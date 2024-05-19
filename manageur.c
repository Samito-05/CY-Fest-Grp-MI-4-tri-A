#include "bibli.h"


void creerSalle() {
  int concert, nrangee, nsiege, nsiegeA, nsiegeB, nsiegeC, fosse;
  char nomsalle[21];
  float prixA, prixB, prixC;
  int verif=0, verif2=0;
  char c;

  concert = 0; // On initialise la salle comme non occupé
  listeSalle();
  printf("Quel est le nom de la salle ? (20 caractères maximum)\n");//A securiser !
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
  do{
    verif=scanf("%d",&nrangee);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nrangee<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nrangee<1);
  verif=0;
  verif2=0;
  clrscr();

  printf("Combien y a t-il de siège par rangée ?\n");
  do{
    verif=scanf("%d",&nsiege);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nsiege<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nsiege<1);
  verif=0;
  verif2=0;
  clrscr();


  // On demande le nombre de siège par catégorie
  printf("Combien y a t-il de rangée de catégorie A ?\n");
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



  printf("Combien y a t-il de rangée de catégorie B ?\n");
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
    printf("Il y a une erreur dans l'affectation des sièges, veuillez "
           "réessayer\n");

    printf("Combien y a t-il de rangée de catégorie A ?\n");
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


    printf("Combien y a t-il de rangée de catégorie B ?\n");
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
    if (verif != 1 || prixA>1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixA>1);
  verif=0;
  verif2=0;
    clrscr();
  }
  // On demande le prix de chaque catégorie
  else {
    printf("Quel est le prix d'une place de catégorie A ?\n");
    do{
    verif=scanf("%f",&prixA);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixA>1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixA>1);
  verif=0;
  verif2=0;
    clrscr();
  }
if(nsiegeB >0){
  printf("Quel est le prix d'une place de catégorie B ?\n");
  do{
    verif=scanf("%f",&prixB);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixB>1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixB>1);
  verif=0;
  verif2=0;
  clrscr();
}


 
  if(nsiegeC >0){  
    printf("Quel est le prix d'une place de catégorie C ?\n");
    do{
    verif=scanf("%f",&prixC);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixC>1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixC>1);
  verif=0;
  verif2=0;
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
  do{
    verif=scanf("%d",&nrangee);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nrangee<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nrangee<1);
  verif=0;
  verif2=0;
  clrscr();

  printf("Combien y a t-il de siège par rangée ?\n");
  do{
    verif=scanf("%d",&nsiege);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || nsiege<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || nsiege<1);
  verif=0;
  verif2=0;
  clrscr();


  // On demande le nombre de siège par catégorie
  printf("Combien y a t-il de rangée de catégorie A ?\n");
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



  printf("Combien y a t-il de rangée de catégorie B ?\n");
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
    printf("Il y a une erreur dans l'affectation des sièges, veuillez "
           "réessayer\n");

    printf("Combien y a t-il de rangée de catégorie A ?\n");
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


    printf("Combien y a t-il de rangée de catégorie B ?\n");
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
    if (verif != 1 || prixA>1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixA>1);
  verif=0;
  verif2=0;
    clrscr();
  }
  // On demande le prix de chaque catégorie
  else {
    printf("Quel est le prix d'une place de catégorie A ?\n");
    do{
    verif=scanf("%f",&prixA);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixA>1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixA>1);
  verif=0;
  verif2=0;
    clrscr();
  }
  if(nsiegeB>0){
  printf("Quel est le prix d'une place de catégorie B ?\n");
  do{
    verif=scanf("%f",&prixB);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixB>1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixB>1);
  verif=0;
  verif2=0;
  clrscr();
}


 
  if(nsiegeC >0){  
    printf("Quel est le prix d'une place de catégorie C ?\n");
    do{
    verif=scanf("%f",&prixC);
    do{
      verif2=scanf("%c",&c);
    }while(verif2 == 1 && c!='\n');
    if (verif != 1 || prixC>1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixC>1);
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

void listeSalle(){
  FILE * salles= fopen("salle.txt","r");
  if (salles==NULL){
    printf("Erreur fichier");
    exit(1);
  }
  char phrase[50];
  char nomsalle[21];
  int a, i=0,nr;
  printf("Voici les salles créée\n");
  printf("\n");
  while((a = fgetc(salles)) != EOF){
    while (a != ' ' && a != EOF && i < 20) {
      nomsalle[i] = (char)a;
      i++;
      a = fgetc(salles);
    }
    nomsalle[i] = '\0'; 
    printf("%s\n",nomsalle);
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


/*void creerConcert(){
  //demander les infos du concert
  char nom_concert[21];
  char nom_salle[21];
  float debut,temps,fin;
  printf("Quelle est le nom du concert ? (maximum 20 caractères)\n");
  scanf("%s",nom_concert);
  printf("A quelle heure commence le concert ? (h.m)\n");
  scanf("%f",&debut);
  //demander dans quelle salle le mettre, changer la variable concert =1
  printf("Le concert a lieu dans quelle salle ? (maximum 20 caractères)\n");
  scanf("%s",nom_salle);
  printf("Combien de temps dure le concert (h.m)?\n");
  scanf("%f",&temps);



  
  
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

  FILE *concert = fopen("concert.txt", "a+");
  if (concert == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", "concert.txt");
    exit(1);
  }
  fprintf(concert, "%s : Nom du concert\n", nom_concert);
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
    printf("La salle n'a pas été trouvée.\n");
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
  printf("En quelle année a lieu le concert ?\n");
  scanf("%d",&a);
  printf("Quel mois a lieu le concert ?\n");
  scanf("%d",&mois);
  printf("Quel jour a lieu le concert (numériquement) ?\n");
  scanf("%d",&j);
  printf("A quelle heure a lieu le concert ?\n");
  scanf("%d",&h);
  printf("A quel minute a lieu le concert ?\n");
  scanf("%d",&min);

  s=((31557600*a+2629800*mois+86400*j+3600*h+60*min)-62168472000);
  printf("%ld\n",s);
  printf("%ld",time(NULL));
}*/

//Pas fini donc a pas utiliser 
