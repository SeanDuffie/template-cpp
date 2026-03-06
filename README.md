# template-cpp
A starting point for various C++ projects.


# Doxygen


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