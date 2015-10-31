<?hh //strict

namespace hhpack\typesafety;

final class ConsoleOutput implements Writable<string>
{

    public function __construct(
        private Stdout $stdout = new Stdout()
    )
    {
    }

    public function write(string $text) : void
    {
        $this->stdout->write($text);
    }

    public function writeln(string $text) : void
    {
        $this->stdout->writeln($text);
    }

}
