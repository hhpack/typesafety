<?hh //partial

namespace hhpack\typesafety\spec;

use hhpack\typesafety\Arguments;

describe(Arguments::class, function() {
  beforeEach(function() {
    $this->args = Arguments::fromArray([ 'script.hh', 'output.json']);
  });
  describe('#getScriptName', function() {
    it('return script name', function() {
      expect($this->args->getScriptName())->toBe('script.hh');
    });
  });
});
