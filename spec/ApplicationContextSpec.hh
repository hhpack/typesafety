<?hh //partial

namespace hhpack\typesafety\spec;

use hhpack\typesafety\Arguments;
use hhpack\typesafety\ApplicationContext;

describe(ApplicationContext::class, function() {
  beforeEach(function() {
    $this->context = ApplicationContext::fromArray([
      'script.hh',
      'output.json'
    ]);
  });
  describe('#getArguments', function() {
    it('return Arguments instance', function() {
      expect($this->context->getArguments())->toBeAnInstanceOf(Arguments::class);
    });
  });
});
