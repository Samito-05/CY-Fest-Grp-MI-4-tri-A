#include "couleurs.h" /* Importation de la bibliotheque pour gerer le terminal */

int main(){
    
    clrscr();

    couleur("32");

    printf("Salut");

    couleur("0");

    return 0;
}
