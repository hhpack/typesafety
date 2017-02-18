<?hh //partial

namespace HHPack\Typesafety\Spec\Reporter;

use HHPack\TypeChecker\Check\Result;
use HHPack\TypeChecker\Check\TypeCheckReportDecoder;
use HHPack\Typesafety\Reporter\TextReporter;
use HHPack\Typesafety\Message\StoppedMessage;
use HHPack\Typesafety\Output\ConsoleOutput;

describe(TextReporter::class, function() {
  beforeEach(function() {
    $content = file_get_contents(__DIR__ . '/../fixtures/failed/output.json');
    $content = str_replace('{$rootDirectory}', realpath(__DIR__ . '/../fixtures/failed') , $content);

    $decoder = new TypeCheckReportDecoder();
    $this->result = $decoder->decode($content);

    $this->reporter = new TextReporter(new ConsoleOutput());
  });
  describe('onStop()', function() {
    it('display type check report', async function () {
      await $this->reporter->onStop(new StoppedMessage($this->result));
    });
  });
});
