<?hh //strict

namespace hhpack\typesafety;


final class Arguments
{

    private ImmVector<string> $argv;

    public function __construct(
        Argv $argv
    )
    {
        $this->argv = new ImmVector($argv);
    }

    public function getScriptName() : ScriptName
    {
        return $this->argv->at(0);
    }

    public static function fromArray(array<string> $argv) : Arguments
    {
        return new Arguments($argv);
    }

}
