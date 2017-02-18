<?hh //strict

/**
 * This file is part of hhack/typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Typesafety
{
    type Path = string;
}

namespace HHPack\Typesafety\Reporter
{
    type Path = string;
}

namespace HHPack\Typesafety
{

    async function main(Traversable<string> $argv) : Awaitable<void>
    {
        $kernel = new CLIKernel(new Typesafety());
        await $kernel->run($argv);
    }

}
