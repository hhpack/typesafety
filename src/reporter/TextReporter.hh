<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\typesafety\reporter;

use hhpack\typechecker\check\Result;
use hhpack\typechecker\check\Error;
use hhpack\typechecker\check\Message;
use hhpack\publisher\Message as TypeCheckMessage;
use hhpack\publisher\Subscribable;
use hhpack\typesafety\message\StoppedMessage;
use hhpack\typesafety\TypeCheckReporter;
use hhpack\typesafety\Output;

final class TextReporter implements TypeCheckReporter
{

    private (function(string, ...):void) $errorPrinter;

    public function __construct
    (
        private Output $output
    )
    {
        $this->errorPrinter = inst_meth($this->output, 'error');
    }

    public async function onStop(StoppedMessage $message) : Awaitable<void>
    {
        $this->displayErrors($message);
        $this->displayStatus($message);
    }

    private function displayStatus(StoppedMessage $message) : void
    {
        if ($message->isOk()) {
            $this->output->success('type check passed.');
        } else {
            $this->output->fail("type checker found %d errors.", $message->errorCount());
        }
    }

    private function displayErrors(StoppedMessage $message) : void
    {
        foreach ($message->errors() as $errorNumber => $error) {
            $this->displayError($errorNumber, $error);
        }
    }

    private function displayError(int $errorNumber, Error $error) : void
    {
        foreach ($error->messages()->lazy() as $number => $message) {
            if ($number === 0) {
                $this->errorPrinter = inst_meth($this->output, 'error');
                $this->display('Error: %d - %s%s', $errorNumber, $message->path(), PHP_EOL);
            } else {
                $this->errorPrinter = inst_meth($this->output, 'info');
            }
            $this->displayMessage($message);
        }
    }

    private function displayMessage(Message $message) : void
    {
        $this->displayDescription($message);
        $this->displayErrorMessage($message);
    }

    private function displayDescription(Message $message) : void
    {
        $description = $message->description();
        $texts = explode(PHP_EOL, $description);

        foreach ($texts as $text) {
            $this->display('  %s', $text);
        }
        $this->output->write("\n");
    }

    private function displayErrorMessage(Message $message) : void
    {
        $startAt = $message->startColumnNumber();
        $endAt = $message->endColumnNumber();
        $lineNumber = $message->lineNumber();

        $stringText = str_pad("^", $startAt, " ", STR_PAD_LEFT);
        $length = $startAt + ($endAt - $startAt);
        $stringText = str_pad($stringText, $length, "^");

        $paddingSpace = str_repeat(' ', strlen((string) $lineNumber) + 1);

        $this->display('    %d: %s', $lineNumber, $message->lineCode());
        $this->display('    %s %s%s', $paddingSpace, $stringText, PHP_EOL);
    }

    private function display(string $format, ...) : void
    {
        $args = Vector { $format };
        $args->addAll(func_get_args());
        call_user_func_array($this->errorPrinter, $args->toValuesArray());
    }

}
