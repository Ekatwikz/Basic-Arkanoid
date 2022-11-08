FILENAME=game

CC=g++
CFLAGS=-std=c++20 -Wall -Wextra -Wpedantic -O0 -g -D _WINDOWS -Wno-unused-parameter
LDFLAGS=-L./ -lFrameworkRelease_x64

.PHONY: all clean clear

all: clean clear $(FILENAME)

$(FILENAME): $(FILENAME).cpp
	@echo === Compiling $(FILENAME).exe ===
	@$(CC) $(CFLAGS) $(FILENAME).cpp -o $(FILENAME).exe $(LDFLAGS)

clean:
	-@del $(FILENAME).exe

clear:
	@cls
