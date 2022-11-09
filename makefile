FILENAME=game

# 1 if windows
# 0 if linux
USINGWINDOWS=0

ifeq ($(USINGWINDOWS), 1)
	PREDEFINES=-D _WINDOWS
	DELETE=del
	CLEAR=cls
	OUTPUTEXTENSION=.exe
	LDFLAGS=-L./lib/windows -lFrameworkRelease_x64
	LAUNCH=
else
	PREDEFINES=
	DELETE=rm
	CLEAR=clear
	OUTPUTEXTENSION=
	LDFLAGS=-lSDL2 -lSDL2main -lSDL2_image
	LAUNCH=./lib/launch.cpp
endif

CC=g++
CFLAGS=-std=c++20 -Wall -Wextra -Wpedantic -O0 -g $(PREDEFINES) -Wno-unused-parameter
LIBSEARCH=-I ./gameSrc -I ./lib

.PHONY: all clean clear

all: clean clear $(FILENAME)

$(FILENAME): $(FILENAME).cpp
	@echo === Compiling $(FILENAME)$(OUTPUTEXTENSION) ===
	@$(CC) $(CFLAGS) $(LIBSEARCH) $(LAUNCH) $(FILENAME).cpp -o $(FILENAME)$(OUTPUTEXTENSION) $(LDFLAGS)

clean:
	-@$(DELETE) $(FILENAME)$(OUTPUTEXTENSION)

clear:
	@$(CLEAR)
