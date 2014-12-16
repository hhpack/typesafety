<?hh //strict

namespace typesafety;


interface Listener
{
    public function onStop(Result $result) : void;
}
