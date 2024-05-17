#include "bibli.h"


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

/*void salle_txt(char* salle)
{

    char *nom = salle.nomsalle;

    nom[strcspn(nom, "\n")] = '\0';

    FILE *fichier = fopen(nom, "w");

    if (fichier == NULL)
    {

        printf("Erreur d'ouverture du fichier.");
        return;
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
    fprintf(fichier, "\n");

    fclose(fichier);
}*/

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

