#!/bin/bash

make distclean
echo "Generating the optimized binary"
./configure --enable-optimize --prefix=$(pwd)/src
make && make install

make distclean
echo "Generating the Unoptimized binary"
./configure --program-suffix=Unoptimized --prefix=$(pwd)/src
make && make install

mv $(pwd)/src/bin/* $(pwd)/src
rmdir $(pwd)/src/bin

echo "Aarohi executables successfully generated"
