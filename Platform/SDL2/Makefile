# Source Files

SOURCES += Source/Main.c
SOURCES += ../../Core/Core.c
SOURCES += ../../Core/Audio/Audio.c
SOURCES += ../../Core/Cartridge/Cartridge.c
SOURCES += ../../Core/Controller/Controller.c
SOURCES += ../../Core/Graphics/Graphics.c
SOURCES += ../../Core/Memory/Memory.c
SOURCES += ../../Core/Processor/Processor.c

OBJECTS += $(addprefix Objects/,$(notdir $(SOURCES:.c=.o)))

# Header Directories

HEADERS += -I../../Core
HEADERS += -I../../Core/Audio
HEADERS += -I../../Core/Cartridge
HEADERS += -I../../Core/Controller
HEADERS += -I../../Core/Graphics
HEADERS += -I../../Core/Memory
HEADERS += -I../../Core/Processor

# Common Flags

CFLAGS += -std=c99 -Wall -Wextra -MMD
CFLAGS += -DVERSION='"nesswemu r$(shell git rev-list --count master)"'

ifeq ($(BUILD),debug)
	CFLAGS += -O0 -g -pg
	LFLAGS += -g -pg
else
	CFLAGS += -O2
endif

# Platform-Specific Flags

ifeq ($(OS),Windows_NT)
	LFLAGS += -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2
	ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
		HEADERS += -ILibraries/SDL2-2.0.5/x86_64-w64-mingw32/include/SDL2
		LFLAGS += -LLibraries/SDL2-2.0.5/x86_64-w64-mingw32/lib
	else ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		HEADERS += -ILibraries/SDL2-2.0.5/x86_64-w64-mingw32/include/SDL2
		LFLAGS += -LLibraries/SDL2-2.0.5/x86_64-w64-mingw32/lib
	else ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		HEADERS += -ILibraries/SDL2-2.0.5/i686-w64-mingw32/include/SDL2
		LFLAGS += -LLibraries/SDL2-2.0.5/i686-w64-mingw32/lib
	endif
else ifeq ($(shell uname -s),Linux)
	HEADERS += $(shell sdl2-config --cflags)
	LFLAGS += $(shell sdl2-config --libs)
endif

# Building Rules

Build/nesswemu: $(OBJECTS)
	gcc $^ $(LFLAGS) -o $@

Objects/Main.o: Source/Main.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

Objects/Core.o: ../../Core/Core.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

Objects/Audio.o: ../../Core/Audio/Audio.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

Objects/Cartridge.o: ../../Core/Cartridge/Cartridge.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

Objects/Controller.o: ../../Core/Controller/Controller.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

Objects/Graphics.o: ../../Core/Graphics/Graphics.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

Objects/Memory.o: ../../Core/Memory/Memory.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

Objects/Processor.o: ../../Core/Processor/Processor.c
	gcc $(CFLAGS) $(HEADERS) -c $< -o $@

-include $(OBJECTS:.o=.d)
