<?hh //strict

namespace typesafety;

class FilePosition
{

    public function __construct
    (
        private LineNumber $lineNumber,
        private ColumnNumber $startColumnNumber,
        private ColumnNumber $endColumnNumber
    )
    {
    }

}
