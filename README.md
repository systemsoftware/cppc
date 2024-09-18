# cppc

This is a utility for compiling C++ files in a directory. It provides various options for customizing the compilation process, including specifying the C++ version, choosing the compiler, and handling output files.

## Features

- Compiles all C++ files (`.cpp` and `.h`) in the current directory
- Option to compile all files in the directory, regardless of extension
- Customizable C++ version
- Ability to specify a different compiler
- Option to delete object files and executables after compilation

## Installation

To build and install the `cppc` tool, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/systemsoftware/cppc.git
   ```

2. Change into the project directory:

   ```bash
   cd cppc
   ```

3. Compile the project with Clang++:

   ```bash
   clang++ -std=c++17 -stdlib=libc++ main.cpp -o ~/cppc
   ```

4. (Optional) Create a symbolic link to make `cppc` accessible from anywhere:

   ```bash
   sudo ln -s ~/cppc /usr/local/bin/cppc
   ```

   This step allows you to run `cppc` from the command line without specifying the full path.

**Note:** Make sure you have `clang++` and the necessary libraries installed on your system. The symbolic link step requires `sudo` privileges.

## Usage

To use this utility, compile the program and run it from the command line. The basic usage is as follows:

```
cppc [options]
```

### Options

- `-v <version>`: Specify the C++ version to use (default is 17)
- `-c <compiler>`: Specify the compiler to use (default is clang++)
- `-d`: Delete object files and executables after compilation
- `-a`: Compile all files in the directory (ignoring .DS_Store, .o, and .out files)

## Examples

1. Compile using default settings:
   ```
   cppc
   ```

2. Use C++20 and g++ compiler:
   ```
   cppc -v 20 -c g++
   ```

3. Compile all files and delete outputs:
   ```
   cppc -a -d
   ```

## Requirements

- C++17 or later and Filesystem library support
- A C++ compiler (default is clang++)

## Notes

- It skips directories, .DS_Store files, and existing .o and .out files when scanning with the `-a` option.
- Error messages are printed to stderr in case of compilation failures or missing files.

## Limitations

- The program does not handle complex project structures or dependencies and is intended for simple, single-directory projects.
- Custom output names are not supported.

## Contributing

Feel free to fork this project and submit pull requests for any enhancements or bug fixes.

## License

MIT License. See LICENSE file for details.
