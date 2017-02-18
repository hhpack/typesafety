<?hh //strict

/**
 * This file is part of hhack/typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Typesafety;


final class Arguments
{

    private ImmVector<string> $args;

    public function __construct(Traversable<string> $args = [])
    {
        $this->args = new ImmVector($args);
    }

    public function getRootDirectory() : Path
    {
        $directory = $this->args->get(0);

        if ($directory === null) {
            $directory = (string) getcwd();
        }

        return $directory;
    }

    public static function fromItems(Traversable<string> $args) : this
    {
        return new static($args);
    }

}
