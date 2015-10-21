<?hh //strict

namespace typesafety;


final class Context implements Writable<string>
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

    public function write(string $text) : void
    {
        $this->console->write($text);
    }

    public function writeln(string $text) : void
    {
        $this->console->writeln($text);
    }

}
