# FastPimpl
Implementation of Fast Pimpl idiom.

Pimpl is a C++ programming technique that removes implementation details of a class from its object representation by placing them in a separate class, accessed through an opaque pointer.
This technique is used to construct C++ library interfaces with stable ABI and to reduce compile-time dependencies.

An implementation using a pointer can be found [here](https://en.cppreference.com/w/cpp/language/pimpl).

### Access overhead
In pImpl, each call to a private member function indirects through a pointer. Each access to a public member made by a private member indirects through another pointer.

To avoid performance losses, you can use the FastPimpl helper class.

The interfaces of Fast Pimpl and the regular pointer are almost identical, which will help to easily use it.

## Building

### On linux
* `mkdir build && cd build`
* `cmake ..`
* `make`
* `./test/main_exec` - to run the small demo

### On Windows
* [Open cmake project in Visual Studio](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=vs-2019).


## Project structure

```
├── CMakeLists.txt
├── include
│   └── FastPimpl.h
└── test
    ├── CMakeLists.txt
    ├── Interface.cpp
    ├── Interface.h
    ├── Main.cpp
    └── NativeType.h
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
