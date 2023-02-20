## Project file structure ##
IDIR = include
SRCDIR = src
ODIR = obj

## CC compiler options ##
CC = gcc
CFLAGS = -g -Wall -I$(IDIR)
LIBS = -lm

_DEPS = utils.h network.h globals.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = utils.o network.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

## Compilation ##
$(ODIR)/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calculate_routing_records: $(OBJ)
	$(CC) -o $@ main.c $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~