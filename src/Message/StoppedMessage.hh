<?hh //strict

/**
 * This file is part of hhack/typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Typesafety\Message;

use HHPack\Publisher\Message;
use HHPack\TypeChecker\Check\Result;
use HHPack\TypeChecker\Check\Error;
use Generator;

final class StoppedMessage implements Message
{

    public function __construct(
        private Result $result
    )
    {
    }

    public function isOk() : bool
    {
        return $this->result->isOk();
    }

    public function isError() : bool
    {
        return $this->result->isError();
    }

    public function errors() : KeyedIterator<int, Error>
    {
        foreach ($this->result->errors()->lazy() as $number => $error) {
            yield $number + 1 => $error;
        }
    }

    public function errorCount() : int
    {
        return $this->result->errorCount();
    }

}
