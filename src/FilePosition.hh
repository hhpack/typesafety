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

    public function getLineNumber() : LineNumber
    {
        return $this->lineNumber;
    }

    public function getStartColumnNumber() : ColumnNumber
    {
        return $this->startColumnNumber;
    }

    public function getEndColumnNumber() : ColumnNumber
    {
        return $this->endColumnNumber;
    }

}
