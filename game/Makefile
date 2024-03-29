CC = clang
CXX = clang++
CFLAGS = -I include -L lib -lglfw
CXXFLAGS = -I include -L lib -lglfw
SOURCES = src/main.c src/game.c
EXECUTABLE = game

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES) -lglfw

clean:
	rm -f $(EXECUTABLE)
