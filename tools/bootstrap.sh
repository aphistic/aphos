#!/bin/bash

# Bootstraps a build environment for the given target

BINUTILS_V="2.25"

TOOLS_DIR=$(cd $(dirname $0); pwd -P)
TARGET=$1
PREFIX=$TOOLS_DIR/$TARGET

cd $TOOLS_DIR

if [ ! -d "tmp" ]; then
	mkdir tmp
fi
cd tmp

echo "Downloading binutils"
curl -z binutils-${BINUTILS_V}.tar.bz2 -O http://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_V}.tar.bz2

tar xf binutils-${BINUTILS_V}.tar.bz2
cd binutils-${BINUTILS_V}

./configure --target=$TARGET --prefix=$PREFIX/binutils
make all
make install

cd $TOOLS_DIR
git clone https://github.com/rust-lang/rust.git rust

rm -rf tmp

