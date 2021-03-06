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

final class ConsoleOutput implements Output
{

    public function __construct(
        private Stdout $stdout = new Stdout()
    )
    {
    }

    public function debug(string $format, ...) : void
    {
        $formatter = Color::fromDefault();
        $message = call_user_func_array(inst_meth($formatter, 'format'), func_get_args());

        $this->stdout->writeln($message);
    }

    public function info(string $format, ...) : void
    {
        $formatter = Color::fromColor(ForegroundColor::Cyan);
        $message = call_user_func_array(inst_meth($formatter, 'format'), func_get_args());

        $this->stdout->writeln($message);
    }

    public function error(string $format, ...) : void
    {
        $formatter = Color::fromColor(ForegroundColor::Red)
            ->addStyle(StyleType::Bold);

        $message = call_user_func_array(inst_meth($formatter, 'format'), func_get_args());

        $this->stdout->writeln($message);
    }

    public function warn(string $format, ...) : void
    {
        $formatter = Color::fromColor(ForegroundColor::Yellow)
            ->addStyle(StyleType::Bold);

        $message = call_user_func_array(inst_meth($formatter, 'format'), func_get_args());

        $this->stdout->writeln($message);
    }

    public function fail(string $format, ...) : void
    {
        call_user_func_array(inst_meth($this, 'error'), func_get_args());
    }

    public function success(string $format, ...) : void
    {
        $formatter = Color::fromColor(ForegroundColor::Green);
        $message = call_user_func_array(inst_meth($formatter, 'format'), func_get_args());

        $this->stdout->writeln($message);
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
