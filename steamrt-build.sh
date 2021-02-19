#!/bin/bash

CXX="g++-9 -m32" CC="gcc-9 -m32" meson --buildtype release build
pushd build
    ninja
popd
