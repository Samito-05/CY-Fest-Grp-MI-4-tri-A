#include "couleurs.h" /* Importation de la bibliotheque pour gerer le terminal */

#include <stdio.h>

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

Salle creerSalle(){
    Salle salle;
    salle.concert=0; //On initialise la salle comme non occupé
    printf("Quel est le nom de la salle ?\n");
    salle.nomsalle=scan(); //Faudra paramétré scan
    printf("Combien y a t-il de rangée ?\n");
    salle.nrangee=scan();
    printf("Combien y a t-il de siège par rangée ?\n");
    salle.nsiege=scan();
    //On demande le nombre de siège par catégorie 
    printf("Combien y a t-il de rangée de catégorie A?\n");  
    salle.nsiegeA=scan()*salle.nsiege; //On fais rangée de Catégorie A * nombre de siège par rangée
    printf("Combien y a t-il de rangée de catégorie B?\n");
    salle.nsiegeB=scan()*salle.nsiege;
    printf("Combien y a t-il de rangée de catégorie C?\n");
    salle.nsiegeC=scan()*salle.nsiege;
    while (salle.nsiegeA+salle.nsiegeB+salle.nsiegeC!=salle.nsiege*salle.nrangee){ //Si la somme des sièges des 3 catégories ne sont pas égales au nombre de siège total on recommence le scan
        printf("Il y a une erreur dans l'affectation des sièges, veuillez réessayer\n");
        printf("Combien y a t-il de rangée de catégorie A?\n");  
        salle.nsiegeA=scan()*salle.nsiege;
        printf("Combien y a t-il de rangée de catégorie B?\n");
        salle.nsiegeB=scan()*salle.nsiege;
        printf("Combien y a t-il de rangée de catégorie C?\n");
        salle.nsiegeC=scan()*salle.nsiege;
    }
    printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
    salle.fosse=scan();
    if (salle.fosse==1){ //Si il y a une fosse on double le nombre de place en catégorie A
        salle.nsiegeA+=salle.nsiegeA;
        printf("Quel est le prix d'une place en fosse ?\n");
        salle.prixA=scan();
    }
    //On demande le prix de chaque catégorie
    else{
        printf("Quel est le prix d'une place de catégorie A ?\n");
        salle.prixA=scan();
    }
    printf("Quel est le prix d'une place de catégorie B ?\n");
    salle.prixB=scan();
    printf("Quel est le prix d'une place de catégorie C ?\n");
    salle.prixC=scan();
    return salle;
}

int scan(int d,float* f,/*char* c ,*/float min,float max){
    // je sais pas faire tout en un seul donc faut qu on voit si c est possible 
    //on est obliger d utiliser des pointeur sinon on peut que retourner du int 
    if(d != -9){
        scanf("%d",&d);
        while (d<min || d>max){
        printf("erreur la valeur saisie doit être entre %f et %f\n",min , max);
        scanf("%d",&d);
        }
        return d;
    }
    if(*f !=-8){
        scanf("%f",*f);
            while(*f<min || *f>max){
                printf("erreur la valeur saisie doit être entre %f et %f\n",min , max);
                scanf("%f",*f);
                
            }
        
    }
    if (*c != gabinleplusbo){
        scanf("%s"*c);
    }


}



int main(){
    
    clrscr();            // Efface tout du terminal

    couleur("44");       // Initialise la couleur

    printf("Salut\n");

    couleur("0");        // Couleur par defaut   /!\ Tres important

    return 0;
}
