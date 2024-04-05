GCC = gcc
CFLAGS = -g -Wall -Wshadow

htags4 : htags4.c list.c
	$(GCC) $(CFLAGS) htags4.o list.o -o htags4

htags4.o : htags4.c
	$(GCC) $(CFLAGS) -c htags4.c

list.o : list.c
	$(GCC) $(CFLAGS) -c list.c
