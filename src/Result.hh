<?hh //partial

namespace typesafety;

class Result
{

    private ImmutableErrors $errors;

    public function __construct
    (
        private bool $passed,
        private Version $version,
        Errors $errors
    )
    {
        $this->errors = new ImmVector($errors);
    }

    public function isPassed() : bool
    {
        return $this->passed;
    }

    public function getVersion() : Version
    {
        return $this->version;
    }

    public function getErrors() : Iterator<Error>
    {
        return $this->errors->getIterator();
    }

    public static function fromObject(stdClass $result) : Result
    {
        return new Result(
            $result->passed,
            $result->version,
            $result->errors
        );
    }

}
