#include<stdio.h>
#include"mini_projet_fonction.c"




int main(){
   
// livre* Librairie=malloc(sizeof(livre)*100);
livre Librairie[50];

int taille=0;

char reponce='y';

do
{
    menu(Librairie,&taille);
   do
   {
    printf("\nest ce que vous voulez continuer utilisation de ce programme ? (y/n) ");
    scanf(" %c", &reponce);
   } while (reponce != 'y' && reponce != 'Y' && reponce != 'n' && reponce != 'N' );
    
} while (reponce == 'y' || reponce == 'Y');


return 0;
}