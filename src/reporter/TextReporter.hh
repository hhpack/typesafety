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

    public function __construct
    (
        private Output $output
    )
    {
    }

    public function onStop(StoppedMessage $message) : void
    {
        $this->displayStatus($message);
        $this->displayErrors($message);
    }

    private function displayStatus(StoppedMessage $message) : void
    {
        if ($message->isPassed()) {
            $this->output->write('Type check passed.');
        } else {
            $this->output->writeln('Type check failed.');
        }
        $this->output->writeln('');
    }

    private function displayErrors(StoppedMessage $message) : void
    {
//        $errors = $result->getErrors();

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
        $this->output->writeln($message->getPath() . PHP_EOL);

        $description = $message->getDescription();
        $texts = explode(PHP_EOL, $description);

        foreach ($texts as $text) {
            $this->output->writeln('' . $text);
        }
        $this->output->writeln('');

        $lineNumber = $message->getLineNumber();
        $startAt = $message->getStartColumnNumber();
        $endAt = $message->getEndColumnNumber();

        $content = file_get_contents($message->getPath());
        $lines = explode(PHP_EOL, $content);

        $record = $lines[$lineNumber - 1];

        $stringText = str_pad("^", $startAt, " ", STR_PAD_LEFT);
        $length = $startAt + ($endAt - $startAt);
        $stringText = str_pad($stringText, $length, "^");

        $this->output->writeln('  ' . $record);
        $this->output->writeln('  ' . $stringText);
    }

}
