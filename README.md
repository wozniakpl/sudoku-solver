# Sudoku solver

Sudoku solver written in C++

## How to build

First, install the dependencies from `dependencies.txt`, e.g.:

```
xargs -a dependencies.txt sudo apt install -y
pip3 install -r dependencies_pip.txt
```

You can use the SDK from the docker image:
```
docker-compose build ; docker-compose run --user $UID:$UID --rm sdk
```
It also installs the dev dependencies, which include e.g. `ccache` that could improve your experience with recompiling the project. $UID trick is added so that you don't have a build dir with root permissions.

When you have all the packages from the step above, generate your buildsystem:

```
mkdir build ; cd build ; cmake .. -DCMAKE_BUILD_TYPE=RELEASE
```

And build the application:
```
make -j $(nproc) susolver
```

For convenience, you can also call `./run release` to do the steps above.

The binary is accessible under `<build_dir>/bin/susolver`.

Try generating a sudoku with the `generate` command:
```
./susolver --generate 10 --seed 42
```
It should give you an easy board with 10 numbers to fill.

You can try solving it:
```
./susolver -i $(./susolver -g 10 -s 42)
```

For now, only Brute-Force is implemented. More algorithms will be added in the future.

### Dev environment

Install dev packages like above (but with `_dev` suffix):
```
xargs -a dependencies_dev.txt sudo apt install -y
pip3 install -r dependencies_dev_pip.txt
```
Install googletest:
```
cd /usr/src/googletest ; cmake . ; cmake --build . --target install
```

and call `cmake` like this:

```
cmake .. -DBUILD_TESTS=ON -DCOVERAGE=ON -DCMAKE_BUILD_TYPE=DEBUG
```
Call `make help` to see possible targets.
