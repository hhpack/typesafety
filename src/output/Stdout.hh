<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\typesafety\output;

use hhpack\typesafety\Writable;

final class Stdout implements Writable<string>
{

    public function write(string $output) : void
    {
        fwrite(STDOUT, $output);
    }

    public function writeln(string $output) : void
    {
        $this->write($output . PHP_EOL);
    }

}
