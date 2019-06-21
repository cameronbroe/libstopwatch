#!/bin/sh
python3 ./bootstrap.py
mkdir -p build/
cd build/
cmake ..
make clean
make
make test
