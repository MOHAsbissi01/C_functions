//search_in_file
void chercherEmploye(char *nomFichier, char *prenom) {
    FILE *fichier = fopen(nomFichier, "r");
    char nom[100];
    char pre[100];
    int nbEnfant;
    int trouve = 0;
    while (fscanf(fichier, "%s %s %d", nom, pre, &nbEnfant) != EOF) {
        if (strcmp(prenom, pre) == 0) {
            printf("Employé trouvé : %s %s %d\n", nom, pre, nbEnfant);
            trouve = 1;
            break;
        }
    }
    if (!trouve) {
        printf("Employé non trouvé\n");
    }
    fclose(fichier);
}