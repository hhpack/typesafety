<?hh //strict

namespace typesafety;

use stdClass;

interface Node<T>
{
    public static function fromObject(stdClass $object) : T;
}
