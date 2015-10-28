<?hh //strict

namespace hhpack\typesafety;

interface Client
{
    public function check() : Result;
}
