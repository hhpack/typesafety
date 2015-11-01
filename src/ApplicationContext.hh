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

final class ApplicationContext implements Context
{

    public function __construct
    (
        private Arguments $args,
        private Output $output = new ConsoleOutput()
    )
    {
    }

    public function getArguments() : Arguments
    {
        return $this->args;
    }

    public function started() : void
    {
        $this->output->writeln('Type check started.');
    }

    public function report(Result $result) : void
    {
        $reporter = new TextReporter($this->output);
        $reporter->onStop($result);
    }

    public function finish() : void
    {
        $this->output->writeln('Type check finished.');
    }

    public function terminated(Result $result) : void
    {
        $exitCode = $result->isPassed() ? 0 : -1;
        exit($exitCode);
    }

    public static function fromArray(array<string> $argv) : this
    {
        return new static(
            Arguments::fromArray($argv)
        );
    }

}
