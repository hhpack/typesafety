<?hh //strict

namespace typesafety;

class Result
{

    public function __construct
    (
        private bool $passed,
        private Version $version,
        private Errors $errors
    )
    {
    }

}
