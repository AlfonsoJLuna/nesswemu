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

# Common Flags

HEADERS += -I../../Core
HEADERS += -I../../Core/Audio
HEADERS += -I../../Core/Cartridge
HEADERS += -I../../Core/Controller
HEADERS += -I../../Core/Graphics
HEADERS += -I../../Core/Memory
HEADERS += -I../../Core/Processor

CFLAGS += -std=c99 -O0 -g -pg -Wall -Wextra -MMD

# Platform-Specific Flags

ifeq ($(OS),Windows_NT)

	LFLAGS += -g -pg -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2

	ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)

		HEADERS += -ILibraries/SDL2-2.0.5/x86_64-w64-mingw32/include/SDL2
		CFLAGS += -m64
		LFLAGS += -m64 -LLibraries/SDL2-2.0.5/x86_64-w64-mingw32/lib

	else

		ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)

			HEADERS += -ILibraries/SDL2-2.0.5/x86_64-w64-mingw32/include/SDL2
			CFLAGS += -m64
			LFLAGS += -m64 -LLibraries/SDL2-2.0.5/x86_64-w64-mingw32/lib

		endif

		ifeq ($(PROCESSOR_ARCHITECTURE),x86)

			HEADERS += -ILibraries/SDL2-2.0.5/i686-w64-mingw32/include/SDL2
			CFLAGS += -m32
			LFLAGS += -m32 -LLibraries/SDL2-2.0.5/i686-w64-mingw32/lib

		endif

	endif

else

	UNAME_S += $(shell uname -s)

	ifeq ($(UNAME_S),Linux)

		HEADERS += $(shell sdl2-config --cflags)
		LFLAGS += $(shell sdl2-config --libs)

	endif

endif

# Rules

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
