#include "couleurs.h" /* Importation de la bibliotheque pour gerer le terminal */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void choix();
void afficheSalle();



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
    clrscr();

    salle.nomsalle=(char*)malloc(sizeof(char)*(n+1));
    if (salle.nomsalle==NULL){
        printf("Erreur de nom\n");
        exit(1);
    }
    printf("Quel est le nom de la salle ?\n");
    scanf("%s",salle.nomsalle);
    clrscr();
    
    printf("Combien y a t-il de rangée ?\n");
    scanf("%d",&salle.nrangee);
    clrscr();
    
    while(salle.nrangee<1){
        printf("Erreur, nombre de rangée non valide. Réessayez.\n");
        scanf("%d",&salle.nrangee);
        clrscr();
    }
    
    printf("Combien y a t-il de siège par rangée ?\n");
    scanf("%d",&salle.nsiege);
    clrscr();
    
    while(salle.nsiege<1){
        printf("Erreur, nombre de siege par rangée non valide. Réessayez.\n");
        scanf("%d",&salle.nsiege);
        clrscr();
    }
    
    //On demande le nombre de siège par catégorie 
    printf("Combien y a t-il de rangée de catégorie A ?\n");  
    scanf("%d",&salle.nsiegeA);
    salle.nsiegeA*=salle.nsiege;//On fais rangée de Catégorie A * nombre de siège par rangée
    clrscr();
    while(salle.nsiegeA<0){
        printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
        scanf("%d",&salle.nsiegeA);
        salle.nsiegeA*=salle.nsiege;
        clrscr();
    } 
    //alessio le goat
    printf("Combien y a t-il de rangée de catégorie B ?\n");  
    scanf("%d",&salle.nsiegeB);
    salle.nsiegeB*=salle.nsiege;
    while(salle.nsiegeB<0){
        printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
        scanf("%d",&salle.nsiegeB);
        salle.nsiegeB*=salle.nsiege;
        clrscr();
    } 
    
        salle.nsiegeC=salle.nsiege*salle.nrangee-(salle.nsiegeA+salle.nsiegeB);
        clrscr();
        if(salle.nsiegeC<0){
            salle.nsiegeC=0;
        }



    while ((salle.nsiegeA+salle.nsiegeB+salle.nsiegeC)!=(salle.nsiege*salle.nrangee)){ //Si la somme des sièges des 3 catégories ne sont pas égales au nombre de siège total on recommence le scan
        printf("Il y a une erreur dans l'affectation des sièges, veuillez réessayer\n");
        
        printf("Combien y a t-il de rangée de catégorie A ?\n");  
        scanf("%d",&salle.nsiegeA);
        clrscr();
        salle.nsiegeA*=salle.nsiege;//On fais rangée de Catégorie A * nombre de siège par rangée
        while(salle.nsiegeA<0){
            printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
            scanf("%d",&salle.nsiegeA);
            salle.nsiegeA*=salle.nsiege;
            clrscr();
        } 
        
        printf("Combien y a t-il de rangée de catégorie B ?\n");  
        scanf("%d",&salle.nsiegeB);
        salle.nsiegeB*=salle.nsiege;
        clrscr();
        while(salle.nsiegeB<0){
            printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
            scanf("%d",&salle.nsiegeB);
            salle.nsiegeB*=salle.nsiege;
            clrscr();
        } 
        
        salle.nsiegeC=salle.nsiege*salle.nrangee-(salle.nsiegeA+salle.nsiegeB);
        clrscr();
          if(salle.nsiegeC<0){
            salle.nsiegeC=0;
        }


    }
    
    printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
    scanf("%d",&salle.fosse);
    clrscr();
    while (salle.fosse!=1 && salle.fosse!=0){
        printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
        scanf("%d",&salle.fosse);
        clrscr();
    }

    if (salle.fosse==1){ //Si il y a une fosse on double le nombre de place en catégorie A
        salle.nrangee+=salle.nsiegeA/salle.nsiege;
        salle.nsiegeA+=salle.nsiegeA;
    //merci julesssssssssss    
        
        printf("Quel est le prix d'une place en fosse ?\n");
        scanf("%f",&salle.prixA);
        clrscr();
        while (salle.prixA<0){
            printf("Quel est le prix d'une place en fosse ?\n");
            scanf("%f",&salle.prixA);
            clrscr();
        }
    }
     //On demande le prix de chaque catégorie
    else{
        printf("Quel est le prix d'une place de catégorie A ?\n");
        scanf("%f",&salle.prixA);
        clrscr();
        
        while (salle.prixA<0){
            printf("Quel est le prix d'une place de catégorie A ?\n");
            scanf("%f",&salle.prixA);
            clrscr();
        }
    }
    
    printf("Quel est le prix d'une place de catégorie B ?\n");
    scanf("%f",&salle.prixB);
    clrscr();
    
    while (salle.prixB<0){
            printf("Quel est le prix d'une place de catégorie B ?\n");
            scanf("%f",&salle.prixB);
            clrscr();
    }
    
    printf("Quel est le prix d'une place de catégorie C ?\n");
    scanf("%f",&salle.prixC);
    clrscr();
    
    while (salle.prixC<0){
            printf("Quel est le prix d'une place de catégorie C ?\n");
            scanf("%f",&salle.prixC);
            clrscr();
    }
    
    char* fichiersalle="salle.txt";
    FILE* fichier =fopen(fichiersalle,"a+");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture du fichier %s\n", fichiersalle);
        exit(1);
    }
    
    fprintf(fichier, "%s : Nom de la salle\n", salle.nomsalle);
    fprintf(fichier, "%d : Est-ce que la salle est utilisée ?\n", salle.concert);
    fprintf(fichier, "%d : Nombre de rangée\n", salle.nrangee);
    fprintf(fichier, "%d : Nombre de siège par rangée\n", salle.nsiege);
    fprintf(fichier, "%d : Nombre de siège de catégorie A\n", salle.nsiegeA);
    fprintf(fichier, "%d : Nombre de siège de catégorie B\n", salle.nsiegeB);
    fprintf(fichier, "%d : Nombre de siège de catégorie C\n", salle.nsiegeC);
    fprintf(fichier, "%d : Est-ce qu'il y a une fosse ?\n", salle.fosse);
    fprintf(fichier, "%.2f : Prix de la catégorie A\n", salle.prixA);
    fprintf(fichier, "%.2f : Prix de la catégorie B\n", salle.prixB);
    fprintf(fichier, "%.2f : Prix de la catégorie C\n", salle.prixC);
    fprintf(fichier,"\n");

    fclose(fichier);
    free(salle.nomsalle);
    return salle;
}
void choix(){//oublier pas d apppeler la fonction a la fin de chaque action majeur 
    int choix;
    printf("que voulez vous faire ?\n1.ajouter une salle 2...\n");//ecris tout les choix de manageur et ne pas oublier 
    scanf("%d",&choix);
     while (choix<1 || choix>2){
        printf("erreur la valeur saisie doit être entre 1 et 2\n");
        scanf("%d",&choix);
    }
    if (choix==1){
        Salle salle=creerSalle();
        afficheSalle(salle);
        choix=0;
    }

}
//l'amour n'a pas d'age ;)
void afficheSalle(Salle salle){
    int r=1;

    //Entête
    clrscr();
    printf("       Plan de la salle :  \n");
    printf("            SCENE           \n");
    printf("-------------------------------\n");

    for (int i=0; i<salle.nsiegeA/salle.nsiege /*on veut le nombre de rangée de cette catégorie et pas le nombre de siège */; i++){ //On affiche catégorie A
        printf("R %d ",r);
        for (int j=0; j<salle.nsiege; j++){
            couleur("36");
            printf("O ");
            couleur("0");
        }
    printf("\n");
    r++;
    }

    for (int i=0; i<salle.nsiegeB/salle.nsiege; i++){//On affiche catégorie B
        printf("R %d ",r);
        for (int j=0; j<salle.nsiege; j++){
            couleur("33");
            printf("O ");
            couleur("0");
        }
    printf("\n");
    r++;
    }

    for (int i=0; i<salle.nsiegeC/salle.nsiege; i++){//On affiche catégorie C
        printf("R %d ",r);
        for (int j=0; j<salle.nsiege; j++){
            couleur("37");
            printf("O ");
            couleur("0");
        }
    printf("\n");
    r++;
    }
    printf("-------------------------------\n");
    choix();
}

void afficheSalle2(char* nom_salle) {
    char *nom = "salle.txt";

    // ouvrir le fichier 
    FILE* salles = fopen(nom, "r");
    if (salles == NULL) {
        exit(1);
    }

    char phrase[50];
    int trouve = 0;

    // Lire ligne par ligne jusqu'à la fin du fichier
    while (fgets(phrase, sizeof(phrase), salles) != NULL) {
        // Vérification de la bonne salle
        if (strstr(phrase, nom_salle) != NULL) {
            printf("La salle existe.\n");
            trouve = 1;
            break;
        }
        
        for (int j = 0; j < 11; j++){                  //Passage a la prochaine salle

        fgets(phrase, sizeof(phrase), salles);
    }
    }


    // Vérifier si la fin du fichier est atteinte sans trouver la salle
    if (!trouve) {
        printf("La salle n'a pas été trouvée.\n");
        fclose(salles);
        return;
    }

    // Reccuperation de données de la salle

    int nbr_rangees, nbr_places, cat_a, cat_b, cat_c, fosse;

    fgets(phrase, sizeof(phrase), salles);

    fgets(phrase, sizeof(phrase), salles);
    nbr_rangees = atoi(phrase);

    fgets(phrase, sizeof(phrase), salles);
    nbr_places = atoi(phrase);

    fgets(phrase, sizeof(phrase), salles);
    cat_a = atoi(phrase);

    fgets(phrase, sizeof(phrase), salles);
    cat_b = atoi(phrase);

    fgets(phrase, sizeof(phrase), salles);
    cat_c = atoi(phrase);

    fgets(phrase, sizeof(phrase), salles);
    fosse = atoi(phrase);

    printf("Nombre de rangées: %d\nNombre de places: %d\nCatégorie A: %d\nCatégorie B: %d\nCatégorie C: %d\nFosse: %d\n", nbr_rangees, nbr_places, cat_a, cat_b, cat_c, fosse);

                      //Entête
    //clrscr();
    printf("       Plan de la salle :  \n");
    printf("            SCENE           \n");
    printf("-------------------------------\n");








/*  Mise en page du fichier txt

Nom de la salle: ...
Est-ce que la salle est utilisée ?: ...
Nombre de rangée: ...
Nombre de siège par rangée: ...
Nombre de siège de catégorie A: ...
Nombre de siège de catégorie B: ...
Nombre de siège de catégorie C: ...
Est-ce qu'il y a une fosse ?: ...
Prix de la catégorie A: ...
Prix de la catégorie B: ...
Prix de la catégorie C: ...

*/

    fclose(salles);

    }



int main(){
    
    clrscr();            // Efface tout du terminal

    couleur("44");       // Initialise la couleur

    printf("Salut\n");

    couleur("0");        // Couleur par defaut   /!\ Tres important

    //On réinitialise tout les fichiers

    char* fichiersalle="salle.txt";
    FILE* fichier =fopen(fichiersalle,"w");
    if(fichier==NULL){
        printf("Erreur lors de l'ouverture du fichier %s\n", fichiersalle);
        exit(1);
    }

    fclose(fichier);

    // choix();

    Salle salle=creerSalle();
    Salle salle2=creerSalle();
    afficheSalle2("Test");

		//alessio le goat
    return 0;
}

/*

- Separer les fonctoin : Gabin
- Mode/role : Romain
- Affichage : Sam
- Fichier de salles : Sam/Gabin
- Fonction de modif de salle : Tous
- Reservation de place : Tous

*/