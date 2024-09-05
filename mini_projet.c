#include<stdio.h>
// #include"mini_projet_fonction.c"
#include"mini_projet_fonction_version_2.c"
// #include<mini_projet_lib.h>




int main(){
//    clrscr();
system("cls");
// livre* Librairie=malloc(sizeof(livre)*100);
livre Librairie[50];
 //fake data 
 Librairie[0].titre="ahmed story"; Librairie[0].auteur= "test" ; Librairie[0].prix = 33.5 ; Librairie[0].quantite=6; 

 Librairie[1].titre="alice in france"; Librairie[1].auteur= "test" ; Librairie[1].prix = 23.5 ; Librairie[1].quantite=44; 

 Librairie[2].titre="learn c++ "; Librairie[2].auteur= "3abass naadi" ; Librairie[2].prix = 65.5 ; Librairie[2].quantite=220; 

 Librairie[3].titre="tom & jerry"; Librairie[3].auteur= "rachid nadi" ; Librairie[3].prix = 70 ; Librairie[3].quantite=4; 


int taille=4;

char reponce='y';

do
{
    system("cls");
    menu(Librairie,&taille);
   do
   {
    printf("\nest ce que vous voulez continuer utilisation de ce programme ? (y/n) ");
    scanf(" %c", &reponce);
   } while (reponce != 'y' && reponce != 'Y' && reponce != 'n' && reponce != 'N' );
    
} while (reponce == 'y' || reponce == 'Y');


return 0;
}