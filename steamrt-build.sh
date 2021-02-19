#!/bin/bash

CXX="/opt/gcc-9.2/bin/g++-9.2 -m32" CC="/opt/gcc-9.2/bin/gcc-9.2 -m32" meson --buildtype release build
pushd build
    ninja
popd
