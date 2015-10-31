<?hh //strict

namespace hhpack\typesafety;

final class ApplicationContext implements Context
{

    public function __construct
    (
        private Arguments $args,
        private Console $console = new Console()
    )
    {
    }

    public function getArguments() : Arguments
    {
        return $this->args;
    }

    public function getConsoleOutput() : Console
    {
        return $this->console;
    }

    public static function fromArray(array<string> $argv) : this
    {
        return new static(
            Arguments::fromArray($argv)
        );
    }

}
