# c_nn
Neural Networks library in C++


#### Build everything
```bash
> mkdir build && cd build
> cmake ..
> make

``` 

#### Build cpp
In the cpp folder
```bash
> mkdir build && cd build
> cmake .. DPYTHON_EXECUTABLE="/path/to/python/executable" -DPYTHON_LIBRARY_DIR="/path/to/python/site-packages"
> make
> sudo make install

``` 

#### Run examples in cpp
In build:
```bash
# ./{example_file_name}
> ./main
```

#### Run tests in cpp
In build:
```bash
> cd tests
> ctest
or
> ./tests
```
