#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure pour représenter un siège
typedef struct {
    int numero;
    char categorie;
    int est_reserve;
} Siege;

// Définition de la structure pour représenter une salle de concert
typedef struct {
    char nom[50];
    int nombre_rangees;
    int* sieges_par_rangee;
    Siege** sieges;
} SalleConcert;

// Fonction pour créer une nouvelle salle de concert
SalleConcert* creerSalleConcert(const char* nom, int nombre_rangees, int* sieges_par_rangee) {
    SalleConcert* salle = (SalleConcert*)malloc(sizeof(SalleConcert));
    if (salle == NULL) {
        printf("Erreur lors de l'allocation de mémoire pour la salle de concert.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(salle->nom, nom);
    salle->nombre_rangees = nombre_rangees;
    salle->sieges_par_rangee = sieges_par_rangee;
    salle->sieges = (Siege**)malloc(nombre_rangees * sizeof(Siege*));
    if (salle->sieges == NULL) {
        printf("Erreur lors de l'allocation de mémoire pour les sièges de la salle de concert.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < nombre_rangees; i++) {
        salle->sieges[i] = (Siege*)malloc(sieges_par_rangee[i] * sizeof(Siege));
        if (salle->sieges[i] == NULL) {
            printf("Erreur lors de l'allocation de mémoire pour les sièges de la rangée %d.\n", i + 1);
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < sieges_par_rangee[i]; j++) {
            salle->sieges[i][j].numero = j + 1;
            salle->sieges[i][j].categorie = 'A'; // Par défaut, tous les sièges sont de catégorie A
            salle->sieges[i][j].est_reserve = 0; // Par défaut, aucun siège n'est réservé
        }
    }
    return salle;
}

// Fonction pour libérer la mémoire allouée pour une salle de concert
void libererSalleConcert(SalleConcert* salle) {
    for (int i = 0; i < salle->nombre_rangees; i++) {
        free(salle->sieges[i]);
    }
    free(salle->sieges);
    free(salle);
}

// Fonction pour afficher le plan d'une salle de concert
void afficherPlanSalle(SalleConcert* salle) {
    printf("Plan de la salle de concert \"%s\":\n", salle->nom);
    for (int i = 0; i < salle->nombre_rangees; i++) {
        printf("Rangée %d :", i + 1);
        for (int j = 0; j < salle->sieges_par_rangee[i]; j++) {
            printf(" Siège %d (%c) ", salle->sieges[i][j].numero, salle->sieges[i][j].categorie);
            if (salle->sieges[i][j].est_reserve) {
                printf("[Réservé] ");
            } else {
                printf("[Libre] ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Exemple de création d'une salle de concert
    int sieges_par_rangee[] = {10, 15, 20}; // Nombre de sièges par rangée
    SalleConcert* salle = creerSalleConcert("Salle A", 3, sieges_par_rangee);
    
    // Exemple d'affichage du plan de la salle de concert
    afficherPlanSalle(salle);
    
    // Libération de la mémoire allouée pour la salle de concert
    libererSalleConcert(salle);
    
    return 0;
}
