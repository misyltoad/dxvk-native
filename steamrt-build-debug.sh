#!/bin/bash

CXX="g++-9 -m32" CC="gcc-9 -m32" meson --buildtype debug build.debug
pushd build.debug
    ninja
popd
