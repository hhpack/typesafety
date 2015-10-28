<?hh //strict

namespace hhpack\typesafety;


final class TextReporter implements Listener
{

    public function onStop(Result $result) : void
    {
        $this->displayStatus($result);
        $this->displayErrors($result);
    }

    private function displayStatus(Result $result) : void
    {
        if ($result->isPassed()) {
            echo "Typing check passed", PHP_EOL;
        } else {
            echo "Typing check failed", PHP_EOL;
        }
        echo PHP_EOL;
    }

    private function displayErrors(Result $result) : void
    {
        $errors = $result->getErrors();

        foreach ($errors as $error) {
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
        echo $message->getPath(), PHP_EOL, PHP_EOL;

        $description = $message->getDescription();
        $texts = explode(PHP_EOL, $description);

        foreach ($texts as $text) {
            echo "  ", $text, PHP_EOL;
        }
        echo PHP_EOL;

        $lineNumber = $message->getLineNumber();
        $startAt = $message->getStartColumnNumber();
        $endAt = $message->getEndColumnNumber();

        $content = file_get_contents($message->getPath());
        $lines = explode(PHP_EOL, $content);

        $record = $lines[$lineNumber - 1];

        $stringText = str_pad("^", $startAt, " ", STR_PAD_LEFT);
        $length = $startAt + ($endAt - $startAt);
        $stringText = str_pad($stringText, $length, "^");

        echo "  ", $record, PHP_EOL;
        echo "  ", $stringText, PHP_EOL;
    }

}
