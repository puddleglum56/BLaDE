#! /bin/bash -l
export CC=/usr/local/bin/gcc
export CXX=/usr/local/bin/g++

source modules

mkdir build
cd build
/usr/local/cmake-3.24.1-linux-x86_64/bin/cmake -DUNITS=AKMA -DCMAKE_BUILD_TYPE=Release ../src
# cmake -DUNITS=AKMA -DPRECISION=DOUBLE -DCMAKE_BUILD_TYPE=Release ../src

make $1 blade
