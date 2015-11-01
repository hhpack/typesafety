<?hh //strict

namespace hhpack\typesafety;

use hhpack\typechecker\check\Result;

interface Context
{
    public function getArguments() : Arguments;
    public function started() : void;
    public function report(Result $result) : void;
    public function finish() : void;
    public function terminated(Result $result) : void;
    public static function fromArray(array<string> $argv) : this;
}
