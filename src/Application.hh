<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

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
