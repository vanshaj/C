flags=-O0 -Wall -std=c2x
ldflags=

all: htable

htable: htable.o
	gcc $(flags) $^ -o $@ $(ldflags)

htable.o: htable.c
	gcc $(flags) -c $^

clean:
	rm -f *.o htable