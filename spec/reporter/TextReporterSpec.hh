<?hh //partial

namespace hhpack\typesafety\spec\reporter;

use hhpack\typechecker\check\Result;
use hhpack\typesafety\reporter\TextReporter;
use hhpack\typesafety\message\StoppedMessage;
use hhpack\typesafety\ConsoleOutput;

describe(TextReporter::class, function() {
  beforeEach(function() {
    $content = file_get_contents(__DIR__ . '/../fixtures/failed/output.json');
    $content = str_replace('{$rootDirectory}', realpath(__DIR__ . '/../fixtures/failed') , $content);
    $json = json_decode($content);
    $this->result = Result::fromObject($json);
    $this->reporter = new TextReporter(new ConsoleOutput());
  });
  describe('onStop()', function() {
    it('display type check report', function () {
      $this->reporter->onStop(new StoppedMessage($this->result));
    });
  });
});
