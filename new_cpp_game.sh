#!/bin/bash

# Prompt the user for the project name
read -p "Enter the name of your new C/C++ game project: " project_name

# Create the project directory
mkdir $project_name
cd $project_name

# Create the directory structure
mkdir -p src include lib assets build

# Install GLFW library
case "$(uname -s)" in
    Darwin*)
        # macOS
        brew install glfw
        ;;
    Linux*)
        echo "This script is designed for macOS with Homebrew. For Linux, please install GLFW using your package manager."
        exit 1
        ;;
    MINGW*|MSYS*|CYGWIN*)
        # Windows
        echo "This script is designed for macOS. For Windows, please install GLFW manually."
        exit 1
        ;;
    *)
        echo "Unsupported operating system. Please install GLFW manually."
        exit 1
        ;;
esac

# Copy GLFW library and include files to the project directories
cp -r /opt/homebrew/include/GLFW include/
cp /opt/homebrew/lib/libglfw.a lib/

# Create initial C/C++ files
touch src/main.c src/game.c include/$project_name.h

# Generate the Makefile
cat > Makefile <<EOL
CC = clang
CXX = clang++
CFLAGS = -I include -L lib -lglfw
CXXFLAGS = -I include -L lib -lglfw
SOURCES = src/main.c src/game.c
EXECUTABLE = $project_name

all: \$(EXECUTABLE)

\$(EXECUTABLE): \$(SOURCES)
	\$(CC) \$(CFLAGS) -o \$(EXECUTABLE) \$(SOURCES) -lglfw

clean:
	rm -f \$(EXECUTABLE)
EOL

# Populate the README.md file
cat > README.md <<EOL
# $project_name

This is a C/C++ game project using the GLFW library.

## Build Instructions

1. Install the necessary dependencies (e.g., GLFW)
2. Run `make` in the project directory to build the game
3. Run the compiled executable `./$project_name`

## Project Structure

- `src/`: Contains the C/C++ source files
- `include/`: Contains the header files
- `lib/`: Contains the compiled library files (e.g., GLFW)
- `assets/`: Contains game assets (images, sounds, fonts)
- `build/`: Contains the compiled binary files
- `Makefile`: Build script for the project
EOL

echo "New C/C++ game project '$project_name' created."