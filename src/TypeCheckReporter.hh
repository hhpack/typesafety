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

use HHPack\Publisher\Message as TypeCheckMessage;
use HHPack\Publisher\Subscribable;
use HHPack\TypeChecker\Check\Result;
use HHPack\Typesafety\Message\StoppedMessage;

interface TypeCheckReporter extends Subscribable<TypeCheckMessage>
{
    public function onStop(StoppedMessage $message) : Awaitable<void>;
}
