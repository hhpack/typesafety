<?hh //strict

namespace hhpack\typesafety;

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

    public function getOutput() : Output
    {
        return $this->output;
    }

    public function report(Result $result) : void
    {
        $reporter = new TextReporter($this->output);
        $reporter->onStop($result);
    }

    public static function fromArray(array<string> $argv) : this
    {
        return new static(
            Arguments::fromArray($argv)
        );
    }

}
