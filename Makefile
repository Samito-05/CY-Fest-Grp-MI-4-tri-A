all : exec

main.o: Programme.c mode.h Couleurs.h
	gcc -c main.c -o main.o

manageur.o: manageur.c mode.h Couleurs.h
	gcc -c manageur.c -o manageur.o

festivalier.o: festivalier.c mode.h Couleurs.h
	gcc -c festivalier.c -o festivalier.o

exec: main.o manageur.o festivalier.o
	gcc main.o manageur.o festivalier.o -o exec

clean:
	rm -f *.o
	rm exec