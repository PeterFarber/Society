#!/bin/bash
$config=$1

BUILD_DIR="./out/build"
INSTALL_DIR="./out/install"

if [ $config == "-r" ]; then
    cmake --install $BUILD_DIR/release --prefix $INSTALL_DIR/release --config Release
else
    cmake --install $BUILD_DIR/debug --prefix $INSTALL_DIR/debug --config Debug
fi


chmod -R 777 $INSTALL_DIR