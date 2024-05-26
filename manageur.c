#include "bibli.h"


void creerSalle() {
  int concert, nrangee, nsiege, nsiegeA, nsiegeB, nsiegeC, fosse;
  char nomsalle[21];
  float prixA, prixB, prixC;
  int verif=0, verif2=0;
  char c;

  concert = 0; // On initialise la salle comme non occupé
  listeSalle();
  printf("Quel est le nom de la salle ? (20 caracteres maximum)\n");//A securiser !
  scanf("%20s", nomsalle);
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
      printf("La salle existe dejà.\n");
      return;
    }
  }


  printf("Combien y a t-il de rangee (20 maximum) ?\n");
  do{
    verif=scanf("%d",&nrangee);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nrangee<1|| nrangee>20){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nrangee<1|| nrangee >20);
  verif=0;
  verif2=0;
  clrscr();

  printf("Combien y a t-il de siege par rangee (20 maximum) ?\n");
  do{
    verif=scanf("%d",&nsiege);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nsiege<1|| nsiege>20){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nsiege<1||nsiege >20);
  verif=0;
  verif2=0;
  clrscr();


  // On demande le nombre de siège par catégorie
  do{  
    printf("Combien y a t-il de rangee de categorie A ?\n");
    do{
      verif=scanf("%d",&nsiegeA);
      do{
        verif2=scanf("%c",&c);
      }while(verif2 == 1 && c!='\n');
      if (verif != 1 || nsiegeA<1){
        printf("saisie invalide\n");
      }
    } while (verif != 1 || nsiegeA<1);
    verif=0;
    verif2=0;
    nsiegeA *=nsiege; // On fait ranger de Catégorie A * nombre de siège par rangée
    clrscr();



    printf("Combien y a t-il de rangee de categorie B ?\n");
    do{
      verif=scanf("%d",&nsiegeB);
      do{
        verif2=scanf("%c",&c);
      }while(verif2 == 1 && c!='\n');
      if(verif != 1 || nsiegeB<0){
        printf("saisie invalide\n");
      }
    } while (verif != 1 || nsiegeB<0);
    verif=0;
    verif2=0;
    nsiegeB *= nsiege;


    nsiegeC =nsiege * nrangee - (nsiegeA + nsiegeB);
    clrscr();
    if (nsiegeC < 0) {
      nsiegeC = 0;
    }
    if ((nsiegeA + nsiegeB + nsiegeC) !=(nsiege *nrangee)) {
      printf("Il y a une erreur dans l'affectation des sieges, veuillez reessayer\n");
    } 
  }while ((nsiegeA + nsiegeB + nsiegeC) !=(nsiege *nrangee)); // Si la somme des sièges des 3 catégories ne sont pas égales au nombre de siège total on recommence le scan

  printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
  do{
    verif=scanf("%d",&fosse);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || fosse !=0 || fosse !=1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 ||  fosse !=0 && fosse !=1);
  verif=0;
  verif2=0;
  clrscr();


  if (fosse ==1) { // Si il y a une fosse on double le nombre de place en catégorie A
    nrangee += nsiegeA / nsiege;
    nsiegeA += nsiegeA;

    printf("Quel est le prix d'une place en fosse ?\n");
    do{
    verif=scanf("%f",&prixA);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixA>1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixA<1);
  verif=0;
  verif2=0;
    clrscr();
  }
  // On demande le prix de chaque catégorie
  else {
    printf("Quel est le prix d'une place de categorie A ?\n");
    do{
    verif=scanf("%f",&prixA);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixA<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixA<1);
  verif=0;
  verif2=0;
    clrscr();
  }
if(nsiegeB >0){
  printf("Quel est le prix d'une place de categorie B ?\n");
  do{
    verif=scanf("%f",&prixB);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixB<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixB<1);
  verif=0;
  verif2=0;
  clrscr();
}


 
  if(nsiegeC >0){  
    printf("Quel est le prix d'une place de categorie C ?\n");
    do{
    verif=scanf("%f",&prixC);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixC<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixC<1);
  verif=0;
  verif2=0;
    clrscr();
  }

char *fichiersalle = "salle.txt"; // Ajout de la salle dans le fichier
  FILE *fichier = fopen(fichiersalle, "a+");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", fichiersalle);
    exit(1);
  }
  fprintf(fichier, "%s : Nom de la salle\n", nomsalle);
  fprintf(fichier, "%d : Est-ce que la salle est utilise ?\n", concert);
  fprintf(fichier, "%d : Nombre de rangée\n", nrangee);
  fprintf(fichier, "%d : Nombre de siege par rangée\n", nsiege);
  fprintf(fichier, "%d : Nombre de siege de catégorie A\n", nsiegeA);
  fprintf(fichier, "%d : Nombre de siege de catégorie B\n", nsiegeB);
  fprintf(fichier, "%d : Nombre de siege de catégorie C\n", nsiegeC);
  fprintf(fichier, "%d : Est-ce qu'il y a une fosse ?\n", fosse);
  fprintf(fichier, "%.2f : Prix de la catégorie A\n", prixA);
  fprintf(fichier, "%.2f : Prix de la catégorie B\n", prixB);
  fprintf(fichier, "%.2f : Prix de la catégorie C\n", prixC);

  
  // affichage de la Salle
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
  printf("La salle a bien ete cree.\n");
}



void modifierSalle(char *nom_salle) {
  // ouvrir le fichier
  int verif=0, verif2=0;
  char c;
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

     printf("Combien y a t-il de rangee ?\n");
  do{
    verif=scanf("%d",&nrangee);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nrangee<1|| nrangee >20){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nrangee<1|| nrangee>20);
  verif=0;
  verif2=0;
  clrscr();

  printf("Combien y a t-il de siege par rangee ?\n");
  do{
    verif=scanf("%d",&nsiege);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nsiege<1||nsiege >20){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nsiege<1|| nsiege<20);
  verif=0;
  verif2=0;
  clrscr();


  // On demande le nombre de siège par catégorie
  printf("Combien y a t-il de rangee de categorie A ?\n");
  do{
    verif=scanf("%d",&nsiegeA);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nsiegeA<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nsiegeA<1);
  verif=0;
  verif2=0;
  nsiegeA *=nsiege; // On fait ranger de Catégorie A * nombre de siège par rangée
  clrscr();



  printf("Combien y a t-il de rangee de categorie B ?\n");
  do{
    verif=scanf("%d",&nsiegeB);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nsiegeB<0){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nsiegeB<0);
  verif=0;
  verif2=0;
  nsiegeB *= nsiege;


  nsiegeC =nsiege * nrangee - (nsiegeA + nsiegeB);
  clrscr();
  if (nsiegeC < 0) {
    nsiegeC = 0;
  }

  while ((nsiegeA + nsiegeB + nsiegeC) !=(nsiege *nrangee)) { // Si la somme des sièges des 3 catégories ne sont pas égales au nombre de siège total on recommence le scan
    printf("Il y a une erreur dans l'affectation des sieges, veuillez reessayer\n");

    printf("Combien y a t-il de rangee de categorie A ?\n");
    do{
      verif=scanf("%d",&nsiegeA);
      do{
        verif2=scanf("%c",&c);
      }while(verif2 == 1 && c!='\n');
      if (verif != 1 || nsiegeA<1){
        printf("saisie invalide\n");
      }
    } while (verif != 1 || nsiegeA<1);
  verif=0;
  verif2=0;
    clrscr();
    nsiegeA *= nsiege; // On fais rangée de Catégorie A * nombre de
  // siège par rangée
    printf("Combien y a t-il de rangee de categorie B ?\n");
    do{
    verif=scanf("%d",&nsiegeB);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nsiegeB<0){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nsiegeB<0);
  verif=0;
  verif2=0;
    nsiegeB *= nsiege;
    clrscr();
    
    nsiegeC = nsiege * nrangee - (nsiegeA + nsiegeB);
    clrscr();
    if (nsiegeC < 0) {
      nsiegeC = 0;
    }
  }

  printf("Y'a t-il une fosse ? (1 si oui, 0 si non)\n");
  do{
    verif=scanf("%d",&fosse);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || fosse !=0 || fosse !=1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 ||  fosse !=0 && fosse !=1);
  verif=0;
  verif2=0;
  clrscr();


  if (fosse ==1) { // Si il y a une fosse on double le nombre de place en catégorie A
    nrangee += nsiegeA / nsiege;
    nsiegeA += nsiegeA;

    printf("Quel est le prix d'une place en fosse ?\n");
    do{
    verif=scanf("%f",&prixA);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixA<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixA<1);
  verif=0;
  verif2=0;
    clrscr();
  }
  // On demande le prix de chaque catégorie
  else {
    printf("Quel est le prix d'une place de categorie A ?\n");
    do{
    verif=scanf("%f",&prixA);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixA<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixA<1);
  verif=0;
  verif2=0;
    clrscr();
  }
  if(nsiegeB>0){
  printf("Quel est le prix d'une place de categorie B ?\n");
  do{
    verif=scanf("%f",&prixB);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixB<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixB<1);
  verif=0;
  verif2=0;
  clrscr();
}


 
  if(nsiegeC >0){  
    printf("Quel est le prix d'une place de categorie C ?\n");
    do{
    verif=scanf("%f",&prixC);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixC<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixC<1);
  verif=0;
  verif2=0;
    clrscr();
  }

  char *fichiersalle = "salle.txt";
  FILE *fichier = fopen(fichiersalle, "w");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", fichiersalle);
    exit(1);
  }
  // Ecritures des nouvelles données    de la salle
  fprintf(fichier, "%s : Nom de la salle\n", nomsalle);
  fprintf(fichier, "%d : Est-ce que la salle est utilisée ?\n", concert);
  fprintf(fichier, "%d : Nombre de rangee\n", nrangee);
  fprintf(fichier, "%d : Nombre de siege par rangée\n", nsiege);
  fprintf(fichier, "%d : Nombre de siege de catégorie A\n", nsiegeA);
  fprintf(fichier, "%d : Nombre de siege de catégorie B\n", nsiegeB);
  fprintf(fichier, "%d : Nombre de siege de catégorie C\n", nsiegeC);
  fprintf(fichier, "%d : Est-ce qu'il y a une fosse ?\n", fosse);
  fprintf(fichier, "%.2f : Prix de la catégorie A\n", prixA);
  fprintf(fichier, "%.2f : Prix de la catégorie B\n", prixB);
  fprintf(fichier, "%.2f : Prix de la catégorie C\n", prixC);

  // Affichage de la salle dans le fichier
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
  if (modif == NULL) {
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
    fclose(salles);
    return;
  }

  rewind(salles);

  while (strstr(fgets(phrase, sizeof(phrase), salles), nom_salle) == NULL) {
    fprintf(modif, "%s", phrase);
  }

  // on ignore les données de la salle souhaité

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

void listeSalle(){
  FILE * salles= fopen("salle.txt","r"); // Ouverture du fichier
  if (salles==NULL){
    printf("Erreur fichier");
    exit(1);
  }
  char phrase[50];
  char nomsalle[21];
  int a, i=0,nr;
  printf("Voici les salles creee\n");
  printf("\n");
  while((a = fgetc(salles)) != EOF){
    while (a != ' ' && a != EOF && i < 20) { // Recuperation des lettres du nom de la salle 
      nomsalle[i] = (char)a;
      i++;
      a = fgetc(salles);
    }
    nomsalle[i] = '\0'; 
    printf("%s\n",nomsalle); // Affichage du nom de la salle
    i=0;
    for (i=1;i<=3;i++){
      fgets(phrase, sizeof(phrase), salles);
    }
    nr=atoi(phrase);
    for (i=1;i<=8+nr;i++){
      fgets(phrase, sizeof(phrase), salles);
    }
    i=0;
  }
  printf("\n");
  fclose(salles);
}

void creerConcert(){
  //demander les infos du concert
  char nom_concert[21];
  char nom_salle[21];
  int tdebut,temps,tfin;
  printf("Quelle est le nom du concert ? (maximum 20 caracteres)\n");
  scanf("%20s",nom_concert);
  //demander dans quelle salle le mettre, changer la variable concert =1
  printf("Le concert a lieu dans quelle salle ? (maximum 20 caracteres)\n");
  scanf("%20s",nom_salle);
  clrscr();
  verifm(nom_salle);
  tdebut=debut(); // heure de debut
  temps=duree(); // durée du concert


  
  
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
    fclose(salles);
    return;
  }

  FILE *concert = fopen("concert.txt", "a+"); // Ouverture fichier "concert.txt"
  if (concert == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", "concert.txt");
    exit(1);
  }
  // insertion des infos du concert
  fprintf(concert, "%s : Nom du concert\n", nom_concert);
  fprintf(concert, "%d : Heure du debut du concert\n", tdebut);
  fprintf(concert, "%d : Longueur du concert\n", temps);
  fprintf(concert, "%d : Heure de fin du concert\n", tdebut+temps);
  fprintf(concert, "%s : Nom de la salle\n", nom_salle);
  fclose(concert);
  
  salles= fopen("salle.txt", "r+");
  if (salles == NULL) {
    exit(1);
  }

  // Lire ligne par ligne jusqu'à la fin du fichier
  while (fgets(phrase, sizeof(phrase), salles) != NULL) {
    // Vérification de la bonne salle
    if (strstr(phrase, nom_salle) != NULL) {
      // printf("La salle existe.\n");
      trouve = 1;
      break;
    }
  }
  if (!trouve) {
    fclose(salles);
  return;
  }
  fseek(salles, 0, SEEK_CUR);
  fputc('1', salles);
  fclose(salles);
}

int debut(){
  int j,mois,a,h,min;
  long s;
  int verif=0, verif2=0;
  char c;
  printf("En quelle annee a lieu le concert ?\n");
  do{                             // Verification de la saisie de l'année
      verif=scanf("%d",&a);
      do{
        verif2=scanf("%c",&c);
      }while(verif2 == 1 && c!='\n');
      if (verif != 1 || a<2024){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || a<2024);
  verif=0;
  verif2=0;
  printf("Quel mois a lieu le concert (numeriquement) ?\n");
  do{                             // Verification de la saisie du mois
    verif=scanf("%d",&mois);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || mois<1|| mois >12){
      printf("saisie invalide\n");
    }
  }while (verif != 1 || mois<1|| mois >12);
  verif=0;
  verif2=0;
  printf("Quel jour a lieu le concert (numeriquement) ?\n");
 
  if (mois == 2 && a%4 != 0){
    do{                          // Verification de la saisie du jour
      verif=scanf("%d",&j);
      do{
        verif2=scanf("%c",&c);
      }while(verif2 == 1 && c!='\n');
      if (verif != 1 || j<1 || j>28){
        printf("saisie invalide\n");
      }
    } while (verif != 1 || j<1|| j >28);
    verif=0;
    verif2=0;//entre 1 et 31
  }
  if (mois == 2 && a%4 == 0){ //Année bissextile
    do{
      verif=scanf("%d",&j);
      do{
        verif2=scanf("%c",&c);
      }while(verif2 == 1 && c!='\n');
      if (verif != 1 || j<1 || j>29){
        printf("saisie invalide\n");
      }
    } while (verif != 1 || j<1|| j >29);
    verif=0;
    verif2=0;//entre 1 et 31
  }
  if (mois == 1|| mois == 3||mois == 5||mois == 7||mois == 8||mois == 10||mois == 12){ // Mois a 31 jours
    do{
      verif=scanf("%d",&j);
      do{
        verif2=scanf("%c",&c);
      }while(verif2 == 1 && c!='\n');
      if (verif != 1 || j<1 || j>31){
        printf("saisie invalide\n");
      }
    } while (verif != 1 || j<1|| j >31);
    verif=0;
    verif2=0;//entre 1 et 31
  }
 
 if (mois == 4|| mois == 6||mois == 9||mois == 11){ // Mois a 30 jours
    do{
      verif=scanf("%d",&j);
      do{
        verif2=scanf("%c",&c);
      }while(verif2 == 1 && c!='\n');
      if (verif != 1 || j<1 || j>30){
        printf("saisie invalide\n");
      }
    } while (verif != 1 || j<1|| j >30);
    verif=0;
    verif2=0;//entre 1 et 31
  }//entre 1 et 31

  printf("A quelle heure a lieu le concert ?\n");
  do{                          // Verificcation saisie de l'heure
    verif=scanf("%d",&h);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || h<0 || h>23){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || h<0|| h >23);
  verif=0;
  verif2=0;//entre 0 et 23 
  printf("A quel minute a lieu le concert ?\n");
  do{                          // Verificcation saisie des minutes
    verif=scanf("%d",&min);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || min<0 || min>59){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || min<0|| min>59);
  verif=0;
  verif2=0;("%d",&min);//entre 0 et 59

  struct tm date;      // Converstion en timestamp
  date.tm_sec = 0;
  date.tm_min = min;
  date.tm_hour= h;
  date.tm_mday= j;
  date.tm_mon = mois-1;
  date.tm_year= a-1900;
  date.tm_wday=0;
  date.tm_yday=0;
  date.tm_isdst=-1;
  
  s=mktime(&date);
  return s;
}

int duree(){
  int h,min;
  long s;
  int verif=0, verif2=0;
  char c;
  do{
    printf("Combien d'heure dure le concert ?\n");
    do{                          // Verification de la durée en heures
    verif=scanf("%d",&h);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || h<0 || h>23){
      printf("saisie invalide\n");
    }
      } while (verif != 1 || h<0|| h >23);
      verif=0;
      verif2=0;
    printf("Combien de minute dure le concert ?\n");
    do{                         // Verification de la durée en minutes
    verif=scanf("%d",&min);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || min<0 || min>59){
      printf("saisie invalide\n");
    }
    } while (verif != 1 || min<0|| min>59);   // Verification de la durée du concert
    verif=0;
    verif2=0;("%d",&min);
    if(h<=0 && min<=0){
      printf("le concert doit duree au moins 1 min\n");
    }
}while(h<=0 && min<=0);   // Conversion en secondes
  s=h*3600+min*60;
  return s;
}

void listeSallem(){  // Liste de salles disponibles
  FILE * salles= fopen("salle.txt","r"); // Ouverture fichier
  if (salles==NULL){
    printf("Erreur fichier");
    exit(1);
  }

  FILE * verifm= fopen("verifm.txt","r");
  if (verifm==NULL){
    printf("Erreur fichier");
    exit(1);
  }

  if (fgetc(verifm)==EOF){
    clrscr();
    printf("Toute les salles sont utilisees\n");
    manage();
  }

  else{        // Affichge des salles
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
      fgets(phrase, sizeof(phrase), salles);   // Lit l'etat de la salle
      fgets(phrase, sizeof(phrase), salles);   // Indicateur utilisé
      if (!atoi(phrase)){
        printf("%s\n",nomsalle); 
      }
      i=0;
      fgets(phrase, sizeof(phrase), salles);   // Nbr de rangées
      nr=atoi(phrase);
      for (i=1;i<=8+nr;i++){
        fgets(phrase, sizeof(phrase), salles);  // Ignores les lignes d'infos
      }
      i=0;
    }
  }
  
  printf("\n");
  fclose(salles);
}

void libererSalle(){

/*-Parcourir tout le fichier et regarder si le temps de fin est dépassé;
-changer la salle : utilsation = 0;
-Supprimer le concert;*/
	FILE * concert=fopen("concert.txt","r");
	if (concert==NULL){
		printf("Erreur fichier\n");
		exit(1);
	}
    verif();
    int a=0,b=0,c=0,i=0,j=0,trouve=0, nr=0, ns=0;
    char phrase[50];
    char nomsalle[21];
    char nomconcert[21];
    while (a!=EOF){
        while (b != ' ' && b != EOF && i < 20){
          b=fgetc(concert);
          nomconcert[i]=b;
          i++;
        }
        nomconcert[i]='\0';  
        for (int i=1;i<=4;i++){
            fgets(phrase,sizeof(phrase),concert);
        }
        if(atoi(phrase)-time(NULL)<=0){  // Verification si le conccert est fini
            
            FILE * salles=fopen("salle.txt","r+");// On réouvre fichier salle a chaque fois
	        if (salles==NULL){
		        printf("Erreur fichier\n");
		        exit(1);
	        }
            
            while (c != ' ' && c != EOF && j < 20){
                c=fgetc(concert);
                nomsalle[j]=c;
                j++;
            }
            nomsalle[j]='\0';

            //On change le "est utilisé de la salle"

            //On recherche la salle dans le fichier salle.txt
            while (fgets(phrase, sizeof(phrase), salles) != NULL) {
                // Vérification de la bonne salle
                if (strstr(phrase, nomsalle) != NULL) {
                // printf("La salle existe.\n");
                trouve = 1;
                break;
                }
            }

            // Vérifier si la fin du fichier est atteinte sans trouver la salle
            if (!trouve) {
                fclose(salles);
                return;
            }

            // On change la valeur 1 par 0
            
            fseek(salles, 0, SEEK_CUR);
            fputc('0', salles);
        
            fclose(salles);

            //On libère les places

            libererPlace(nomsalle);
            supprimerConcert(nomconcert);

        }
        j=0;
        fgets(phrase,sizeof(phrase),concert);
      a=fgetc(concert);
    }
    fclose(concert);
    verif();
}

void libererPlace(char* nom_salle){
   // ouvrir le fichier
  int verif=0, verif2=0;
  char c;
  FILE *salles = fopen("salle.txt", "r");
  if (salles == NULL) {
    exit(1);
  }

  FILE *place = fopen("place.txt", "w");
  if (place == NULL) {
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
    fclose(salles);
    return;
  }

  rewind(salles);

  while (strstr(fgets(phrase, sizeof(phrase), salles), nom_salle) == NULL) {
    fprintf(place, "%s", phrase);
  }

  // Reccuperation de données de la salle

  int nr,ns,nsA,nsB,nsC,f;
  float pA,pB,pC;

  fgets(phrase, sizeof(phrase), salles);

  fgets(phrase, sizeof(phrase), salles);
  nr = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);
  ns = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);
  nsA = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);
  nsB = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);
  nsC = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);
  f = atoi(phrase);

  fgets(phrase, sizeof(phrase), salles);
  pA = atof(phrase);

  fgets(phrase, sizeof(phrase), salles);
  pB = atof(phrase);

  fgets(phrase, sizeof(phrase), salles);
  pC = atof(phrase);

  for (int i=1;i<=nr; i++){
    fgets(phrase, sizeof(phrase), salles);
  }

  while (fgets(phrase, sizeof(phrase), salles) != NULL) {
    fprintf(place, "%s", phrase);
  }
  fclose(salles);
  fclose(place);
  ///////////////////////////////////

  int concert = 0; // On initialise la salle comme non occupé

  FILE *fichier = fopen("salle.txt", "w");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier\n" );
    exit(1);
  } // Reinitialisation des données de la salle
  fprintf(fichier, "%s : Nom de la salle\n", nom_salle);
  fprintf(fichier, "%d : Est-ce que la salle est utilisée ?\n", concert);
  fprintf(fichier, "%d : Nombre de rangée\n", nr);
  fprintf(fichier, "%d : Nombre de siege par rangée\n", ns);
  fprintf(fichier, "%d : Nombre de siege de catégorie A\n", nsA);
  fprintf(fichier, "%d : Nombre de siege de catégorie B\n", nsB);
  fprintf(fichier, "%d : Nombre de siege de catégorie C\n", nsC);
  fprintf(fichier, "%d : Est-ce qu'il y a une fosse ?\n", f);
  fprintf(fichier, "%.2f : Prix de la catégorie A\n", pA);
  fprintf(fichier, "%.2f : Prix de la catégorie B\n", pB);
  fprintf(fichier, "%.2f : Prix de la catégorie C\n", pC);

  for (int i = 0; i < nsA / ns; i++) {
    for (int j = 0; j < ns - 1; j++) {
      fprintf(fichier, "O");
      fprintf(fichier, " ");
    }
    fprintf(fichier, "O");
    fprintf(fichier, "\n");
  }
  for (int i = 0; i < nsB / ns; i++) {
    for (int j = 0; j < ns - 1; j++) {
      fprintf(fichier, "O");
      fprintf(fichier, " ");
    }
    fprintf(fichier, "O");
    fprintf(fichier, "\n");
  }
  for (int i = 0; i < nsC / ns; i++) {
    for (int j = 0; j < ns - 1; j++) {
      fprintf(fichier, "O");
      fprintf(fichier, " ");
    }
    fprintf(fichier, "O");
    fprintf(fichier, "\n");
  }

  fclose(fichier);

  salles = fopen("salle.txt", "a+");  // Mise a jour du fichier avec les autres salles
  if (salles == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", "salle.txt");
    exit(1);
  }

  place = fopen("place.txt", "r");
  if (salles == NULL) {
    exit(1);
  }

  while (fgets(phrase, sizeof(phrase), place)!= NULL) {
    fprintf(salles, "%s", phrase);
  }
  fclose(salles);
  fclose(place);

}

void supprimerConcert(char* nom_concert){
     // ouvrir le fichier
  int verif=0, verif2=0;
  char c;
  FILE *concert = fopen("concert.txt", "r"); // Ouverture fichier
  if (concert == NULL) {
    exit(1);
  }

  FILE *mconcert = fopen("mconcert.txt", "w");
  if (mconcert == NULL) {
    exit(1);
  }

  char phrase[50];
  int trouve = 0;

  // Lire ligne par ligne jusqu'à la fin du fichier
  while (fgets(phrase, sizeof(phrase), concert) != NULL) {
    // Vérification de la bonne salle
    if (strstr(phrase, nom_concert) != NULL) {  // Recherche du concert ta supprimer
      // printf("La salle existe.\n");
      trouve = 1;
      break;
    }
  }

  // Vérifier si la fin du fichier est atteinte sans trouver la salle
  if (!trouve) {
    fclose(concert);
    return;
  }

  rewind(concert);

  while (strstr(fgets(phrase, sizeof(phrase), concert), nom_concert) == NULL) { // Copie des autres concerts sans le concert supprimé
    fprintf(mconcert, "%s", phrase);
  }

  for (int i=1; i<=4;i++){
    fgets(phrase,sizeof(phrase),concert);
  }

  while (fgets(phrase, sizeof(phrase), concert) != NULL) {
    fprintf(mconcert, "%s", phrase);
  }

  fclose(concert);
  fclose(mconcert);
  ///////////////////////////////////


  concert = fopen("concert.txt", "w");
  if (concert == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", "salle.txt");
    exit(1);
  }

  mconcert = fopen("mconcert.txt", "r");
  if (mconcert == NULL) {
    exit(1);
  }

  while (fgets(phrase, sizeof(phrase), mconcert)!=NULL) {
    fprintf(concert, "%s", phrase);
  }
  fclose(concert);
  fclose(mconcert);


}

void verif(){
  FILE * salles= fopen("salle.txt","r");
  FILE * verifm= fopen("verifm.txt","w");
  FILE * veriff= fopen("veriff.txt","w");
  if (salles==NULL){
    printf("Erreur fichier");
    exit(1);
  }
  char phrase[50];
  char nomsalle[21];
  int a, i=0,nr;
  while((a = fgetc(salles)) != EOF){
    while (a != ' ' && a != EOF && i < 20) {
      nomsalle[i] = (char)a;
      i++;
      a = fgetc(salles);
    }
    nomsalle[i] = '\0';
    fgets(phrase, sizeof(phrase), salles);
    fgets(phrase, sizeof(phrase), salles);
    if (!atoi(phrase)){
      fprintf(verifm, "%s\n", nomsalle); 
    }
    else{
      fprintf(veriff, "%s\n", nomsalle); 
    }
    i=0;
    fgets(phrase, sizeof(phrase), salles);
    nr=atoi(phrase);
    for (i=1;i<=8+nr;i++){
      fgets(phrase, sizeof(phrase), salles);
    }
    i=0;
  }
  fclose(verifm);
  fclose(veriff);
  fclose(salles);
}

void verifm(char *salle){
  FILE* verifm=fopen("verifm.txt","r");
  if (verifm==NULL){
    printf("Erreur de fichier\n");
    exit(1);
  }
  
  char phrase[50];
  int trouve=0;

  while(fgets(phrase,sizeof(phrase),verifm)!=NULL){
    if (strstr(phrase,salle)!=NULL){
      trouve=1;
      break;
    }
  }
  fclose(verifm);
  if (!trouve){
    printf("Cette salle est occupe ou n'existe pas\n");
    manage();
  }
}



