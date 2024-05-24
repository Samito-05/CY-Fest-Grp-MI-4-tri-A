#include "bibli.h"




void mode(){ 
    libererSalle();
    int mode;
    int cle;
    int i = 0;

    printf("Que voulez-vous faire ?\n1. Gerer le festival (mode manageur)\t2. Reserver des places (mode festivalier)\t3.sortir du programme\n");
    int verif=0, verif2=0;
    char c;
    do{
        verif=scanf("%d",&mode);
        do{
            verif2=scanf("%c",&c);
        }while(verif2 == 1 && c!='\n');
        if (verif != 1 || mode<1 || mode>3){
            printf("saisie invalide\n");
        }

    } while (verif != 1 || mode<1 || mode>3);
    verif=0;
    verif2=0;

    

    if (mode == 1)
    {
        // Vérification de la clé d'accès pour le mode manageur
        while (cle != 123456 && i < 3){
            printf("Entrez la cle d'acces : ");
            do{
                verif=scanf("%d",&cle);
                do{
                    verif2=scanf("%c",&c);
                }while(verif2 == 1 && c!='\n');
                if (verif != 1 || cle<99999 || cle>1000000){
                printf("saisie invalide\n");
                }
            } while (verif != 1 || cle<99999 || cle>1000000);
            verif=0;
             verif2=0;
            if (cle != 123456){
                i++;
                printf("Code errone. Plus que %d tentative(s).\n", 3 - i);
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
}


void festival(){
    libererSalle();
    int festivalier;
    printf("Que voulez vous faire ?\n1.reserver une place\t2.annuler une reservation\t3.afficher les salles de concert\t4.retour au choix du mode\n"); // ecris tout les choix de manageur
    int verif=0, verif2=0;
    char g;
    do{
        verif=scanf("%d",&festivalier);
        do{
            verif2=scanf("%c",&g);
        }while(verif2 == 1 && g!='\n');
        if (verif != 1 || festivalier<1 || festivalier>4){
            printf("saisie invalide\n");
        }
    } while (verif != 1 || festivalier<1 || festivalier>4);
    verif=0;
    verif2=0;
    clrscr();
    
    
    if (festivalier == 1){
        int r,c,n;
        char salle[21];
        listeSallef(); 
        printf("Quel est le nom de la salle ? (20 caracteres maximum)\n");
        scanf("%20s", salle);
        clrscr();
        veriff(salle);
        clrscr();
        afficheSalle(salle);
        printf("Quelle rangee ?\n");
        do{
            verif=scanf("%d",&r);
            do{
                verif2=scanf("%c",&g);
            }while(verif2 == 1 && g!='\n');  
            if (verif != 1 || r<0 ){
            printf("saisie invalide\n");
            }

        } while (verif != 1 ||r<0);
        verif=0;
        verif2=0; 
        clrscr();
        afficheSalle(salle);
        printf("Quelle colonne ?\n");
        do{
            verif=scanf("%d",&c);
            do{
                verif2=scanf("%c",&g);
            }while(verif2 == 1 && g!='\n');
            if (verif != 1 || c<0 ){
            printf("saisie invalide\n");
            }

        } while (verif != 1 ||c<0);
        verif=0;
        verif2=0; 
        clrscr();
        reserverSalle(salle,r,c);
        afficheSalle(salle);
        festival();
    }
    clrscr();
    
    
    
    if (festivalier == 2)
    {
        int r,c,n;
        char salle[21];
        listeSallef(); 
        printf("Quel est le nom de la salle ? (20 caracteres maximum)\n");
        scanf("%20s", salle);
        clrscr();
        veriff(salle);
        clrscr();
        afficheSalle(salle);
        printf("Quelle rangee ?\n");
        do{
            verif=scanf("%d",&r);
            do{
                verif2=scanf("%c",&g);
            }while(verif2 == 1 && g!='\n');  
            if (verif != 1 || r<0 ){
            printf("saisie invalide\n");
            }

        } while (verif != 1 ||r<0);
        verif=0;
        verif2=0; 
        clrscr();
        afficheSalle(salle);
        printf("Quelle colonne ?\n");
        do{
            verif=scanf("%d",&c);
            do{
                verif2=scanf("%c",&g);
            }while(verif2 == 1 && g!='\n');
            if (verif != 1 || c<0 ){
            printf("saisie invalide\n");
            }

        } while (verif != 1 ||c<0);
        verif=0;
        verif2=0; 
        clrscr();
        remboursement(salle,r,c);
        afficheSalle(salle);
        festival();
    
        festival();
    }

    if (festivalier==3){
      char salle[21];
      listeSallef();
      printf("Quel est le nom de la salle ? (20 caracteres maximum)\n");
      scanf("%20s", salle);
      clrscr();
      veriff(salle);
      afficheSalle(salle);
      festival();
    }

    if (festivalier == 4)
    {
        clrscr();
        mode();
    }
}

void manage()
{ // oublier pas d apppeler la fonction a la fin de chaque action majeur
    libererSalle();
    int manageur;
    printf("Que voulez vous faire ?\n1.ajouter une salle\t2.modifier une salle\t3.supprimer une salle\t4.creer un concert\t5.afficher une salle\t6.retour au choix du mode\n"); // ecris tout les choix de manageur
    int verif=0, verif2=0;
    char c;
    
    do{
        verif=scanf("%d",&manageur);
        do{
            verif2=scanf("%c",&c);
        }while(verif2 == 1 && c!='\n');
        if (verif != 1 || manageur<1 || manageur>6){
            printf("saisie invalide\n");
        }
  
    } while (verif != 1 || manageur<1 || manageur>6);
    verif=0;
    verif2=0;
    if (manageur == 1)
    {
        creerSalle();
        manage();
    }
    else if (manageur == 2)
    {
      int n;
      char salle[21];
      listeSallem();
      printf("Quel est le nom de la salle ? (20 caracteres maximum)\n");
      scanf("%20s", salle);
      clrscr();
      verifm(salle);
      clrscr();
      modifierSalle(salle);
      manage();
    }
    else if (manageur == 3)
    {
      char salle[21];
      listeSalle();
      printf("Quel est le nom de la salle ? (20 caracteres maximum)\n");
      scanf("%20s", salle);
      clrscr();
      verifm(salle);
      clrscr();
      supprimerSalle(salle);
      manage();
    }
    else if (manageur == 4)
    {
        clrscr();
        listeSallem();
        creerConcert();
        manage();
    }
    else if (manageur==5){
      char salle[21];
      listeSalle();
      printf("Quel est le nom de la salle ? (20 caracteres maximum)\n");
      scanf("%20s", salle);
      clrscr();
      afficheSalle(salle);
      manage();
    }

    else if (manageur == 6)
    {
        clrscr();
        mode();
    }
}



int main(){
    clrscr();
    mode();
    return 0;
}
