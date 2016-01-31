<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

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

    public function getRootDirectory() : Path
    {
        $directory = $this->argv->get(1);

        if ($directory === null) {
            $directory = (string) getcwd();
        }

        return $directory;
    }

    public static function fromItems(Argv $argv) : this
    {
        return new static($argv);
    }

}
