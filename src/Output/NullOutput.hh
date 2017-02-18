<?hh //strict

/**
 * This file is part of hhack/typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Typesafety\Output;

use HHPack\Typesafety\Output;
use HHPack\Color\Color;
use HHPack\Color\StyleType;
use HHPack\Color\ForegroundColor;

final class NullOutput implements Output
{

    public function debug(string $format, ...) : void
    {
    }

    public function info(string $format, ...) : void
    {
    }

    public function error(string $format, ...) : void
    {
    }

    public function warn(string $format, ...) : void
    {
    }

    public function fail(string $format, ...) : void
    {
    }

    public function success(string $format, ...) : void
    {
    }

    public function write(string $text) : void
    {
    }

    public function writeln(string $text) : void
    {
    }

}
