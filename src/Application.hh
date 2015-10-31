<?hh //strict

namespace hhpack\typesafety;


final class Application
{

    private TypeCheckerClient $client;

    public function __construct
    (
        private TextReporter $reporter
    )
    {
        $this->client = new TypeCheckerClient();
    }

    public async function run(Context $context) : Awaitable<void>
    {
        await $this->client->restart();
        $result = await $this->client->check();
        $this->reporter->onStop($result);
    }

}
