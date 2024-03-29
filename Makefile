CC = clang
CFLAGS = -I/usr/local/include/SDL2 -L/usr/local/lib -lSDL2
SOURCES = main.c
EXECUTABLE = my_game

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f $(EXECUTABLE)