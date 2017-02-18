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

interface Output extends Writable<string>
{
    public function debug(string $format, ...) : void;
    public function info(string $format, ...) : void;
    public function error(string $format, ...) : void;
    public function warn(string $format, ...) : void;
    public function fail(string $format, ...) : void;
    public function success(string $format, ...) : void;
}
