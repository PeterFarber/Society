#!/bin/bash
config=$1

if [ $config == "-r" ]; then
    ./build/release/SandboxApp
else
    ./build/debug/SandboxAppd
fi  