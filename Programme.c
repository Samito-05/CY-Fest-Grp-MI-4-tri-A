#include "bibli.h"




void choix()
{ // j ai mis des clear screen mais si vous trouver que y en a pas assez vous pouvez en rajouter
    int mode;
    int cle;
    int i = 0;

    printf("Que voulez-vous faire ?\n1. Gérer le festival (mode manageur)\t2. Réserver des places (mode festivalier)\t3.sortir du programme\n");
    scanf("%d", &mode);

    while (mode < 1 || mode > 3)
    {
        printf("Erreur : la valeur saisie doit être entre 1 et 3.\n");
        scanf("%d", &mode);
    }

    if (mode == 1)
    {
        // Vérification de la clé d'accès pour le mode manageur
        while (cle != 123456 && i < 3)
        {
            printf("Entrez la clé d'accès : ");
            scanf("%d", &cle);
            if (cle != 123456)
            {
                i++;
                printf("Code erroné. Plus que %d tentative(s).\n", 3 - i);
                if (i == 3)
                {
                    printf("Nombre maximum de tentatives atteint. Sortie du programme.\n");
                    clrscr();
                    exit(1); // si on se troupe 3 fois on sort du programe
                }
            }
        }
        clrscr();
        manage();
    }
    else if (mode == 2)
    {
        clrscr();
        festival();
    }
    else if (mode == 3)
    {
        exit(1);
    }
    else {
      printf("erreur dans la saisie");
      choix();
    }
}

void festival()
{
    int festivalier;
    printf("que voulez vous faire ?\n1.reserver une place\t2.annuler une reservation\t3.retour au choix du mode\n"); // ecris tout les choix de manageur
    scanf("%d", &festivalier);
    while (festivalier < 1 || festivalier > 6)
    {
        printf("erreur la valeur saisie doit être entre 1 et 2\n");
        scanf("%d", &festivalier);
    }
    if (festivalier == 1)
    {
        int r,c,n;
        char* salle;
          
        printf("Combien de lettres contient le nom de la salle ?\n");
        scanf("%d", &n);
        clrscr();
        salle = (char *)malloc(sizeof(char) * (n + 1));
        if (salle == NULL) {
          printf("Erreur de nom\n");
          exit(1);
        }
        printf("Quel est le nom de la salle ?\n");
        scanf("%s", salle);
        clrscr();
        printf("Quelle rangée ?\n");
        scanf("%d",&r);
        clrscr();
        printf("Quelle colonne ?\n");
        scanf("%d",&c);
        clrscr();
        reserverSalle(salle,r,c);
        afficheSalle(salle);
        festival();
    }
    if (festivalier == 1)
    {
        printf("remboursement\n");
        festival();
    }
    if (festivalier == 3)
    {
        clrscr();
        choix();
    }
        else {
      printf("erreur dans la saisie");
      festival();
    }
}

void manage()
{ // oublier pas d apppeler la fonction a la fin de chaque action majeur
    int manageur;
    printf("que voulez vous faire ?\n1.ajouter une salle\t2.modifier une salle\t3.supprimer une salle\t4.retour au choix du mode\n"); // ecris tout les choix de manageur
    scanf("%d", &manageur);
    while (manageur < 1 || manageur > 6)
    {
        printf("erreur la valeur saisie doit être entre 1 et 2\n");
        scanf("%d", &manageur);
    }
    if (manageur == 1)
    {
        creerSalle();
        manage();
    }
    else if (manageur == 2)
    {
      int n;
      char* salle;
      printf("Combien de lettres contient le nom de la salle ?\n");
      scanf("%d", &n);
      clrscr();
      salle = (char *)malloc(sizeof(char) * (n + 1));
      if (salle == NULL) {
        printf("Erreur de nom\n");
        exit(1);
      }
      printf("Quel est le nom de la salle ?\n");
      scanf("%s", salle);
      clrscr();
      modifierSalle(salle);
      manage();
    }
    else if (manageur == 3)
    {
      int n;
      char* salle;
      printf("Combien de lettres contient le nom de la salle ?\n");
      scanf("%d", &n);
      clrscr();
      salle = (char *)malloc(sizeof(char) * (n + 1));
      if (salle == NULL) {
        printf("Erreur de nom\n");
        exit(1);
      }
      printf("Quel est le nom de la salle ?\n");
      scanf("%s", salle);
      clrscr();
      supprimerSalle(salle);
      manage();
    }
    else if (manageur == 4)
    {
        clrscr();
        choix();
    }
        else {
      printf("erreur dans la saisie");
      manage();
    }
}



int main()
{
/*FILE* salles = fopen("salle.txt", "w");
  if (salles == NULL) {
      exit(1);
  }
  fclose(salles);*/
  clrscr();
  choix();
  return 0;
}