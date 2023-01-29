// ajoouter un element avec un message de confirmation liee au fichier line9
void ajouter_gateau_ft(gateau g, char nom_fich[]) 
{
    FILE *f = fopen(nom_fich, "a"); // open the file in "append" mode
    if (f != NULL)
     {
        fprintf(f, "%d %d %f\n", g.type, g.nbr_ing, g.prix); // write the cake's information to the file
        fclose(f); // close the file
        printf("Cake added to file %s\n", nom_fich);
    } else {
        printf("Error opening file!\n");
    }
}
