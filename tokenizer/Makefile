CC = gcc
CFLAGS =
HEADERS = mytoc.h
OBJECTS = test.o mytoc.o util.o strcopy.o
default: all
all: test
test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS)
	rm -f test
