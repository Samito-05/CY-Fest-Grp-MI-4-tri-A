#include "couleurs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void creerSalle() {
  int concert, nrangee, nsiege, nsiegeA, nsiegeB, nsiegeC, fosse, n = 0;
  char* nomsalle= NULL;
  float prixA, prixB, prixC;

  concert = 0; // On initialise la salle comme non occupé

  printf("Combien de lettres contient le nom de la salle ?\n");
  scanf("%d", &n);
  clrscr();

  nomsalle = (char *)malloc(sizeof(char) * (n + 1));
  if (nomsalle == NULL) {
    printf("Erreur de nom\n");
    exit(1);
  }
  printf("Quel est le nom de la salle ?\n");
  scanf("%s", nomsalle);
  clrscr();


  FILE *salles = fopen("salle.txt", "r");
  if (salles == NULL) {
    exit(1);
  }

  char phrase[50];
  int trouve = 0;

  // Lire ligne par ligne jusqu'à la fin du fichier
  while (fgets(phrase, sizeof(phrase), salles) != NULL) {
    // Vérification de la bonne salle
    if (strstr(phrase, nomsalle) != NULL) {
      printf("La salle existe déjà.\n");
      return;
    }
  }


  printf("Combien y a t-il de rangée ?\n");
  scanf("%d", &nrangee);
  clrscr();

  while (nrangee < 1) {
    printf("Erreur, nombre de rangée non valide. Réessayez.\n");
    scanf("%d", &nrangee);
    clrscr();
  }

  printf("Combien y a t-il de siège par rangée ?\n");
  scanf("%d", &nsiege);
  clrscr();

  while (nsiege < 1) {
    printf("Erreur, nombre de siege par rangée non valide. Réessayez.\n");
    scanf("%d", &nsiege);
    clrscr();
  }

  // On demande le nombre de siège par catégorie
  printf("Combien y a t-il de rangée de catégorie A ?\n");
  scanf("%d", &nsiegeA);
  nsiegeA *=nsiege; // On fait ranger de Catégorie A * nombre de siège par rangée
  clrscr();

  while (nsiegeA < 0) {
    printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
    scanf("%d", &nsiegeA);
    nsiegeA *= nsiege;
    clrscr();
  }

  printf("Combien y a t-il de rangée de catégorie B ?\n");
  scanf("%d", &nsiegeB);
  nsiegeB *= nsiege;

  while (nsiegeB < 0) {
    printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
    scanf("%d", &nsiegeB);
    nsiegeB *= nsiege;
    clrscr();
  }

  nsiegeC =nsiege * nrangee - (nsiegeA + nsiegeB);
  clrscr();
  if (nsiegeC < 0) {
    nsiegeC = 0;
  }

  while ((nsiegeA + nsiegeB + nsiegeC) !=(nsiege *nrangee)) { // Si la somme des sièges des 3 catégories ne sont pas égales au nombre de siège total on recommence le scan
    printf("Il y a une erreur dans l'affectation des sièges, veuillez "
           "réessayer\n");

    printf("Combien y a t-il de rangée de catégorie A ?\n");
    scanf("%d", &nsiegeA);
    clrscr();
    nsiegeA *= nsiege; // On fais rangée de Catégorie A * nombre de
                                   // siège par rangée
    while (nsiegeA < 0) {
      printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
      scanf("%d", &nsiegeA);
      nsiegeA *= nsiege;
      clrscr();
    }

    printf("Combien y a t-il de rangée de catégorie B ?\n");
    scanf("%d", &nsiegeB);
    nsiegeB *= nsiege;
    clrscr();
    while (nsiegeB < 0) {
      printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
      scanf("%d", &nsiegeB);
      nsiegeB *= nsiege;
      clrscr();
    }

    nsiegeC = nsiege * nrangee - (nsiegeA + nsiegeB);
    clrscr();
    if (nsiegeC < 0) {
      nsiegeC = 0;
    }
  }

  printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
  scanf("%d", &fosse);
  clrscr();
  while (fosse != 1 && fosse != 0) {
    printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
    scanf("%d", &fosse);
    clrscr();
  }

  if (fosse ==1) { // Si il y a une fosse on double le nombre de place en catégorie A
    nrangee += nsiegeA / nsiege;
    nsiegeA += nsiegeA;

    printf("Quel est le prix d'une place en fosse ?\n");
    scanf("%f", &prixA);
    clrscr();
    while (prixA < 0) {
      printf("Quel est le prix d'une place en fosse ?\n");
      scanf("%f", &prixA);
      clrscr();
    }
  }
  // On demande le prix de chaque catégorie
  else {
    printf("Quel est le prix d'une place de catégorie A ?\n");
    scanf("%f", &prixA);
    clrscr();

    while (prixA < 0) {
      printf("Quel est le prix d'une place de catégorie A ?\n");
      scanf("%f", &prixA);
      clrscr();
    }
  }

  printf("Quel est le prix d'une place de catégorie B ?\n");
  scanf("%f", &prixB);
  clrscr();

  while (prixB < 0) {
    printf("Quel est le prix d'une place de catégorie B ?\n");
    scanf("%f", &prixB);
    clrscr();
  }

  printf("Quel est le prix d'une place de catégorie C ?\n");
  scanf("%f", &prixC);
  clrscr();

  while (prixC < 0) {
    printf("Quel est le prix d'une place de catégorie C ?\n");
    scanf("%f", &prixC);
    clrscr();
  }

  char *fichiersalle = "salle.txt";
  FILE *fichier = fopen(fichiersalle, "a+");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", fichiersalle);
    exit(1);
  }
  fprintf(fichier, "%s : Nom de la salle\n", nomsalle);
  fprintf(fichier, "%d : Est-ce que la salle est utilisée ?\n", concert);
  fprintf(fichier, "%d : Nombre de rangée\n", nrangee);
  fprintf(fichier, "%d : Nombre de siège par rangée\n", nsiege);
  fprintf(fichier, "%d : Nombre de siège de catégorie A\n", nsiegeA);
  fprintf(fichier, "%d : Nombre de siège de catégorie B\n", nsiegeB);
  fprintf(fichier, "%d : Nombre de siège de catégorie C\n", nsiegeC);
  fprintf(fichier, "%d : Est-ce qu'il y a une fosse ?\n", fosse);
  fprintf(fichier, "%.2f : Prix de la catégorie A\n", prixA);
  fprintf(fichier, "%.2f : Prix de la catégorie B\n", prixB);
  fprintf(fichier, "%.2f : Prix de la catégorie C\n", prixC);

  for (int i = 0; i < nsiegeA / nsiege; i++) {
    for (int j = 0; j < nsiege - 1; j++) {
      fprintf(fichier, "O");
      fprintf(fichier, " ");
    }
    fprintf(fichier, "O");
    fprintf(fichier, "\n");
  }
  for (int i = 0; i < nsiegeB / nsiege; i++) {
    for (int j = 0; j < nsiege - 1; j++) {
      fprintf(fichier, "O");
      fprintf(fichier, " ");
    }
    fprintf(fichier, "O");
    fprintf(fichier, "\n");
  }
  for (int i = 0; i < nsiegeC / nsiege; i++) {
    for (int j = 0; j < nsiege - 1; j++) {
      fprintf(fichier, "O");
      fprintf(fichier, " ");
    }
    fprintf(fichier, "O");
    fprintf(fichier, "\n");
  }

  fclose(fichier);
  free(nomsalle);
  printf("La salle a bien été créé.\n");
}

























void afficheSalle(char *nom_salle) {
  char *nom = "salle.txt";
  int r = 1;

  // ouvrir le fichier
  FILE *salles = fopen(nom, "r");
  if (salles == NULL) {
    exit(1);
  }

  char phrase[50];
  int trouve = 0;

  // Lire ligne par ligne jusqu'à la fin du fichier
  while (fgets(phrase, sizeof(phrase), salles) != NULL) {
    // Vérification de la bonne salle
    if (strstr(phrase, nom_salle) != NULL) {
      // printf("La salle existe.\n");
      trouve = 1;
      break;
    }
  }

  // Vérifier si la fin du fichier est atteinte sans trouver la salle
  if (!trouve) {
    printf("La salle n'a pas été trouvée.\n");
    fclose(salles);
    return;
  }

  // Reccuperation de données de la salle

  int nbr_places, cat_a, cat_b, cat_c;

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);
  nbr_places = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);
  cat_a = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);
  cat_b = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);
  cat_c = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);

  // printf("Nombre de rangées: %d\nNombre de places: %d\nCatégorie A:
  // %d\nCatégorie B: %d\nCatégorie C: %d\nFosse: %d\n", nbr_rangees,
  // nbr_places, cat_a, cat_b, cat_c, fosse);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);

  // Entête
  // clrscr();
  printf("       Plan de la salle :  \n");
  printf("            SCENE           \n");
  printf("-------------------------------\n");
  for (int i = 0; i < cat_a / nbr_places; i++) {
    printf("R %d ", r);
    // Affichez le plan pour chaque rangée ici
    for (int j = 0; j < nbr_places * 2; j++) {
      char a = fgetc(salles);
      if (a == 'O') {
        couleur("36");
        printf("%c", a);
        couleur("0");
      } else if (a == 'X') {
        couleur("31");
        printf("%c", a);
        couleur("0");
      } else {
        printf("%c", a);
      }
    }
    r++;
  }

  for (int i = 0; i < cat_b / nbr_places; i++) {
    printf("R %d ", r);
    // Affichez le plan pour chaque rangée ici
    for (int j = 0; j < nbr_places * 2; j++) {
      char a = fgetc(salles);
      if (a == 'O') {
        couleur("33");
        printf("%c", a);
        couleur("0");
      } else if (a == 'X') {
        couleur("31");
        printf("%c", a);
        couleur("0");
      } else {
        printf("%c", a);
      }
    }
    r++;
  }

  for (int i = 0; i < cat_c / nbr_places; i++) {
    printf("R %d ", r);
    // Affichez le plan pour chaque rangée ici
    for (int j = 0; j < nbr_places * 2; j++) {
      char a = fgetc(salles);
      if (a == 'O') {
        couleur("37");
        printf("%c", a);
        couleur("0");
      } else if (a == 'X') {
        couleur("31");
        printf("%c", a);
        couleur("0");
      } else {
        printf("%c", a);
      }
    }
    r++;
  }

  printf("-------------------------------\n");

  printf("\nLégende\n");
  couleur("36");
  printf("O : Categorie 1 / Fosse\n");
  couleur("33");
  printf("O : Categorie 2\n");
  couleur("37");
  printf("O : Categorie 3\n");
  couleur("0");

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

















































void reserverSalle(char *salle, int y, int x) {
  char *nom = "salle.txt";

  // ouvrir le fichier
  FILE *salles = fopen(nom, "r+");
  if (salles == NULL) {
    exit(1);
  }

  char phrase[50];
  int trouve = 0;

  // Lire ligne par ligne jusqu'à la fin du fichier
  while (fgets(phrase, sizeof(phrase), salles) != NULL) {
    // Vérification de la bonne salle
    if (strstr(phrase, salle) != NULL) {
      trouve = 1;
      break;
    }
  }

  // Vérifier si la fin du fichier est atteinte sans trouver la salle
  if (!trouve) {
    printf("La salle n'a pas été trouvée.\n");
    fclose(salles);
    return;
  }

  // Reccuperation de données de la salle

  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);
  fgets(phrase, sizeof(phrase), salles);

  for (int i = 1; i < y; i++) {
    fgets(phrase, sizeof(phrase), salles);
  }
  int position = (x - 1) * 2;

  // Se déplacer à la position désirée dans le fichier
  fseek(salles, position, SEEK_CUR);
  // Écrire 'X' à la position désirée dans le fichier
  fputc('X', salles);
  fclose(salles);
}
































void modifierSalle(char *nom_salle) {
  // ouvrir le fichier
  FILE *salles = fopen("salle.txt", "r");
  if (salles == NULL) {
    exit(1);
  }

  FILE *modif = fopen("modif.txt", "w");
  if (modif == NULL) {
    exit(1);
  }

  char phrase[50];
  int trouve = 0;

  // Lire ligne par ligne jusqu'à la fin du fichier
  while (fgets(phrase, sizeof(phrase), salles) != NULL) {
    // Vérification de la bonne salle
    if (strstr(phrase, nom_salle) != NULL) {
      // printf("La salle existe.\n");
      trouve = 1;
      break;
    }
  }

  // Vérifier si la fin du fichier est atteinte sans trouver la salle
  if (!trouve) {
    printf("La salle n'a pas été trouvée.\n");
    fclose(salles);
    return;
  }

  rewind(salles);

  while (strstr(fgets(phrase, sizeof(phrase), salles), nom_salle) == NULL) {
    fprintf(modif, "%s", phrase);
  }

  // Reccuperation de données de la salle

  int nbr_rangees;

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);
  nbr_rangees = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  for (int i = 0; i < nbr_rangees; i++) {
    fgets(phrase, sizeof(phrase), salles);
  }

  while (fgets(phrase, sizeof(phrase), salles) != NULL) {
    fprintf(modif, "%s", phrase);
  }
  fclose(salles);
  fclose(modif);
  ///////////////////////////////////
  int concert, nrangee, nsiege, nsiegeA, nsiegeB, nsiegeC, fosse;
  char* nomsalle= nom_salle;
  float prixA, prixB, prixC;

  concert = 0; // On initialise la salle comme non occupé

  printf("Combien y a t-il de rangée ?\n");
  scanf("%d", &nrangee);
  clrscr();

  while (nrangee < 1) {
    printf("Erreur, nombre de rangée non valide. Réessayez.\n");
    scanf("%d", &nrangee);
    clrscr();
  }

  printf("Combien y a t-il de siège par rangée ?\n");
  scanf("%d", &nsiege);
  clrscr();

  while (nsiege < 1) {
    printf("Erreur, nombre de siege par rangée non valide. Réessayez.\n");
    scanf("%d", &nsiege);
    clrscr();
  }

  // On demande le nombre de siège par catégorie
  printf("Combien y a t-il de rangée de catégorie A ?\n");
  scanf("%d", &nsiegeA);
  nsiegeA *=nsiege; // On fait ranger de Catégorie A * nombre de siège par rangée
  clrscr();

  while (nsiegeA < 0) {
    printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
    scanf("%d", &nsiegeA);
    nsiegeA *= nsiege;
    clrscr();
  }

  printf("Combien y a t-il de rangée de catégorie B ?\n");
  scanf("%d", &nsiegeB);
  nsiegeB *= nsiege;

  while (nsiegeB < 0) {
    printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
    scanf("%d", &nsiegeB);
    nsiegeB *= nsiege;
    clrscr();
  }

  nsiegeC =nsiege * nrangee - (nsiegeA + nsiegeB);
  clrscr();
  if (nsiegeC < 0) {
    nsiegeC = 0;
  }

  while ((nsiegeA + nsiegeB + nsiegeC) !=(nsiege *nrangee)) { // Si la somme des sièges des 3 catégories ne sont pas égales au nombre de siège total on recommence le scan
    printf("Il y a une erreur dans l'affectation des sièges, veuillez "
           "réessayer\n");

    printf("Combien y a t-il de rangée de catégorie A ?\n");
    scanf("%d", &nsiegeA);
    clrscr();
    nsiegeA *= nsiege; // On fais rangée de Catégorie A * nombre de
                                   // siège par rangée
    while (nsiegeA < 0) {
      printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
      scanf("%d", &nsiegeA);
      nsiegeA *= nsiege;
      clrscr();
    }

    printf("Combien y a t-il de rangée de catégorie B ?\n");
    scanf("%d", &nsiegeB);
    nsiegeB *= nsiege;
    clrscr();
    while (nsiegeB < 0) {
      printf("Erreur, nombre de rangée pour cette catégorie. Réessayez.\n");
      scanf("%d", &nsiegeB);
      nsiegeB *= nsiege;
      clrscr();
    }

    nsiegeC = nsiege * nrangee - (nsiegeA + nsiegeB);
    clrscr();
    if (nsiegeC < 0) {
      nsiegeC = 0;
    }
  }

  printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
  scanf("%d", &fosse);
  clrscr();
  while (fosse != 1 && fosse != 0) {
    printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
    scanf("%d", &fosse);
    clrscr();
  }

  if (fosse ==1) { // Si il y a une fosse on double le nombre de place en catégorie A
    nrangee += nsiegeA / nsiege;
    nsiegeA += nsiegeA;

    printf("Quel est le prix d'une place en fosse ?\n");
    scanf("%f", &prixA);
    clrscr();
    while (prixA < 0) {
      printf("Quel est le prix d'une place en fosse ?\n");
      scanf("%f", &prixA);
      clrscr();
    }
  }
  // On demande le prix de chaque catégorie
  else {
    printf("Quel est le prix d'une place de catégorie A ?\n");
    scanf("%f", &prixA);
    clrscr();

    while (prixA < 0) {
      printf("Quel est le prix d'une place de catégorie A ?\n");
      scanf("%f", &prixA);
      clrscr();
    }
  }

  printf("Quel est le prix d'une place de catégorie B ?\n");
  scanf("%f", &prixB);
  clrscr();

  while (prixB < 0) {
    printf("Quel est le prix d'une place de catégorie B ?\n");
    scanf("%f", &prixB);
    clrscr();
  }

  printf("Quel est le prix d'une place de catégorie C ?\n");
  scanf("%f", &prixC);
  clrscr();

  while (prixC < 0) {
    printf("Quel est le prix d'une place de catégorie C ?\n");
    scanf("%f", &prixC);
    clrscr();
  }

  char *fichiersalle = "salle.txt";
  FILE *fichier = fopen(fichiersalle, "w");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", fichiersalle);
    exit(1);
  }
  fprintf(fichier, "%s : Nom de la salle\n", nomsalle);
  fprintf(fichier, "%d : Est-ce que la salle est utilisée ?\n", concert);
  fprintf(fichier, "%d : Nombre de rangée\n", nrangee);
  fprintf(fichier, "%d : Nombre de siège par rangée\n", nsiege);
  fprintf(fichier, "%d : Nombre de siège de catégorie A\n", nsiegeA);
  fprintf(fichier, "%d : Nombre de siège de catégorie B\n", nsiegeB);
  fprintf(fichier, "%d : Nombre de siège de catégorie C\n", nsiegeC);
  fprintf(fichier, "%d : Est-ce qu'il y a une fosse ?\n", fosse);
  fprintf(fichier, "%.2f : Prix de la catégorie A\n", prixA);
  fprintf(fichier, "%.2f : Prix de la catégorie B\n", prixB);
  fprintf(fichier, "%.2f : Prix de la catégorie C\n", prixC);

  for (int i = 0; i < nsiegeA / nsiege; i++) {
    for (int j = 0; j < nsiege - 1; j++) {
      fprintf(fichier, "O");
      fprintf(fichier, " ");
    }
    fprintf(fichier, "O");
    fprintf(fichier, "\n");
  }
  for (int i = 0; i < nsiegeB / nsiege; i++) {
    for (int j = 0; j < nsiege - 1; j++) {
      fprintf(fichier, "O");
      fprintf(fichier, " ");
    }
    fprintf(fichier, "O");
    fprintf(fichier, "\n");
  }
  for (int i = 0; i < nsiegeC / nsiege; i++) {
    for (int j = 0; j < nsiege - 1; j++) {
      fprintf(fichier, "O");
      fprintf(fichier, " ");
    }
    fprintf(fichier, "O");
    fprintf(fichier, "\n");
  }

  fclose(fichier);
  free(nomsalle);

  salles = fopen("salle.txt", "a+");
  if (salles == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", "salle.txt");
    exit(1);
  }

  modif = fopen("modif.txt", "r");
  if (salles == NULL) {
    exit(1);
  }

  while (fgets(phrase, sizeof(phrase), modif)) {
    fprintf(salles, "%s", phrase);
  }
  fclose(salles);
  fclose(modif);
}











































void supprimerSalle(char *nom_salle) {
  // ouvrir le fichier
  FILE *salles = fopen("salle.txt", "r");
  if (salles == NULL) {
    exit(1);
  }

  FILE *modif = fopen("modif.txt", "w");
  if (modif == NULL) {
    exit(1);
  }

  char phrase[50];
  int trouve = 0;

  // Lire ligne par ligne jusqu'à la fin du fichier
  while (fgets(phrase, sizeof(phrase), salles) != NULL) {
    // Vérification de la bonne salle
    if (strstr(phrase, nom_salle) != NULL) {
      // printf("La salle existe.\n");
      trouve = 1;
      break;
    }
  }

  // Vérifier si la fin du fichier est atteinte sans trouver la salle
  if (!trouve) {
    printf("La salle n'a pas été trouvée.\n");
    fclose(salles);
    return;
  }

  rewind(salles);

  while (strstr(fgets(phrase, sizeof(phrase), salles), nom_salle) == NULL) {
    fprintf(modif, "%s", phrase);
  }

  // Reccuperation de données de la salle

  int nbr_rangees;

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);
  nbr_rangees = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);

  for (int i = 0; i < nbr_rangees; i++) {
    fgets(phrase, sizeof(phrase), salles);
  }

  while (fgets(phrase, sizeof(phrase), salles) != NULL) {
    fprintf(modif, "%s", phrase);
  }
  fclose(salles);
  fclose(modif);

  salles = fopen("salle.txt", "w");
  if (salles == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", "salle.txt");
    exit(1);
  }

  modif = fopen("modif.txt", "r");
  if (salles == NULL) {
    exit(1);
  }

  while (fgets(phrase, sizeof(phrase), modif)) {
    fprintf(salles, "%s", phrase);
  }
  fclose(salles);
  fclose(modif);
  printf("Salle bien supprimer\n");
}



































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































int main() {
  /*FILE* salles = fopen("salle.txt", "w");
  if (salles == NULL) {
      exit(1);
  }
  fclose(salles);*/
  clrscr();
  choix();
  return 0;
}