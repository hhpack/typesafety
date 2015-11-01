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

    public async function run(Context $context) : Awaitable<void>
    {
        $context->started();

        $client = new TypeCheckerClient();

        await $client->restartServer();
        $result = await $client->verifyType();

        $context->finish();

        $context->report($result);
        $context->terminated($result);
    }

}
