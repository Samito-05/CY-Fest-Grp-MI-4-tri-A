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
    if (verif != 1 || prixA<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixA<1);
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
    if (verif != 1 || prixB<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixB<1);
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
    if (verif != 1 || prixC<1){
      printf("saisie invalide\n");
    }
  } while (verif != 1 || prixC<1);
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
    printf("Quel est le prix d'une place de catégorie A ?\n");
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
  printf("Quel est le prix d'une place de catégorie B ?\n");
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
    printf("Quel est le prix d'une place de catégorie C ?\n");
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

void creerConcert(){
  //demander les infos du concert
  char nom_concert[21];
  char nom_salle[21];
  int tdebut,temps,tfin;
  printf("Quelle est le nom du concert ? (maximum 20 caractères)\n");
  scanf("%s",nom_concert);
  //demander dans quelle salle le mettre, changer la variable concert =1
  printf("Le concert a lieu dans quelle salle ? (maximum 20 caractères)\n");
  scanf("%s",nom_salle);
  tdebut=debut();
  temps=duree();


  
  
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
  scanf("%d",&mois);//entre 0 et 11
  printf("Quel jour a lieu le concert (numériquement) ?\n");
  scanf("%d",&j);//entre 1 et 31
  printf("A quelle heure a lieu le concert ?\n");
  scanf("%d",&h);//entre 0 et 23 
  printf("A quel minute a lieu le concert ?\n");
  scanf("%d",&min);//entre 0 et 59

  struct tm date;
  date.tm_sec = 0;
  date.tm_min = min;
  date.tm_hour= h;
  date.tm_mday= j;
  date.tm_mon = mois-1;
  date.tm_year= a-1900;
  date.tm_wday=0;
  date.tm_yday=0;
  date.tm_isdst=0;
  
  s=mktime(&date);
  return s;
}

int duree(){
  int h,min;
  long s;
  printf("Combien d'heure dure le concert ?\n");
  scanf("%d",&h);
  printf("Combien de minute dure le concert ?\n");
  scanf("%d",&min);

  s=h*3600+min*60;
  return s;
}

void listeSallem(){
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
    if (!atoi(phrase)){
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

void libererSalle(){

/*-Parcourir tout le fichier et regarder si le temps de fin est dépassé;
-changer la salle : utilsation = 0;
-Supprimer le concert;*/

	FILE * concert=fopen("concert.txt","r");
	if (concert==NULL){
		printf("Erreur fichier\n");
		exit(1);
	}

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
        if(atoi(phrase)-time(NULL)<=0){
            
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
                printf("La salle n'a pas été trouvée.\n");
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
    printf("La salle n'a pas été trouvée.\n");
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
  }
  fprintf(fichier, "%s : Nom de la salle\n", nom_salle);
  fprintf(fichier, "%d : Est-ce que la salle est utilisée ?\n", concert);
  fprintf(fichier, "%d : Nombre de rangée\n", nr);
  fprintf(fichier, "%d : Nombre de siège par rangée\n", ns);
  fprintf(fichier, "%d : Nombre de siège de catégorie A\n", nsA);
  fprintf(fichier, "%d : Nombre de siège de catégorie B\n", nsB);
  fprintf(fichier, "%d : Nombre de siège de catégorie C\n", nsC);
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

  salles = fopen("salle.txt", "a+");
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
  FILE *concert = fopen("concert.txt", "r");
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
    if (strstr(phrase, nom_concert) != NULL) {
      // printf("La salle existe.\n");
      trouve = 1;
      break;
    }
  }

  // Vérifier si la fin du fichier est atteinte sans trouver la salle
  if (!trouve) {
    printf("La salle n'a pas été trouvée.\n");
    fclose(concert);
    return;
  }

  rewind(concert);

  while (strstr(fgets(phrase, sizeof(phrase), concert), nom_concert) == NULL) {
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

/*void supprimerSalle(){
  // ouvrir le fichier
  char nomsalle[21];
  print("Quelle salle voulez-vous supprimer ?\n");
  listeSallem();
  scanf("%s",nomsalle[21]);

  int verif=0, verif2=0;
  char c;
  FILE *salle = fopen("salle.txt", "r");
  if (salle == NULL) {
    exit(1);
  }

  FILE *modif = fopen("modif.txt", "w");
  if (modif == NULL) {
    exit(1);
  }

  char phrase[50];
  int trouve = 0;

  // Lire ligne par ligne jusqu'à la fin du fichier
  while (fgets(phrase, sizeof(phrase), salle) != NULL) {
    // Vérification de la bonne salle
    if (strstr(phrase, salle) != NULL) {
      // printf("La salle existe.\n");
      trouve = 1;
      break;
    }
  }

  // Vérifier si la fin du fichier est atteinte sans trouver la salle
  if (!trouve) {
    printf("La salle n'a pas été trouvée.\n");
    fclose(salle);
    return;
  }

  rewind(salle);

  while (strstr(fgets(phrase, sizeof(phrase), salle), nomsalle) == NULL) {
    fprintf(modif, "%s", phrase);
  }

  for (int i=1; i<=4;i++){
    fgets(phrase,sizeof(phrase),salle);
  }

  while (fgets(phrase, sizeof(phrase), salle) != NULL) {
    fprintf(modif, "%s", phrase);
  }

  fclose(salle);
  fclose(modif);
  ///////////////////////////////////


  salle = fopen("concert.txt", "w");
  if (salle == NULL) {
    printf("Erreur lors de l'ouverture du fichier %s\n", "salle.txt");
    exit(1);
  }

  modif = fopen("mconcert.txt", "r");
  if (modif == NULL) {
    exit(1);
  }

  while (fgets(phrase, sizeof(phrase), modif)!=NULL) {
    fprintf(salle, "%s", phrase);
  }
  fclose(salle);
  fclose(modif);


}*/


//mktime()
//localtime()
