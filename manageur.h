#ifndef MANAGEUR_H
#define MANAGEUR_H

typedef struct{
    int concert; // 0 si la salle n'est pas utilisié, sinon 1
    char* nomsalle; 
    int nrangee; // le nombre de rangée total
    int nsiege; // le nombre de siège par rangée
    //Les sièges par catégories
    int nsiegeA;
    int nsiegeB;
    int nsiegeC; 
    int fosse; // 0 si il n'y a pas de fosse, sinon 1
    // Prix par catégories
    float prixA;
    float prixB;
    float prixC;
}Salle;

Salle creerSalle();

void salle_txt(Salle salle);

void afficheSalle(Salle salle);

void afficheSalle2(char* nom_salle);

#endif