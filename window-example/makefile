CC         = clang
CFLAGS     = -c -Wall
SDLFLAGS   = `sdl-config --cflags --libs`
VPATH      = src
OBJDIR     = temp
SOURCES    = window.c
OBJECTS    = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
EXECUTABLE = window.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(SDLFLAGS) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

