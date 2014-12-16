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

    public static function fromObject(stdClass $message) : Message
    {
        $position = new FilePosition($message->line, $message->start, $message->end);
        $file = new File($message->path, $position);

        return new Message($message->code, $message->descr, $file);
    }

}
