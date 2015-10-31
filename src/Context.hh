<?hh //strict

namespace hhpack\typesafety;


final class Context
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

    public static function fromArray(array<string> $argv) : Context
    {
        return new Context(
            Arguments::fromArray($argv)
        );
    }

}
