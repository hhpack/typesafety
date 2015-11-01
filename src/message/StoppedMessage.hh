<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\typesafety\message;

use hhpack\publisher\Message;
use hhpack\typechecker\check\Result;

final class StoppedMessage implements Message
{

    public function __construct(
        private Result $result
    )
    {
    }

}
