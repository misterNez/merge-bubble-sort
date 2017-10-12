CC	= g++
CFLAGS	= -g

PROG1	= merge
OBJ1	= merge.o

PROG2	= bubble
OBJ2	= bubble.o

.SUFFIXES: .c .o

all: $(PROG1) $(PROG2)

$(PROG1):	$(OBJ1)
	$(CC) $(CFLAGS) -o $@ $(OBJ1)

$(PROG2):	$(OBJ2)
	$(CC) $(CFLAGS) -o $@ $(OBJ2)

.c.o:
	$(CC) $(CFLAGS) -c $(INCLDIRS) $<

clean:
	/bin/rm -f *.o core *.i *.s $(PROG1) $(PROG2)
