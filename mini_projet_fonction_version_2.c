#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int tmp_int;
float tmp_float;
char* tmp_char;

typedef struct
{
    char *titre;
    char *auteur;
    int quantite;
    float prix;

} livre;

void hola()
{
    printf("hello ycode");
}
// CRUD

//###### ajoute ##########

void ajoute_un_livre(livre* Librairie , int* taille ){
livre tmp ;
tmp.titre = malloc(100 * sizeof(char));
tmp.auteur = malloc(100 * sizeof(char));

   
printf("   titre : ");

getchar(); 
scanf("%[^\n]", tmp.titre);
getchar(); 

printf("   auteur : ");    

// getchar(); 
scanf("%[^\n]", tmp.auteur);
getchar(); 

printf("   prix (example 12.75 ) : ");
scanf(" %f",&tmp.prix);

printf("   quantite  : ");
scanf(" %d",&tmp.quantite);

Librairie[*taille] = tmp;

(*taille)++;

}

// void index_par_titre(livre* Librairie , int* taille ,int * index,char * temp){
// getchar(); 
// scanf("%[^\n]", temp);
// getchar(); 
// for (int i = 0; i < *taille; i++)
// {
//     if( strncmp(temp, Librairie[i].titre, strlen(temp) )==0)
//     { 
//         *index=i;
//         break;
//     }
// }
// }

//###### supprimer ##########

void supprimer(livre* Librairie ,int index, int* taille )  {
   for (int i = index; i < *taille - 1 ; i++)
{
    Librairie[i]=Librairie[i+1];

}
free(Librairie + (*taille));
(*taille)--; 
printf("livre est supprime");
} 

void ajoute(livre* Librairie , int* taille ){
printf(" \n========= Ajouter un livre au stock ========= \n");
char reponce='y';
do
{
  ajoute_un_livre(Librairie,taille);
do{
   printf("voulez vous ajouter autre livre ? (y/n) ");
   scanf(" %c", &reponce);
} while (reponce != 'y' && reponce != 'Y' && reponce != 'n' && reponce != 'N' );
    
} while (reponce == 'y' || reponce == 'Y');

}


void Afficher_tous_les_livres(livre* Librairie , int* taille ){
printf(" \n========= ficher tous les livres disponibles ========= \n");

    printf("\n=========================================================================================\n");
    printf("   id |             titre            |            auteur            |  prix    |   quantite   ");
    printf("\n=========================================================================================\n");
for(int i=0;i< *taille ;i++){ //|%40s|%40s|%10.2f|%6d
    printf("   %d  |%30s|%30s|%10.2f|%6d   \n",i,Librairie[i].titre, Librairie[i].auteur, Librairie[i].prix ,Librairie[i].quantite );
    printf("---------------------------------------------------------------------------------------\n");
 
}

}
      
void Rechercher_un_livre_par_so_titre(livre* Librairie , int* taille ){
printf(" \n========= Rechercher un livre par son titre. ========= \n");
char temp[100];
livre recherche_table[100];
int count=0;
printf(" entrer un titre pour recherche : ");

getchar(); 
scanf("%[^\n]", temp);
getchar(); 
for (int i = 0; i < *taille; i++)
{
    if( strncmp(temp, Librairie[i].titre, strlen(temp) )==0)
    {
        recherche_table[count++]=Librairie[i];

    }
}
if(count>0){
printf("\n===================================================================================\n");
printf("      |             titre            |            auteur            |  prix    |   quantite   ");
printf("\n===================================================================================\n");
for(int i=0;i< *taille ;i++){
    printf("      |%30s|%30s|%10.2f|%6d   \n",recherche_table[i].titre, recherche_table[i].auteur, recherche_table[i].prix ,recherche_table[i].quantite );
}
}else{
    printf("aucun livre avec ce titre : %s",temp);
}

}

void Mettre_a_jour_la_quantite_un_livre(livre* Librairie , int* taille ){
printf(" \n========= Mettre a jour la quantite un livre ========= \n");
char temp[100];

int y=-1;
printf(" entrer un titre pour recherche pour mettre a jour : ");

// index_par_titre(Librairie ,taille ,&y,temp);
getchar(); 
scanf("%[^\n]", temp);
getchar(); 
for (int i = 0; i < *taille; i++)
{
    if( strncmp(temp, Librairie[i].titre, strlen(temp) )==0)
    { 
        y=i;
        break;
    }
}
if(y != -1){
    printf(" voila le current quantite %d donne la nouvelle valeur : ",Librairie[y].quantite);
    scanf(" %d",&Librairie[y].quantite);
    printf("apres mettre a jour");
    printf("\n===================================================================================\n");
    printf("     |       titre           |        auteur          |  prix    |   quantite   ");
    printf("\n===================================================================================\n");
    printf("     |       %s           |        %s          |  %.2f    |   %d  \n ",Librairie[y].titre, Librairie[y].auteur, Librairie[y].prix ,Librairie[y].quantite );

}else{
     printf("aucun livre avec ce titre : %s",temp);
}
}
void Supprimer_un_livre_du_stock(livre* Librairie , int* taille){
printf(" \n========= Supprimer un livre du stock. ========= \n");
char temp[100];

int y=-1;
printf(" entrer un titre pour recherche pour suppression : ");

getchar(); 
scanf("%[^\n]", temp);
getchar(); 
for (int i = 0; i < *taille; i++)
{
    if( strncmp(temp, Librairie[i].titre, strlen(temp) )==0)
    { 
        y=i;
        break;
    }
}
// index_par_titre(Librairie ,taille ,&y,temp);

supprimer(Librairie,y,taille);

}
  
void Afficher_le_nombre_total_de_livres_en_stock(livre* Librairie , int* taille){
printf(" \n========= Afficher le nombre total de livres en stock. ========= \n");
if( (*taille) > 0)
{
    int somme_book=0;
for(int i=0;i< *taille ;i++){
   somme_book += Librairie[i].quantite;
}
printf("le nombre total de livres en stock est : %d \n",somme_book);
}else{
    printf("stock est vide");
}

}

    

void menu(livre* Librairie , int* taille ){
int choix;
printf(" ========= Systeme de Gestion de Stock dans une Librairie ========= ");
printf("\n1 : Ajouter un livre au stock.");
printf("\n2 : Afficher tous les livres disponibles.   ");
printf("\n3 : Rechercher un livre par son titre.    ");
printf("\n4 : Mettre a jour la quantite d'un livre.    ");
printf("\n5 : Supprimer un livre du stock.    ");
printf("\n6 : Afficher le nombre total de livres en stock.    ");
printf(" \n\nvotre choix :");
scanf("%d",&choix);

    switch (choix)
    {
    case 1 :
        ajoute(Librairie , taille);
        break;
     case 2 :
        Afficher_tous_les_livres(Librairie , taille);
        break;
     case 3 :
        Rechercher_un_livre_par_so_titre(Librairie , taille);
        break;
     case 4 :
        Mettre_a_jour_la_quantite_un_livre(Librairie , taille);
        break;
     case 5 :
        Supprimer_un_livre_du_stock(Librairie , taille );
        break;
    case 6 :
        Afficher_le_nombre_total_de_livres_en_stock(Librairie , taille);
        break;
    
    default:
        menu(Librairie , taille);
        break;
    }
}
