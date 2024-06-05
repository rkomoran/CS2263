GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = main.o \
    htags.o
HDRS = htags.h
VAL = valgrind --tool=memcheck --leak-check=full
VAL += --verbose --log-file=

htags: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f htags $(OBJS) 

test: htags
	./htags < Sample.html
