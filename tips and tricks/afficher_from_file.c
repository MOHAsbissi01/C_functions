//afficher_from_file
void afficherEmploye(char *nomFichier, int nbEnfants) {
    FILE *fichier = fopen(nomFichier, "r");
    char nom[100];
    char pre[100];
    int nbEnfant;
    printf("Employés avec %d enfants ou plus :\n", nbEnfants);
    while (fscanf(fichier, "%s %s %d", nom, pre, &nbEnfant) != EOF) {
        if (nbEnfant >= nbEnfants) {
            printf("%s %s %d\n", nom, pre, nbEnfant);
        }
    }
    fclose(fichier);
}