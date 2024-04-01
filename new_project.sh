#!/bin/bash

# Prompt the user for the project name
read -p "Enter the name of your new C game project: " project_name

# Create the project directory
mkdir $project_name
cd $project_name

# Create the directory structure
mkdir -p src include lib assets build

# Create the initial files
touch src/main.c include/$project_name.h Makefile README.md

# Populate the Makefile
cat > Makefile <<EOL
CC = clang
CFLAGS = -I include -L lib -lSDL2
SOURCES = src/main.c
EXECUTABLE = $project_name

all: \$(EXECUTABLE)

\$(EXECUTABLE): \$(SOURCES)
	\$(CC) \$(CFLAGS) -o \$(EXECUTABLE) \$(SOURCES)

clean:
	rm -f \$(EXECUTABLE)
EOL

# Populate the README.md file
cat > README.md <<EOL
# $project_name

This is a C-based game project.

## Build Instructions

1. Install the necessary dependencies (e.g., SDL2)
2. Run `make` in the project directory to build the game
3. Run the compiled executable `.$project_name`

## Project Structure

- `src/`: Contains the C source files
- `include/`: Contains the header files
- `lib/`: Contains the compiled library files (e.g., SDL2)
- `assets/`: Contains game assets (images, sounds, fonts)
- `build/`: Contains the compiled binary files
- `Makefile`: Build script for the project
EOL

#!/bin/bash

# ... (existing script code)

# Install SDL2 library
if [ -d "/usr/local/include/SDL2" ]; then
    cp -r /usr/local/include/SDL2 include/
    cp /usr/local/lib/libSDL2.a lib/
elif [ -d "/usr/include/SDL2" ]; then
    cp -r /usr/include/SDL2 include/
    cp /usr/lib/libSDL2.a lib/
elif [ -d "C:/path/to/SDL2/include" ]; then
    cp -r "C:/path/to/SDL2/include" include/
    cp "C:/path/to/SDLL2/lib/x64/libSDL2.a" lib/
else
    echo "SDL2 library not found. Please install SDL2 and update the script accordingly."
    exit 1
fi

# ... (rest of the script)

echo "New C game project '$project_name' created."