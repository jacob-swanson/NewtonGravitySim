#!/bin/bash
# ~/bin/build-polycode

pushd ../

git clone https://github.com/ivansafrin/Polycode.git Polycode
cd Polycode
mkdir -p Dependencies/Build/Debug Dependencies/Build/Release Build/Debug Build/Release Standalone/Build

cd Dependencies/Build/Debug
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../..
make

cd ../Release
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../..
make

cd ../../../Build/Debug
#cmake -G "Unix Makefiles" -DPOLYCODE_BUILD_BINDINGS=ON -DPOLYCODE_BUILD_PLAYER=ON -DCMAKE_BUILD_TYPE=Debug -DPYTHON_EXECUTABLE=/usr/bin/python2 ../..
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DPYTHON_EXECUTABLE=/usr/bin/python2 ../..

make
#make PolycodeLua
make install

cd ../Release
make
#cmake -G "Unix Makefiles" -DPOLYCODE_BUILD_BINDINGS=ON -DPOLYCODE_BUILD_PLAYER=ON -DCMAKE_BUILD_TYPE=Release -DPYTHON_EXECUTABLE=/usr/bin/python2 ../..
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DPYTHON_EXECUTABLE=/usr/bin/python2 ../..

#make PolycodeLua
make install

#cd ../../Standalone/Build
#cmake -G "Unix Makefiles" -DPYTHON_EXECUTABLE=/usr/bin/python2 ..
#make install

popd
echo "Polycode build complete!"
