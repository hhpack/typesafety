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

interface Output extends Writable<string>
{
    public function log(string $format, ...) : void;
    public function info(string $format, ...) : void;
    public function error(string $format, ...) : void;
    public function warn(string $format, ...) : void;
    public function fail(string $format, ...) : void;
    public function success(string $format, ...) : void;
}
