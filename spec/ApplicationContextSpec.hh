<?hh //partial

namespace hhpack\typesafety\spec;

use hhpack\typesafety\Arguments;
use hhpack\typesafety\ApplicationContext;

describe(ApplicationContext::class, function() {
  beforeEach(function() {
    $this->context = ApplicationContext::fromArray([ 'script.hh' ]);
  });
  describe('#getArguments', function() {
    it('return Arguments instance', function() {
      $args = $this->context->getArguments();
      expect($args->getScriptName())->toBe('script.hh');
      expect($args->getRootDirectory())->toBe((string) getcwd());
    });
  });
});
