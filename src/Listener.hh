<?hh //strict

namespace hhpack\typesafety;


interface Listener
{
    public function onStop(Result $result) : void;
}
