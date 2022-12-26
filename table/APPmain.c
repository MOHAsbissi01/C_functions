#include <stdio.h>
#include <stdlib.h>
#include "HEADSM15.h"
#include <string.h>

void main()
{
    Livre  p_livre,t_livres[50];

    Emprunt p_emprunt,t_emprunts[50];

    int choix,choix1;

    int nl,pos,code_l,ne,num;
    ne=0;
    nl=0;

    do {
        do {
            printf("****MENU****\n");
            printf("1- ajouter livre \n");
            printf("2- affichage de livres\n");
            printf("3- ajouter emprunt\n");
            printf("4-  retourner_emprunt \n");
            printf("5- afficher emprunt \n");
            printf("Tapez votre choix = \n");
            scanf("%d",&choix1);
        }while(choix1<1 || choix1>8);

        switch (choix1) {
             case 1:
                 ajouter_livre( t_livres, &nl) ;
                break;
            case 2:
                afficher_livres(t_livres,  nl );
                break;
            case 3:
                ajouter_emprunt(t_emprunts,&ne,t_livres,nl) ;
                break;

            case 4:
                retourner_emprunt(num, t_emprunts, ne,t_livres, nl) ;
                break;
             case 5:
                 afficher_emprunts_retournes( t_emprunts, ne) ;
                break;
        }

        printf("Voulez vous faire un autre traitement ? (1 si oui 0 si non) =\n");
        scanf("%d",&choix);
    }while(choix==1);
}
