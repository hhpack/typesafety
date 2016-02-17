<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\typesafety
{
    type Path = string;
}

namespace hhpack\typesafety\reporter
{
    type Path = string;
}

namespace hhpack\typesafety
{

    async function main(Traversable<string> $argv) : Awaitable<void>
    {
        $kernel = new CLIKernel(new Application());
        await $kernel->run($argv);
    }

}
