<?hh //strict

namespace hhpack\typesafety;

final class Stdout implements Writable<string>
{

    public function write(string $output) : void
    {
        fwrite(STDOUT, $output);
    }

    public function writeln(string $output) : void
    {
        $this->write($output . PHP_EOL);
    }

}
