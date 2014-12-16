<?hh //partial

namespace typesafety;

use \stdClass;


class Error
{

    private ImmutableMessages $messages;

    public function __construct(Messages $messages)
    {
        $this->messages = new ImmVector($messages);
    }

    public function getMessages() : Iterator<Message>
    {
        return $this->messages->getIterator();
    }

    public static function fromObject(stdClass $error) : Error
    {
        $messages = $error->messages;
        return new Error($messages);
    }

}
