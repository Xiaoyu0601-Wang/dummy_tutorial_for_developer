# Install clang-format
First, you need to install clang-format if it's not already installed. You can do this through the terminal:
```sh
sudo apt-get update
sudo apt-get install clang-format
```

# Basic Usage
You can use clang-format to format individual files or entire directories of code. By default, clang-format tries to infer the coding style from the existing code, but you can also define a style explicitly.

To format a file, simply run:
```
clang-format -i filename.cpp
```
The ```-i``` flag tells clang-format to format the file "in place", modifying the file directly.

# Specifying a Style
clang-format supports a variety of predefined coding styles. You can specify a style with the -style option:
LLVM: ```clang-format -style=llvm -i filename.cpp```
Google: ```clang-format -style=google -i filename.cpp```
Mozilla: ```clang-format -style=mozilla -i filename.cpp```
WebKit: ```clang-format -style=webkit -i filename.cpp```
Microsoft: ```clang-format -style=microsoft -i filename.cpp```

# Create a .clang-format File
You can define custom formatting rules by creating a .clang-format configuration file in your project's root directory. clang-format will automatically use this file when formatting code.

To generate a basic .clang-format file:
```clang-format -style=llvm -dump-config > .clang-format```
This will output the default llvm style configuration. You can edit this file to customize it according to your preferences.

# Format All Files in a Directory
If you want to format all .cpp and .h files in a directory, you can use a find command to apply clang-format to all files recursively:
```
find . -name '*.cpp' -o -name '*.h' | xargs clang-format -i
```