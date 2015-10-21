<?hh //strict

namespace typesafety;

interface Writable<T>
{
    public function write(T $output) : void;
    public function writeln(T $output) : void;
}
