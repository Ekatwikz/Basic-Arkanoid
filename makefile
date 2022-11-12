DEFAULTFILES=game

# 1 if windows
# 0 if linux
USINGWINDOWS=1

# 1 to clean every time
# 0 to not
AUTOCLEAN=1

DEBUGFLAGS=-O0 -g3

ifeq ($(USINGWINDOWS), 1)
	DELETE=del
	CLEAR=cls

	LAUNCH=
	OUTPUTEXTENSION=.exe
	CHECKLIBPATH=call checkLibPath.bat

	LIBPATHS=./lib/windows
	LIBRARIES=FrameworkRelease_x64

	PREDEFINES=_WINDOWS
	SANITIZEFLAGS=
else
	DELETE=rm
	CLEAR=clear

	LAUNCH=./lib/launch.cpp
	OUTPUTEXTENSION=
	CHECKLIBPATH=

	LIBPATHS=
	LIBRARIES=SDL2 SDL2main SDL2_image

	PREDEFINES=
	SANITIZEFLAGS=-fsanitize=address,undefined
endif

ifeq ($(AUTOCLEAN), 1)
	SHOULDCLEAN=clean
else
	SHOULDCLEAN=
endif

WARNINGS=all extra pedantic no-unused-parameter

CXX=g++
CXXFLAGS=-std=c++20 $(WARNINGS:%=-W%) $(DEBUGFLAGS) $(PREDEFINES:%=-D %) $(SANITIZEFLAGS)
LDFLAGS=$(LIBPATHS:%=-L%) $(LIBRARIES:%=-l%)
INC=./gameSrc ./lib

.PHONY: all clean clear

all: $(SHOULDCLEAN) clear $(DEFAULTFILES)

$(DEFAULTFILES): $(DEFAULTFILES:%=%.cpp)
%: %.cpp
	@$(CHECKLIBPATH)
	@echo === Compiling $< to $@$(OUTPUTEXTENSION) ===
	@$(CXX) $(CXXFLAGS) $(INC:%=-I %) $< $(LAUNCH) -o $@$(OUTPUTEXTENSION) $(LDFLAGS)

clean:
	-@$(DELETE) $(DEFAULTFILES)$(OUTPUTEXTENSION)

clear:
	@$(CLEAR)
