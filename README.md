# template-cpp
A starting point for various C++ projects.


## Installation

### vcpkg

`vcpkg` is a package manager for C++, similar to how `uv` works for Python. To install it, it must be downloaded and compiled from source, then associated with the environment.

#### 1. Build Tools

##### Windows
1. Git
2. Visual Studio
   1. Download Visual Studio Community
   2. Check the box for "Desktop Development with C++"

##### macOS

1. Xcode: `xcode-select --install`
2. Install CMake: `brew install cmake`

##### Linux

1. Install Build Tools
``` bash
sudo apt update
sudo apt install build-essential cmake git curl zip unzip tar
```

#### 2. Install vcpkg

1. Clone the repo: `git clone https://github.com/microsoft/vcpkg.git`
   1. NOTE: Pick a permanent location, like root or home.
2. Bootstrap:
##### Windows

``` bash
cd vcpkg
bootstrap-vcpkg.bat
```

##### Mac/Linux

``` bash
cd vcpkg
./bootstrap-vcpkg.sh

```
#### 3. Enable Global Integration (optional, but recommended)
``` bash
# From inside the vcpkg directory
./vcpkg integrate install
```

#### 4. Set Environment Variable

##### Windows

1. Edit the System Environment Variables -> Environment Variables -> New
2. {"VCPKG_ROOT": "C:\vcpkg" <or other path>}

##### Mac/Linux

Add this to `~/.zshrc` or `~/.bashrc`:
``` bash
export VCPKG_ROOT=~/vcpkg
export PATH=$VCPKG_ROOT:$PATH  # Optional: lets you type 'vcpkg' anywhere
```

#### 5. VS Code Setup

1. Install these Extensions:
   1. C/C++ Extension Pack (Microsoft): Includes IntelliSense and Debugging.
   2. CMake Tools (Microsoft): The engine that reads CMakeLists.txt.
2. Point VS Code to vcpkg:
   1. Settings -> CMake: Toolchain File.
   2. Windows: Set it to `${env:VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake`
   3. Mac/Linux: Set it to `${env:VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake`

#### 5. Validate

1. Git: `git --version`
2. CMake: `cmake --version`
3. vcpkg: `vcpkg version`

## 📚 Documentation

Documentation is integrated directly into the CMake build process.

### Initializing Doxygen

1. Generate the default "Doxyfile" using `doxygen -g`.
2. Make the following edits to the Doxyfile keys:
   1. `PROJECT_NAME = "Project Name"`
   2. `RECURSIVE = YES` (Scans the "./src/ folder)
   3. `OUTPUT_DIRECTORY = docs` (Where the HTML is saved)
   4. `USE_MDFILE_AS_MAINPAGE = README.md` (Makes the README the "Home" page)

### Generating Docs
You can generate the HTML documentation using the `docs` target:
``` bash
cmake --build build --target docs
```

# Using CMake

1. Configure: `cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[path_to_vcpkg]/scripts/buildsystems/vcpkg.cmake`
2. Build: `cmake --build build`