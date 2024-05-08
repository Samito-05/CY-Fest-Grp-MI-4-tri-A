all : exec

main.o: Programme.c mode.h Couleurs.h
	gcc -c main.c -o main.o

manager.o: manager.c mode.h Couleurs.h
	gcc -c manager.c -o manager.o

festivalier.o: festivalier.c mode.h Couleurs.h
	gcc -c festivalier.c -o festivalier.o

exec: main.o manager.o festivalier.o
	gcc main.o manager.o festivalier.o -o exec

clean:
	rm -f *.o
	rm exec