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

final class ConsoleOutput implements Writable<string>
{

    public function __construct(
        private Stdout $stdout = new Stdout()
    )
    {
    }

    public function write(string $text) : void
    {
        $this->stdout->write($text);
    }

    public function writeln(string $text) : void
    {
        $this->stdout->writeln($text);
    }

}
