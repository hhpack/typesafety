<?hh //strict

namespace hhpack\typesafety;

use hhpack\typechecker\check\Result;

interface Listener
{
    public function onStop(Result $result) : void;
}
