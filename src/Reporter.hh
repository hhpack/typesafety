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

use hhpack\typechecker\check\Result;
use hhpack\publisher\Message as TypeCheckMessage;
use hhpack\typesafety\message\StoppedMessage;
use hhpack\publisher\Subscribable;

interface Reporter extends Subscribable<TypeCheckMessage>
{
    public function onStop(StoppedMessage $message) : void;
}
