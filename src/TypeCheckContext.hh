<?hh //strict

/**
 * This file is part of hhack/typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Typesafety;

use HHPack\TypeChecker\Check\Result;
use HHPack\TypeChecker\TypeCheckerClient;
use HHPack\Typesafety\Message\StoppedMessage;
use HHPack\Typesafety\Output\ConsoleOutput;
use HHPack\Typesafety\Output;
use HHPack\Typesafety\Reporter\ReporterLoader;
use HHPack\Typesafety\Reporter\TextReporter;

final class TypeCheckContext implements ApplicationContext
{

    public function __construct
    (
        private Arguments $args,
        private ArgumentOptions $options,
        private Output $output = new ConsoleOutput()
    )
    {
    }

    public function isHelp() : bool
    {
        return (bool) $this->options->at('help');
    }

    public function isVersion() : bool
    {
        return (bool) $this->options->at('version');
    }

    private function loadReporter() : TypeCheckReporter
    {
        $name = (string) $this->options->at('reporter');

        $loader = new ReporterLoader();
        return $loader->load($name, [ $this->output ]);
    }

    public async function execute() : Awaitable<void>
    {
        $directory = $this->args->getRootDirectory();
        $client = new TypeCheckerClient($directory);

        $this->output->info('type check started');
        await $client->restart();
        $result = await $client->check();
        $this->output->info('type check finished');

        await $this->report($result);
    }

    private async function report(Result $result) : Awaitable<void>
    {
        if ($result->isError()) {
            $this->output->write(PHP_EOL);
        }

        $reporter = $this->loadReporter();
        await $reporter->onStop(new StoppedMessage($result));
    }

}
