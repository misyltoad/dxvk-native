# include/native/directx

Put your DirectX headers in here. These cannot be redisted due to current licensing reasons.

Example of how to get them:
```sh
brew install mingw-w64
# ...installing
cd ~/Cellar/mingw-w64/7.0.0_2/toolchain-x86_64/x86_64-w64-mingw32/include/
cp d3d*.h dxgi*.h ~/git/github/Joshua-Ashton/dxvk-native/include/native/directx/
```