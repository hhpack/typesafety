<?hh //partial

use typesafety\Arguments;

describe('Arguments', function() {
    beforeEach(function() {
        $this->args = new Arguments(['script.hh', 'output.json']);
    });
    describe('#getScriptName', function() {
        it('return script name', function() {
            expect($this->args->getScriptName())->toBe('script.hh');
        });
    });
    describe('#getJSONReportFilePath', function() {
        it('return json report file path', function() {
            expect($this->args->getJSONReportFilePath())->toBe('output.json');
        });
    });
});
