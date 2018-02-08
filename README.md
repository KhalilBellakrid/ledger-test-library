# Ledger C++ Test Library

Test Library that allows to retrieve transactions of addresses

## Dependencies
For Windows build you will need to install: **_make, libiconv, libintl_**.

Get all dependencies from git submodules:
```
git submodule update --recursive --remote
```

## Cross-platform interfaces generation

Generation of interfaces for different platforms using Djinni (C++, iOS and Android) :

```
make
```

## Binding to node JS

Generate binding (under build/Release/ledgerapp_nodejs.node):

```
/bin/bash create_node_binding.sh
```

Build:

```
npm run gypbuild
```

## Todo

To push in repository:

	-Java implementation and Android test app,
	-React bridging and React Native test app.
