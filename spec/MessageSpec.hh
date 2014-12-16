<?hh //partial

use typesafety\Message;
use stdClass;

describe('Message', function() {
    beforeEach(function() {
        $object = new stdClass();
        $object->code = 2055;
        $object->descr = "error message";
        $object->path = "/foo/var/example.hh";
        $object->line = 38;
        $object->end = 26;
        $object->start = 26;

        $this->object = $object;
    });
    describe('#fromObject', function() {
        it('return Message instance', function() {
            $message = Message::fromObject($object);
            expect($message)->toBeAnInstanceOf(Message::class);
        });
    });
});
