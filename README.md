# Ledger C++ Test Library

Test Library that allows to retrieve transactions of addresses

## Dependencies

### Build
For Windows build you will need to install: **_make, libiconv, libintl_**.

### External dependencies:

This projects is based on external modules: Djinni, json11, gyp and optional.
To get those dependencies:

```
git submodule init
git submodule update --remote
```

## Cross-platform interfaces generation

Generation of interfaces for different platforms using Djinni (C++, Objective-C and Java) :

```
make
```

## Binding to node JS

Generate binding (under _build/Release/ledgerapp_nodejs.node_):

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
