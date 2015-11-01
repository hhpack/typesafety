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

interface Context
{
    public function getArguments() : Arguments;
    public function started() : void;
    public function report(Result $result) : void;
    public function finish() : void;
    public function terminated(Result $result) : void;
    public static function fromArray(array<string> $argv) : this;
}
