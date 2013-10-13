NewtonGravitySim
================

An n-body Newtonian gravity simulator
### Dependencies ###
* [GMP](http://gmplib.org/)
* [Qt](http://qt-project.org/)
* [Polycode](http://polycode.org/)

### Building Instructions ###
#### Build Polycode ####
You can either use the provided script or build Polycode yourself by following the directions on http://polycode.org/.
```
apt-get install git
apt-get install cmake
apt-get install libsdl-dev
cd NewtonGravitySim
./buildPolycode.sh
```
#### Build and Run NewtonGravitySim ####
```
apt-get install qt5-default
apt-get install libgmp-dev
apt-get install libopenal1
cd NewtonGravitySim
qmake
make
./NewtonGravitySim
```
### Controls ###
* Mousewheel up - zoom in
* Mousewheel down - zoom out
* Left & right arrow - change camera target
* Hold right click and move mouse to move camera around target
