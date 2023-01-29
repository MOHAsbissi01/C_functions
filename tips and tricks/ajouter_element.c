//exemple ajouter element with .txt file
void ajouter_gateau_ft(gateau g, char nom_fich[]) 
{
    FILE *f = fopen(nom_fich, "a");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    fprintf(f, "%d %d %f\n", g.type, g.nbr_ing, g.prix);
    fclose(f);
}