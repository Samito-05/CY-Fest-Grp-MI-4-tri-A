CFLAGS = -Wno-implicit-fuction-declaration

Tout : prg 

prg: main.o manageur.o festivalier.o
	@echo "Creation de l'application finale"
	gcc $(CFLAGS) main.o manageur.o festivalier.o -o prg

Programme.o: Programme.c mode.h Couleurs.h
	@echo "Compilation du programme principal"
	gcc $(CFLAGS) -c Programme.c 

manageur.o: manageur.c mode.h Couleurs.h
	@echo "Compilation mode manageur"
	gcc $(CFLAGS) -c manageur.c

festivalier.o: festivalier.c mode.h Couleurs.h
	@echo "Compilation du mode festivalier"
	gcc $(CFLAGS) -c festivalier.c 

 
clean:
	@echo "Supression des fichier supplementaires"
	rm -f *.o
	rm prg