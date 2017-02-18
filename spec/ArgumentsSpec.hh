<?hh //partial

namespace HHPack\Typesafety\Spec;

use HHPack\Typesafety\Arguments;

describe(Arguments::class, function() {
  describe('#getRootDirectory', function() {
    context('when not specify a root directory', function () {
      beforeEach(function() {
        $this->args = Arguments::fromItems([]);
      });
      it('returns root directory path', function() {
        expect($this->args->getRootDirectory())->toBe((string) getcwd());
      });
    });
    context('when specify a root directory', function () {
      beforeEach(function() {
        $this->args = Arguments::fromItems([ __DIR__ ]);
      });
      it('returns root directory path', function() {
        expect($this->args->getRootDirectory())->toBe(__DIR__);
      });
    });
  });
});
