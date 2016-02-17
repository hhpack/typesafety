<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\typesafety;

use hhpack\typechecker\check\Result;
use hhpack\typechecker\TypeCheckerClient;
use hhpack\typesafety\reporter\TextReporter;
use hhpack\typesafety\message\StoppedMessage;
use hhpack\typesafety\output\ConsoleOutput;
use hhpack\typesafety\Output;
use hhpack\typesafety\Reporter;
use hhpack\typesafety\reporter\ReporterLoader;

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

    private function loadReporter() : Reporter
    {
        $name = (string) $this->options->at('reporter');

        $loader = new ReporterLoader();
        return $loader->load($name, [ $this->output ]);
    }

    public async function execute() : Awaitable<void>
    {
        $directory = $this->args->getRootDirectory();
        $client = new TypeCheckerClient($directory);

        await $client->restart();
        $result = await $client->check();

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
