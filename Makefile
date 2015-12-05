include settings.mk

C_FILES=main.c parser.c math/math.c
OBJS=$(C_FILES:.c=.o)
BIN=CCalculator



$(BIN): $(OBJS) Makefile
	$(CC) $(OBJS) -o $@

clean:
	rm -fr $(OBJS) $(BIN) *~
	cd test && make clean

check: $(OBJS)
	cd test && make check

