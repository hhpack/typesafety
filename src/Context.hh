<?hh //strict

namespace typesafety;


class Context
{

    public function __construct
    (
        private Arguments $args
    )
    {
    }

    public function getArguments() : Arguments
    {
        return $this->args;
    }

}
