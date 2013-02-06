#!/bin/bash

export PREFIX=$HOME/devroot/usr

export SCRIPT_DIR=`dirname $0`;
export CMAKE_PREFIX_PATH=$PREFIX:$CMAKE_PREFIX_PATH
export PKG_CONFIG_PATH=$PREFIX/lib/pkgconfig/:$PKG_CONFIG_PATH
cmake \
    -G "Eclipse CDT4 - Unix Makefiles" \
    -DECLIPSE_CDT4_GENERATE_SOURCE_PROJECT=TRUE \
    -DCMAKE_INSTALL_PREFIX=$PREFIX $SCRIPT_DIR \
    -DCMAKE_PREFIX_PATH="$CMAKE_PREFIX_PATH" \
    -DCMAKE_MODULE_PATH="$PREFIX/usr/share/cmake-2.8/Modules" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_ECLIPSE_MAKE_ARGUMENTS="-j6"

