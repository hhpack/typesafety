<?hh //partial

use typesafety\Error;
use stdClass;

describe('Error', function() {
    beforeEach(function() {
        $message = new stdClass();
        $message->code = 2055;
        $message->descr = "error message";
        $message->path = "/foo/var/example.hh";
        $message->line = 38;
        $message->end = 26;
        $message->start = 26;

        $errorObject = new stdClass();
        $errorObject->messages = [
            $message
        ];

        $this->errorObject = $errorObject;
        $this->error = Error::fromObject($errorObject);
    });
    describe('#getMessages', function() {
        it('return Iterator<Message> instance', function() {
            expect($this->error->getMessages())->toBeAnInstanceOf(Iterator::class);
        });
    });
});
