<?hh //strict

namespace typesafety;


class Arguments
{

    private ImmVector<string> $argv;

    public function __construct
    (
        Argv $argv
    )
    {
        $this->argv = new ImmVector($argv);
    }

    public function getScriptName() : ScriptName
    {
        return $this->argv->at((int) ArgumentOrder::ScriptName);
    }

    public function getJSONReportFilePath() : Path
    {
        return $this->argv->at((int) ArgumentOrder::JsonReportFilePath);
    }

}
