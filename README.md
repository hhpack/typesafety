typesafety
========================================

[![Latest Stable Version](https://poser.pugx.org/hhpack/typesafety/version)](https://packagist.org/packages/hhpack/typesafety)
[![Build Status](https://travis-ci.org/hhpack/typesafety.svg?branch=master)](https://travis-ci.org/hhpack/typesafety)
[![Dependency Status](https://www.versioneye.com/user/projects/562cbfeb36d0ab001900118e/badge.svg?style=flat)](https://www.versioneye.com/user/projects/562cbfeb36d0ab001900118e)
[![License](https://poser.pugx.org/hhpack/typesafety/license)](https://packagist.org/packages/hhpack/typesafety)

![ScreenShot](https://raw.githubusercontent.com/hhpack/typesafety/master/screen-shot.png)

Basic usage
----------------------------------------

You only need to specify the directory where you want to check the type.

	vendor/bin/typesafety [RootDirectory]

composer.json
----------------------------------------

By adding a set to composer.json, it will be able to easily run.

```json
{
    "scripts": {
        "check": "vendor/bin/typesafety"
    }
}
```

You can run the typecheck with the following command.

	composer check


Run the test
------------------------------------------------

You can run the test with the following command.

	composer install
	composer test
