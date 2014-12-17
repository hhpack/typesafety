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

    public static function fromObject(stdClass $errorObject) : Error
    {
        $messages = Vector {};

        foreach ($errorObject->message as $messageObject) {
            $message = Message::fromObject($messageObject);
            $messages->add($message);
        }

        return new Error($messages->getIterator());
    }

}
