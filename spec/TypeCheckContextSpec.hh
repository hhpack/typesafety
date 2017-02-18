<?hh //partial

namespace HHPack\Typesafety\Spec;

use HHPack\Typesafety\Arguments;
use HHPack\Typesafety\ArgumentOptions;
use HHPack\Typesafety\TypeCheckContext;

describe(TypeCheckContext::class, function() {
  describe('#isHelp', function() {
    context('when use help option', function() {
      beforeEach(function() {
        $this->context = new TypeCheckContext(
          new Arguments(),
          new ArgumentOptions([ 'help' => true ])
        );
      });
      it('return true', function() {
        expect( $this->context->isHelp() )->toBeTrue();
      });
    });
    context('when not use help option', function() {
      beforeEach(function() {
        $this->context = new TypeCheckContext(
          new Arguments(),
          new ArgumentOptions([ 'help' => false ])
        );
      });
      it('return false', function() {
        expect( $this->context->isHelp() )->toBeFalse();
      });
    });
  });
  describe('#isVersion', function() {
    context('when use version option', function() {
      beforeEach(function() {
        $this->context = new TypeCheckContext(
          new Arguments(),
          new ArgumentOptions([ 'version' => true ])
        );
      });
      it('return true', function() {
        expect( $this->context->isVersion() )->toBeTrue();
      });
    });
    context('when not use version option', function() {
      beforeEach(function() {
        $this->context = new TypeCheckContext(
          new Arguments(),
          new ArgumentOptions([ 'version' => false ])
        );
      });
      it('return false', function() {
        expect( $this->context->isVersion() )->toBeFalse();
      });
    });
  });
});
