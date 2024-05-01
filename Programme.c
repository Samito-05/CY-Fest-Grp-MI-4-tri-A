#include "couleurs.h" /* Importation de la bibliotheque pour gerer le terminal */

int main(){
    
    clrscr();            // Efface tout du terminal

    couleur("44");       // Initialise la couleur

    printf("Salut");

    couleur("0");        // Couleur par defaut   /!\ Tres important

    return 0;
}
