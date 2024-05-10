CFLAGS = -Wno-implicit-function-declaration

Tout : prg 

prg: Programme.o manageur.o festivalier.o couleur.o
	@echo "Creation de l'application finale"
	@gcc $(CFLAGS) Programme.o manageur.o festivalier.o -o prg

Programme.o: Programme.c mode.h Couleurs.h
	@echo "Compilation du programme principal"
	@gcc $(CFLAGS) -c Programme.c 

manageur.o: manageur.c mode.h Couleurs.h
	@echo "Compilation mode manageur"
	@gcc $(CFLAGS) -c manageur.c

festivalier.o: festivalier.c mode.h Couleurs.h
	@echo "Compilation du mode festivalier"
	@gcc $(CFLAGS) -c festivalier.c 

couleur.o: Couleurs.h
	@echo "Compilation des couleurs"
	@gcc $(CFLAGS) -c Couleurs.h

clean:
	@echo "Supression des fichier supplementaires"
	rm -f *.o
	rm prg