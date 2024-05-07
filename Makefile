all : exec

main.o: Programme.c manager.c mode.h 
	gcc -c manager.c -o manager.o

exec: main.o manager.o
	gcc main.o manager.o -o exec

clean:
	rm -f *.o
	rm exec