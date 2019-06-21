# Basic C++ CMake template for a shared lib

## Project setup

### Dependencies

* Python >=3.5

### Bootstrap

```bash
python3 bootstrap.py
```

## Usage

To generate Makefile:

```bash
mkdir build/
cd build/
cmake ..
```

To build library:

```bash
make
ls -l lib/
```

To run tests:

```bash
make test
```

## License

This project is licensed under the MIT license. A copy of this license is provided [in this repository](LICENSE).
