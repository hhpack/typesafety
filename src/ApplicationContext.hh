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
use hhpack\getopt as cli;
use hhpack\getopt\app\ApplicationSpec;

final class ApplicationContext implements Context
{

    const VERSION = '0.5.0';

    private ApplicationSpec $spec;
    private Arguments $args;
    private ArgumentOptions $options;

    public function __construct
    (
        Argv $args,
        private Output $output = new ConsoleOutput()
    )
    {
        $spec = cli\app('typesafety');
        $spec->version(static::VERSION)
            ->options([
                cli\bool_option('help', '-h|--help', false, 'display help message'),
                cli\bool_option('version', '-v|--version', false, 'display version')
            ]);
        $this->spec = $spec;

        $result = $this->spec->parse($args);
        $this->args = Arguments::fromItems($result->arguments());
        $this->options = ArgumentOptions::fromItems($result->options());
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

    public function displayHelp() : void
    {
        $this->spec->displayHelp();
    }

    public function displayVersion() : void
    {
        $this->spec->displayVersion();
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

    public static function fromItems(Argv $argv) : this
    {
        return new static($argv);
    }

}
