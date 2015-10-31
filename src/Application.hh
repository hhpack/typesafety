<?hh //strict

namespace hhpack\typesafety;

final class Application
{

    private TypeCheckerClient $client;

    public function __construct()
    {
        $this->client = new TypeCheckerClient();
    }

    public async function run(Context $context) : Awaitable<void>
    {
        await $this->client->restart();
        $result = await $this->client->check();

        $context->report($result);
        $context->terminated($result);
    }

}
