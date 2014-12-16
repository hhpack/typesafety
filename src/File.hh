<?hh //strict

namespace typesafety;


class File
{

    public function __construct
    (
        private Path $path,
        private FilePosition $position
    )
    {
    }

}
