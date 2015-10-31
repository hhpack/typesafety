<?hh //strict

namespace hhpack\typesafety;

interface Context
{
    public function getArguments() : Arguments;
    public function report(Result $result) : void;
    public static function fromArray(array<string> $argv) : this;
}
