int nbre_gateaux_ft(char nom_fich[]) {
    int nbre_gateaux = 0;
    FILE *f = fopen(nom_fich, "r");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return -1;
    }//pour cette  fonction calculer nbre_gateaux methode 1
    int c;
    while ((c = getc(f)) != EOF) {
        if (c == '\n')
            nbre_gateaux++;
    }
    fclose(f);
    return nbre_gateaux;
}
//pour cette  fonction calculer nbre_gateaux 2
int nbre_gateaux = 0;
char c;
FILE *f = fopen(nom_fich, "r");
if (f==NULL) 
{
    for (c=getc(f);c != EOF; c=getc(f))
    { if (c=="\n")
nbre_gateaux ++ ;}
} else printf('error');
