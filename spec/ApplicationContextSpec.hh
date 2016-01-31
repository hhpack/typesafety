<?hh //partial

namespace hhpack\typesafety\spec;

use hhpack\typesafety\Arguments;
use hhpack\typesafety\ApplicationContext;

describe(ApplicationContext::class, function() {
  beforeEach(function() {
    $this->context = ApplicationContext::fromItems([ 'script.hh' ]);
  });
  describe('#rootDirectory', function() {
    it('return root directory instance', function() {
      $path = $this->context->rootDirectory();
      expect($path)->toBe((string) getcwd());
    });
  });
});
