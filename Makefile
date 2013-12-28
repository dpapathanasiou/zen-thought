
CFLAGS=-Wall -g

TARGET  = zen-thought
SOURCES = $(shell echo *.c)
OBJECTS = $(SOURCES:.c=.o)
DATA    = $(shell echo *.txt)

PREFIX  = $(DESTDIR)/usr/local
BINDIR  = $(PREFIX)/bin
DATADIR = /usr/share/games/zen-thought

all: $(TARGET)

clean:
	-rm -f $(TARGET) $(OBJECTS)

install:
	install -D $(TARGET) $(BINDIR)/$(TARGET)
	install -D $(DATA) $(DATADIR)/$(DATA)
 
uninstall:
	-rm -f $(BINDIR)/$(TARGET)
	-rm -rf $(DATADIR)
