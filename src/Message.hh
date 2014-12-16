<?hh //partial

namespace typesafety;

use \stdClass;


class Message
{

    public function __construct
    (
        private int $code,
        private string $description,
        private File $file
    )
    {
    }

    public function getCode() : int
    {
        return $this->code;
    }

    public function getDescription() : string
    {
        return $this->description;
    }

    public function getPath() : Path
    {
        return $this->file->getPath();
    }

    public function getLineNumber() : LineNumber
    {
        return $this->file->getLineNumber();
    }

    public function getStartColumnNumber() : ColumnNumber
    {
        return $this->file->getStartColumnNumber();
    }

    public function getEndColumnNumber() : ColumnNumber
    {
        return $this->file->getEndColumnNumber();
    }

    public static function fromObject(stdClass $message) : Message
    {
        $position = new FilePosition($message->line, $message->start, $message->end);
        $file = new File($message->path, $position);

        return new Message($message->code, $message->descr, $file);
    }

}
