<?hh //strict

namespace typesafety;

final class StdOut
{

    public function write(string $text) : void
    {
        fwrite(STDOUT, $text);
    }

    public function writeln(string $text) : void
    {
        $this->write($text . PHP_EOL);
    }

}
