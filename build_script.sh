#!/bin/bash

script_dir="$(dirname "$(realpath "$0")")"

# Output the directory
echo "The script is run from: $script_dir"

rm -rf build
mkdir build
cd build
cmake -S ../ -B .
make
rm -rf ../bin
mkdir ../bin
mv DreamRpc ../bin