<?hh //partial

use typesafety\Result;
use typesafety\TextReporter;

describe(TextReporter::class, function() {
  beforeEach(function() {
    $content = file_get_contents(__DIR__ . '/fixtures/failed/output.json');
    $content = str_replace('{$rootDirectory}', realpath(__DIR__ . '/../') , $content);
    $json = json_decode($content);
    $this->result = Result::fromObject($json);
    $this->reporter = new TextReporter();
  });
  describe('onStop()', function() {
    it('display type check report', function () {
      $this->reporter->onStop($this->result);
    });
  });
});
