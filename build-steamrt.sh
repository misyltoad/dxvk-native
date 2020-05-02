#!/bin/bash

set -e

pushd `dirname $0`
  if [ -f /.dockerenv ]; then
    # If we are in a docker container then build...
    export CC=/opt/gcc-9.2/bin/gcc-9.2
    export CXX=/opt/gcc-9.2/bin/g++-9.2

    rm -rf build.native

    meson --buildtype release \
          --strip             \
          build.native

    pushd build.native
      ninja
    popd
  else
    # Launcher our docker container to build...
    sudo docker run -it --rm --name dxvk-steamrt-instance -v $(pwd):/dxvk dxvk-steamrt /dxvk/build-steamrt.sh
  fi
popd
