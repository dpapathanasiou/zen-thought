
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

CFLAGS=-Wall -g

TARGET  = zen-thought
SOURCES = $(shell echo *.c)
OBJECTS = $(SOURCES:.c=.o)
DATA    = $(shell echo *.txt)

PREFIX  = $(DESTDIR)/usr/local
BINDIR  = $(PREFIX)/bin
DATADIR = /usr/local/share/games/zen-thought

all: $(TARGET)

ifeq ($(uname_S),Darwin)
clean:
	-rm -f $(TARGET) $(OBJECTS)
	-rm -rf $(TARGET).dSYM
else
clean:
	-rm -f $(TARGET) $(OBJECTS)
endif

ifeq ($(uname_S),Darwin)
install:
	install -C $(TARGET) $(BINDIR)
	install -d $(DATADIR)
	install -C $(DATA) $(DATADIR)
else
install:
	install -D $(TARGET) $(BINDIR)/$(TARGET)
	install -D $(DATA) $(DATADIR)/$(DATA)
endif

uninstall:
	-rm -f $(BINDIR)/$(TARGET)
	-rm -rf $(DATADIR)
