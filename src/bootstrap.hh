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
    type ScriptName = string;
    type Argv = Traversable<string>;
    type Output = Writable<string>;
}

namespace hhpack\typesafety\reporter
{
    use hhpack\typesafety\Writable;

    type Output = Writable<string>;
}
