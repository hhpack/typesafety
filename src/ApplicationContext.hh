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
use hhpack\typesafety\reporter\TextReporter;
use hhpack\typesafety\message\StoppedMessage;
use hhpack\typesafety\output\ConsoleOutput;
use hhpack\typesafety\Output;

final class ApplicationContext implements Context
{

    public function __construct
    (
        private Arguments $args,
        private ArgumentOptions $options,
        private Output $output = new ConsoleOutput()
    )
    {
    }

    public function rootDirectory() : Path
    {
        return $this->args->getRootDirectory();
    }

    public function isHelp() : bool
    {
        return (bool) $this->options->at('help');
    }

    public function isVersion() : bool
    {
        return (bool) $this->options->at('version');
    }

    public function started() : void
    {
        $this->output->info('Type check started.');
    }

    public async function report(Result $result) : Awaitable<void>
    {
        if ($result->isError()) {
            $this->output->write(PHP_EOL);
        }
        $reporter = new TextReporter($this->output);
        await $reporter->onStop(new StoppedMessage($result));
    }

    public function finish() : void
    {
        $this->output->info('Type check finished.');
    }

    public function terminated(Result $result) : void
    {
        $exitCode = $result->isOk() ? 0 : -1;
        exit($exitCode);
    }

}
