#ifndef MINI_PROJET_LIB_H
#define MINI_PROJET_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tmp_int;
float tmp_float;
char *tmp_char;

typedef struct
{
    char *titre;
    char *auteur;
    int quantite;
    float prix;

} livre;

       
       void ajoute(livre*, int*);
       void Afficher_tous_les_livres(livre*, int*);
       void Rechercher_un_livre_par_so_titre(livre*, int*);
       void Mettre_a_jour_la_quantite_un_livre(livre*, int*);
       void Supprimer_un_livre_du_stock(livre*, int*);
       void Afficher_le_nombre_total_de_livres_en_stock(livre*, int*);
       void menu(livre*, int*);


#endif