#include "couleurs.h"
#include "mode.h"
#include "festivalier.h"
#include "manageur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mode();
void manageur();
void afficheSalle();
void festivalier();


void mode()
{ // j ai mis des clear screen mais si vous trouver que y en a pas assez vous pouvez en rajouter
    int mode;
    int cle;
    int i = 0;

    printf("Que voulez-vous faire ?\n1. Gérer le festival (mode manageur)\t2. Réserver des places (mode festivalier)\t3.sortir du programme\n");
    scanf("%d", &mode);

    while (mode < 1 || mode > 3)
    {
        printf("Erreur : la valeur saisie doit être entre 1 et 2.\n");
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
        printf("reserve\n");
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
        mode();
    }
}

void manage()
{ // oublier pas d apppeler la fonction a la fin de chaque action majeur
    int manageur;
    printf("que voulez vous faire ?\n1.ajouter une salle\t2.modifier une salle(pas encore créé)\t3.supprimer une salle(pas encore créé)\t4.retour au choix du mode\n"); // ecris tout les choix de manageur
    scanf("%d", &manageur);
    while (manageur < 1 || manageur > 6)
    {
        printf("erreur la valeur saisie doit être entre 1 et 2\n");
        scanf("%d", &manageur);
    }
    if (manageur == 1)
    {
        Salle salle = creerSalle();
        afficheSalle(salle);
        salle_txt(salle);
        manage();
    }
    else if (manageur == 2)
    {
        printf("modifier\n");
        manage();
    }
    else if (manageur == 3)
    {
        printf("supprimer\n");
        manage();
    }
    else if (manageur == 4)
    {
        clrscr();
        mode();
    }
}

int main()
{

    clrscr(); // Efface tout du terminal

    couleur("44"); // Initialise la couleur

    printf("Salut\n");

    couleur("0"); // Couleur par defaut   /!\ Tres important

    // On réinitialise tout les fichiers

    char *fichiersalle = "salle.txt";
    FILE *fichier = fopen(fichiersalle, "w");
    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier %s\n", fichiersalle);
        exit(1);
    }

    fclose(fichier);

    mode();

    // Salle salle=creerSalle();

    // afficheSalle2("Test");

    return 0;
}

/*

- Separer les fonctoin : Sam
- Mode/role : Romain
- Affichage : Sam
- Fichier de salles : Sam/Gabin
- Fonction de modif de salle : Tous
- Reservation de place : Tous

*/