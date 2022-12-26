#include <stdio.h>
#include <stdlib.h>
#include "HEADSM15.h"
#include <string.h>


void saisir_livre(Livre* p_livre)
{
    printf("code  \t");
    scanf("%d",&p_livre->code);
    printf("\n");
    printf("emprunt\t");
    scanf("%d",&p_livre->nb_exmp);
}
void chercher_livre(Livre t_livres[], int nl, int code_l, int* pos)
{ int i=0  ;

    (*pos)=-1;
    while((i<nl)&& (*pos==-1))
    {
        if (t_livres[i].code==code_l)
            (*pos)=i;
        else
            i++ ;
    }

}
void ajouter_livre(Livre t_livres[], int* nl)
{  Livre p_livre ;
    int pos ;
    saisir_livre(&p_livre);
    chercher_livre( t_livres, *nl,  p_livre.code, & pos) ;
  if (pos ==-1)
     {
       t_livres[*nl]=p_livre ;
       (*nl) ++ ;
     }
  else
    { t_livres[pos].nb_exmp=t_livres[pos].nb_exmp + p_livre.nb_exmp; }
}
void afficher_livres(Livre t_livres[], int nl)
{
    int i;
    for(i=0;i<nl;i++)
    {
        printf("code %d ",t_livres[i].code);
        printf("emprunt %d",t_livres[i].nb_exmp);
    }
}
void saisir_emprunt(Emprunt* p_emprunt)
{
     int i;
          printf("numero \n");
         scanf("%d",&p_emprunt->numero);
         printf("code\n");
         scanf("%d",&p_emprunt->code_livre);
         printf(" l'id_abonne\n");
         fflush(stdin);
         gets(p_emprunt->id_abonne);
         p_emprunt->etat=0;
}

void ajouter_emprunt(Emprunt t_emprunts[], int* ne, Livre t_livres[], int nl)
{  Emprunt p_emprunt ;
    int pos  , pos1;

    saisir_emprunt(&p_emprunt);
    chercher_emprunt(p_emprunt.numero, t_emprunts, *ne, &pos);
    if(pos!=-1)
 {
     printf("  un message d�erreur s�affichera \n");
 }
 else
 {chercher_livre(t_livres,ne,p_emprunt.code_livre,&pos1);
     if((pos1!=1) && (t_livres[pos1].nb_exmp>=1))
     {
        t_livres[pos1].nb_exmp--;
        t_emprunts[*ne]=p_emprunt;
        (*ne)++;
     }
     else
     {
         printf(" un message d�erreur s�affichera\n");
     }
 }
}
void chercher_emprunt(int num, Emprunt t_emprunts[], int ne, int* pos)
{
    int i=0 ;

    (*pos)=-1;
    while((i<ne)&&(*pos==-1))
    {
        if ( t_emprunts[i].numero==num)
            (*pos)=i;
        else
            i++ ;
    }

}
void retourner_emprunt(int num, Emprunt t_emprunts[], int ne, Livre t_livres[],int nl)
{

int pos1, pos2,code_l;
    chercher_emprunt(num,t_emprunts,ne,&pos1) ;
    if ((pos1!=-1)&&(t_emprunts[pos1].etat==0))
    {
        chercher_livre(t_livres,ne,t_emprunts[pos1].code_livre,&pos2);
        if (pos2!=1)
        {
            t_livres[pos2].nb_exmp++;
            t_emprunts[pos1].etat=1;

        }

     }
        else
        {
            printf("un message d�erreur s�affichera\n");
        }

     }
void afficher_emprunts_retournes(Emprunt t_emprunts[], int ne)
{
     int i;
    for(i=0;i<ne;i++)
    {   if ( t_emprunts[i].etat==1){
        printf("code %d ",t_emprunts[i].code_livre);
        printf("identifiant %d",t_emprunts[i].id_abonne);
        printf("numero %d",t_emprunts[i].numero);
        printf("etat %d",t_emprunts[i].etat);
    }
    }
}
