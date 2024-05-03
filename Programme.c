#include "couleurs.h" /* Importation de la bibliotheque pour gerer le terminal */
#include <stdio.h>
#include <stdlib.h>



/* SCAN VERSION ROMAIN
int scan(int d,float* f,char* c ,float min,float max){
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


}*///



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
    int n=0;
    
    salle.concert=0; //On initialise la salle comme non occupé
    
    printf("Combien de lettres contient le nom de la salle ?\n");
    scanf("%d",&n);
    salle.nomsalle=(char*)malloc(sizeof(char)*(n+1));
    if (salle.nomsalle==NULL){
        printf("Erreur de nom\n");
        exit(1);
    }
    printf("Quel est le nom de la salle ?\n");
    scanf("%s",salle.nomsalle);
    
    printf("Combien y a t-il de rangée ?\n");
    scanf("%d",&salle.nrangee);
    
    while(salle.nrangee<1){
        printf("Erreur, nombre de rangée non valide. Réessayez.\n");
        scanf("%d",&salle.nrangee);
    }
    
    printf("Combien y a t-il de siège par rangée ?\n");
    scanf("%d",&salle.nsiege);
    
    while(salle.nsiege<1){
        printf("Erreur, nombre de siege par rangée non valide. Réessayez.\n");
        scanf("%d",&salle.nsiege);
    }
    
    //On demande le nombre de siège par catégorie 
    
    printf("Combien y a t-il de rangée de catégorie A ?\n");  
    scanf("%d",&salle.nsiegeA);
    salle.nsiegeA*=salle.nsiege;//On fais rangée de Catégorie A * nombre de siège par rangée
    while(salle.nsiegeA<1){
        printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
        scanf("%d",&salle.nsiegeA);
        salle.nsiegeA*=salle.nsiege;
    } 
    
    printf("Combien y a t-il de rangée de catégorie B ?\n");  
    scanf("%d",&salle.nsiegeB);
    salle.nsiegeB*=salle.nsiege;
    while(salle.nsiegeB<1){
        printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
        scanf("%d",&salle.nsiegeB);
        salle.nsiegeB*=salle.nsiege;
    } 
    
    printf("Combien y a t-il de rangée de catégorie C ?\n");  
    scanf("%d",&salle.nsiegeC);
    salle.nsiegeC*=salle.nsiege;
    while(salle.nsiegeC<1){
        printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
        scanf("%d",&salle.nsiegeC);
        salle.nsiegeC*=salle.nsiege;
    } 
    
    while (salle.nsiegeA+salle.nsiegeB+salle.nsiegeC!=salle.nsiege*salle.nrangee){ //Si la somme des sièges des 3 catégories ne sont pas égales au nombre de siège total on recommence le scan
        printf("Il y a une erreur dans l'affectation des sièges, veuillez réessayer\n");
        
        printf("Combien y a t-il de rangée de catégorie A ?\n");  
        scanf("%d",&salle.nsiegeA);
        salle.nsiegeA*=salle.nsiege;//On fais rangée de Catégorie A * nombre de siège par rangée
        while(salle.nsiegeA<1){
            printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
            scanf("%d",&salle.nsiegeA);
            salle.nsiegeA*=salle.nsiege;
        } 
        
        printf("Combien y a t-il de rangée de catégorie B ?\n");  
        scanf("%d",&salle.nsiegeB);
        salle.nsiegeB*=salle.nsiege;
        while(salle.nsiegeB<1){
            printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
            scanf("%d",&salle.nsiegeB);
            salle.nsiegeB*=salle.nsiege;
        } 
        
        printf("Combien y a t-il de rangée de catégorie C ?\n");  
        scanf("%d",&salle.nsiegeC);
        salle.nsiegeC*=salle.nsiege;
        while(salle.nsiegeC<1){
            printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
            scanf("%d",&salle.nsiegeC);
            salle.nsiegeC*=salle.nsiege;
        }
    }
    
    printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
    scanf("%d",&salle.fosse);
    while (salle.fosse!=1 && salle.fosse!=0){
        printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
        scanf("%d",&salle.fosse);
    }

    if (salle.fosse==1){ //Si il y a une fosse on double le nombre de place en catégorie A
        salle.nsiegeA+=salle.nsiegeA;
        
        printf("Quel est le prix d'une place en fosse ?\n");
        scanf("%f",&salle.prixA);
        while (salle.prixA<0){
            printf("Quel est le prix d'une place en fosse ?\n");
            scanf("%f",&salle.prixA);
        }
    }
     //On demande le prix de chaque catégorie
    else{
        printf("Quel est le prix d'une place de catégorie A ?\n");
        scanf("%f",&salle.prixA);
        
        while (salle.prixA<0){
            printf("Quel est le prix d'une place de catégorie A ?\n");
            scanf("%f",&salle.prixA);
        }
    }
    
    printf("Quel est le prix d'une place de catégorie B ?\n");
    scanf("%f",&salle.prixB);
    
    while (salle.prixB<0){
            printf("Quel est le prix d'une place de catégorie B ?\n");
            scanf("%f",&salle.prixB);
    }
    
    printf("Quel est le prix d'une place de catégorie C ?\n");
    scanf("%f",&salle.prixC);
    
    while (salle.prixC<0){
            printf("Quel est le prix d'une place de catégorie C ?\n");
            scanf("%f",&salle.prixC);
    }
   
    return salle;
}



int main(){
    
    clrscr();            // Efface tout du terminal

    couleur("44");       // Initialise la couleur

    printf("Salut\n");

    couleur("0");        // Couleur par defaut   /!\ Tres important

    Salle salle=creerSalle();
    printf("%s",salle.nomsalle);
    free(salle.nomsalle);
    return 0;
}
