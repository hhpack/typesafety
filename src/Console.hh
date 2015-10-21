<?hh //strict

namespace typesafety;

final class Console
{

    public function __construct(
        private Stdout $stdout = new Stdout()
    )
    {
    }

}
