#ifndef COULEURS
#define COULEURS

#include <stdio.h>

// Efface l'écran et replace le curseur en haut à gauche
#define clrscr() printf("\033[H\033[2J")

// Sélection de couleurs
#define couleur(param) printf("\033[%sm",param)
/*   
         0  réinitialisation         
         1  haute intensité (des caractères)
         5  clignotement             
         7  video inversé
         30, 31, 32, 33, 34, 35, 36, 37 couleur des caractères
         40, 41, 42, 43, 44, 45, 46, 47 couleur du fond
        
    noir, rouge, vert, jaune, bleu, magenta, cyan et blanc 

*/

#endif