# Cargo Loading Calculator
The inital requirements for this project can be found here: [Cargo App Code Challenge](https://gist.github.com/0x-a6/3c444b6ec192720c0f9712f5abbbe01e).

## Additional Requirements
After some more communication with John Grant, I also obtained these additional requirements:

1. 0 volume is an invalid cargo item
1. cargo volume format is x, y, z and the units is meters
1. the key is an arbitrary ID and it has to be a number, a key with string char is invalid
1. the trolley is a special space net container that doesn't have a maximum volume
1. there is an infinite amount of trolleys
1. see 5, no you can safely assume infinite trolleys
1. yes the output is representing the number of trolleys

## Language and Building
This project will be developed in C++20 which is the latest stable version and can be compiled using the make command:

### Compiling
```sh
make
```

### Running
```sh
./clc
```

### Clean Build Directory
```sh
make clean
```

