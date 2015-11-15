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
use hhpack\typesafety\Reporter;
use hhpack\typesafety\Output;

final class TextReporter implements Reporter
{

    private Set<Path> $files = Set {};

    public function __construct
    (
        private Output $output
    )
    {
    }

    public function onStop(StoppedMessage $message) : void
    {
        $this->displayErrors($message);
        $this->displayStatus($message);
    }

    private function displayStatus(StoppedMessage $message) : void
    {
        if ($message->isPassed()) {
            $this->output->success('Type check passed.');
        } else {
            $this->output->fail('Type check failed.');
        }
    }

    private function displayErrors(StoppedMessage $message) : void
    {
        foreach ($message->errors() as $error) {
            $this->displayError($error);
        }
    }

    private function displayError(Error $error) : void
    {
        $messages = $error->getMessages();

        foreach ($messages as $message) {
            $this->displayMessage($message);
        }
    }

    private function displayMessage(Message $message) : void
    {
        $this->displayHeader($message);
        $this->displayDescription($message);
        $this->displayErrorMessage($message);
    }

    private function displayHeader(Message $message) : void
    {
        $file = $message->getPath();

        if ($this->files->contains($file) === false) {
            $this->files->add($file);
            $this->output->info('%s%s', $file, PHP_EOL);
        };
    }

    private function displayDescription(Message $message) : void
    {
        $description = $message->getDescription();
        $texts = explode(PHP_EOL, $description);

        foreach ($texts as $text) {
            $this->output->error('  %s', $text);
        }
        $this->output->log('');
    }

    private function displayErrorMessage(Message $message) : void
    {
        $startAt = $message->getStartColumnNumber();
        $endAt = $message->getEndColumnNumber();
        $lineNumber = $message->getLineNumber();

        $stringText = str_pad("^", $startAt, " ", STR_PAD_LEFT);
        $length = $startAt + ($endAt - $startAt);
        $stringText = str_pad($stringText, $length, "^");

        $paddingSpace = str_repeat(' ', strlen((string) $lineNumber) + 1);

        $this->output->error('  %d: %s', $lineNumber, $message->getLineCode());
        $this->output->error('  %s %s', $paddingSpace, $stringText);
    }

}
