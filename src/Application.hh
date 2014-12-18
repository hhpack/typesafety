<?hh //partial

namespace typesafety;

use \RuntimeException;


final class Application
{

    public function __construct
    (
        private TextReporter $reporter
    )
    {
    }

    public function run(array $args) : void
    {
        $relativeJsonReportFile = $args[1];
        $jsonReportFile = getcwd() . '/' . $relativeJsonReportFile;

        if (file_exists($jsonReportFile) === false) {
            throw new RuntimeException('JSON report file not found.');
        }

        $jsonObject = json_decode(file_get_contents($jsonReportFile));

        $result = Result::fromObject($jsonObject);
        $this->reporter->onStop($result);
    }

}
