include ../settings.mk

check: test.c ../math/math.o ../parser.o
	$(CC) test.c ../math/math.o ../parser.o -I../math -I../. -I. -o test
	./test

clean:
	-rm *.o test *~

