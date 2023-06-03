encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c
hello.o: hello.c encrypt.h
	gcc -c hello.c
h: encrypt.o hello.o
	gcc encrypt.o hello.o -o h
