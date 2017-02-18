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

use HHPack\TypeChecker\Check\Result;

interface ApplicationContext
{
    public function isHelp() : bool;
    public function isVersion() : bool;
    public function execute() : Awaitable<void>;
}
