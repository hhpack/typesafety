<?hh //strict

namespace hhpack\typesafety;

use hhpack\typechecker\TypeCheckerClient;

final class Application
{

    private TypeCheckerClient $client;

    public function __construct()
    {
        $this->client = new TypeCheckerClient();
    }

    public async function run(Context $context) : Awaitable<void>
    {
        $context->started();

        await $this->client->restartServer();
        $result = await $this->client->verifyType();

        $context->finish();

        $context->report($result);
        $context->terminated($result);
    }

}
