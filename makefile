FILENAME=game

# 1 if windows
# 0 if linux
USINGWINDOWS=1

# 1 to clean every time
# 0 to not
AUTOCLEAN=1

ifeq ($(USINGWINDOWS), 1)
	PREDEFINES=-D _WINDOWS
	DELETE=del
	CLEAR=cls
	OUTPUTEXTENSION=.exe
	LDFLAGS=-L./lib/windows -lFrameworkRelease_x64
	LAUNCH=
	CHECKLIBPATH=call checkLibPath.bat
else
	PREDEFINES=
	DELETE=rm
	CLEAR=clear
	OUTPUTEXTENSION=
	LDFLAGS=-lSDL2 -lSDL2main -lSDL2_image
	LAUNCH=./lib/launch.cpp
	CHECKLIBPATH=
endif

ifeq ($(AUTOCLEAN), 1)
	SHOULDCLEAN=clean
else
	SHOULDCLEAN=
endif

CC=g++
CFLAGS=-std=c++20 -Wall -Wextra -Wpedantic -O0 -g $(PREDEFINES) -Wno-unused-parameter
LIBSEARCH=-I ./gameSrc -I ./lib

.PHONY: all clean clear

all: $(SHOULDCLEAN) clear $(FILENAME)

$(FILENAME): $(FILENAME).cpp
	@$(CHECKLIBPATH)
	@echo === Compiling $(FILENAME)$(OUTPUTEXTENSION) ===
	@$(CC) $(CFLAGS) $(LIBSEARCH) $(LAUNCH) $(FILENAME).cpp -o $(FILENAME)$(OUTPUTEXTENSION) $(LDFLAGS)

clean:
	-@$(DELETE) $(FILENAME)$(OUTPUTEXTENSION)

clear:
	@$(CLEAR)
