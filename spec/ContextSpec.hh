<?hh //partial

use typesafety\Arguments;
use typesafety\Context;

describe('Context', function() {
    beforeEach(function() {
        $this->context = new Context(new Arguments([
            'script.hh',
            'output.json'
        ]));
    });
    describe('#getArguments', function() {
        it('return Arguments instance', function() {
            expect($this->context->getArguments())->toBeAnInstanceOf(Arguments::class);
        });
    });
});
