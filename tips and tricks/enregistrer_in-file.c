//exemple of saving in .txt files
void enregistrerEmploye(char *nomFichier, Employe employe) {
    FILE *fichier = fopen(nomFichier, "a");
    fprintf(fichier, "%s %s %d\n", employe.nom, employe.prenom, employe.nbEnfant);
    fclose(fichier);
}