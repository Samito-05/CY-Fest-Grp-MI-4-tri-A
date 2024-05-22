#include "bibli.h"

void afficheSalle(char *nom_salle) {
  int r = 1;

  // ouvrir le fichier
  FILE *salles = fopen("salle.txt", "r");
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
  float pA,pB,pC;

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
  pA=atof(phrase);
  fgets(phrase, sizeof(phrase), salles);
  pB=atof(phrase);
  fgets(phrase, sizeof(phrase), salles);
  pC=atof(phrase);

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
  printf("O : Categorie 1 / Fosse (%.2f EURO)\n",pA);
  couleur("33");
  printf("O : Categorie 2 (%.2f EURO)\n",pB);
  couleur("37");
  printf("O : Categorie 3 (%.2f EURO)\n",pC);
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

  for (int i=1; i<=10; i++){
    fgets(phrase, sizeof(phrase), salles);
  }
  

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

void listeSallef(){
  FILE * salles= fopen("salle.txt","r");
  if (salles==NULL){
    printf("Erreur fichier");
    exit(1);
  }
  char phrase[50];
  char nomsalle[21];
  int a, i=0,nr;
  printf("Voici les salles disponibles\n");
  printf("\n");
  while((a = fgetc(salles)) != EOF){
    while (a != ' ' && a != EOF && i < 20) {
      nomsalle[i] = (char)a;
      i++;
      a = fgetc(salles);
    }
    nomsalle[i] = '\0';
    fgets(phrase, sizeof(phrase), salles);
    fgets(phrase, sizeof(phrase), salles);
    if (atoi(phrase)){
      printf("%s\n",nomsalle); 
    }
    i=0;
    fgets(phrase, sizeof(phrase), salles);
    nr=atoi(phrase);
    for (i=1;i<=8+nr;i++){
      fgets(phrase, sizeof(phrase), salles);
    }
    i=0;
  }
  printf("\n");
  fclose(salles);
}