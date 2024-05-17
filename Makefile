CFLAGS = -Wno-implicit-function-declaration

Tout : prg 

prg: Programme.o manageur.o festivalier.o 
	@echo "Creation de l'application finale"
	@gcc $(CFLAGS) Programme.o manageur.o festivalier.o -o prg

Programme.o: Programme.c bibli.h
	@echo "Compilation du programme principal"
	@gcc $(CFLAGS) -c Programme.c 

manageur.o: manageur.c bibli.h
	@echo "Compilation mode manageur"
	@gcc $(CFLAGS) -c manageur.c

festivalier.o: festivalier.c bibli.h
	@echo "Compilation du mode festivalier"
	@gcc $(CFLAGS) -c festivalier.c 


vide:
	@echo "Supression des fichier supplementaires"
	@rm -f *.o
	@rm prg