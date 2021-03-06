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

use HHPack\Typesafety\Output;
use HHPack\Typesafety\Output\ConsoleOutput;

final class CLIKernel implements Kernel
{

    public function __construct
    (
        private Application $application,
        private Output $output = new ConsoleOutput()
    )
    {
    }

    public async function run(Traversable<string> $argv) : Awaitable<void>
    {
        $result = await $this->application->run($argv);
        $this->terminated($result);
    }

    private function terminated(ApplicationResult $result) : void
    {
        if ($result->isError()) {
            $result->displayError($this->output);
        }
        $exitCode = $result->isOk() ? 0 : -1;
        exit($exitCode);
    }

}
