DEFAULTFILENAME=game

# 1 if windows
# 0 if linux
USINGWINDOWS=0

# 1 to clean every time
# 0 to not
AUTOCLEAN=1

ifeq ($(USINGWINDOWS), 1)
	DELETE=del
	CLEAR=cls

	LAUNCH=
	OUTPUTEXTENSION=.exe
	CHECKLIBPATH=call checkLibPath.bat

	PREDEFINES=_WINDOWS
	SANITIZEFLAGS=
	LDFLAGS=-L./lib/windows -lFrameworkRelease_x64
else
	DELETE=rm
	CLEAR=clear

	LAUNCH=./lib/launch.cpp
	OUTPUTEXTENSION=
	CHECKLIBPATH=

	PREDEFINES=
	LDFLAGS=-lSDL2 -lSDL2main -lSDL2_image
	SANITIZEFLAGS=-fsanitize=address,undefined
endif

ifeq ($(AUTOCLEAN), 1)
	SHOULDCLEAN=clean
else
	SHOULDCLEAN=
endif

CXX=g++
CXXFLAGS=-std=c++20 -Wall -Wextra -Wpedantic -O0 -g3 $(PREDEFINES:%=-D %) -Wno-unused-parameter $(SANITIZEFLAGS)
INC=./gameSrc ./lib

.PHONY: all clean clear

all: $(SHOULDCLEAN) clear $(DEFAULTFILENAME)

$(DEFAULTFILENAME): $(DEFAULTFILENAME).cpp
%: %.cpp
	@$(CHECKLIBPATH)
	@echo === Compiling $< to $@$(OUTPUTEXTENSION) ===
	@$(CXX) $(CXXFLAGS) $(INC:%=-I %) $< $(LAUNCH) -o $@$(OUTPUTEXTENSION) $(LDFLAGS)

clean:
	-@$(DELETE) $(DEFAULTFILENAME)$(OUTPUTEXTENSION)

clear:
	@$(CLEAR)
