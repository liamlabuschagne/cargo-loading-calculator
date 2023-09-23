# Cargo Loading Calculator
The initial requirements for this project can be found here: [Cargo App Code Challenge](https://gist.github.com/0x-a6/3c444b6ec192720c0f9712f5abbbe01e).

## Additional Requirements
After some more communication with John Grant, I also obtained these additional requirements:

* 0 volume is an invalid cargo item
* Cargo volume format is x, y, z and the units is meters
* The key is an arbitrary ID and it has to be a number, a key with string char is invalid
* The trolley is a special space net container that doesn't have a maximum volume
* There is an infinite amount of trolleys
* The output is representing the number of trolleys

## Dependencies
* C++20 standard or above
* CMake >= v3.27.4
* GoogleTest >= v1.14.0 (automatically installed by CMake)

## Usage
### Configuring
```sh
mkdir build
cd build
cmake ..
```
After configuring, you can build, run or test the code as follows:

### Building
To build the application:
```sh
cd build/src
make
```

To build the tests:
```sh
cd build/test
make
```

Once you have successfully built either the application or the tests, you can run them as follows:

### Running
To run the application:
```sh
cd build/src
./CargoLoadingCalculator
```

To run the tests:
```sh
cd build/test
ctest
```

### Cleaning
To clean the project of all generated files:
```sh
rm -rf build
```