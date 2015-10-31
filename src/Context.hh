<?hh //strict

namespace hhpack\typesafety;


interface Context
{
    public function getArguments() : Arguments;
    public function getConsoleOutput() : Console;
    public static function fromArray(array<string> $argv) : this;
}
