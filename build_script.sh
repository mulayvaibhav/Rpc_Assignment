#!/bin/bash

script_dir="$(dirname "$(realpath "$0")")"

# Output the directory
echo "The script is run from: $script_dir"

mkdir build
cd build
cmake -S ../ -B .
make
mkdir ../bin
mv DreamRpc ../bin