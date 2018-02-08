# Ledger C++ Test Library

Test Library that allows to retrieve transactions of addresses

##Clone projects with its submodules

This projects is based on external modules:

```
git clone --recurse-submodules
```

## Dependencies

###Build
For Windows build you will need to install: **_make, libiconv, libintl_**.

###External dependencies:
If you didn't clone project using **--recurse-submodules**, you should provide following dependencies in _deps_ directory: Djinni, json11, gyp and optional

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
