<?hh //partial

namespace hhpack\typesafety\spec;

use hhpack\typesafety\Arguments;

describe(Arguments::class, function() {
  describe('#getScriptName', function() {
    beforeEach(function() {
      $this->args = Arguments::fromArray([ 'script.hh' ]);
    });
    it('returns script name', function() {
      expect($this->args->getScriptName())->toBe('script.hh');
    });
  });
  describe('#getRootDirectory', function() {
    context('when not specify a root directory', function () {
      beforeEach(function() {
        $this->args = Arguments::fromArray([ 'script.hh' ]);
      });
      it('returns root directory path', function() {
        expect($this->args->getRootDirectory())->toBe((string) getcwd());
      });
    });
    context('when specify a root directory', function () {
      beforeEach(function() {
        $this->args = Arguments::fromArray([ 'script.hh', __DIR__ ]);
      });
      it('returns root directory path', function() {
        expect($this->args->getRootDirectory())->toBe(__DIR__);
      });
    });
  });
});
