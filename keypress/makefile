CC         = clang
CFLAGS     = -c -Wall
SDLFLAGS   = `sdl-config --cflags --libs`
VPATH      = src
OBJDIR     = temp
SOURCES    = main.c
OBJECTS    = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
HEADERS    = include/
EXECUTABLE = keypress.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(SDLFLAGS) -o $@

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADERS) $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(EXECUTABLE)

