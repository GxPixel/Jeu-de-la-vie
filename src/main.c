#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char** argv){
	int nb_ligne;
	int nb_colone;
	int nb_iteration;
	int torique;
	int** tab;
	
	scanf("%d",&nb_ligne);				// scan du nombre de ligne
	scanf("%d",&nb_colone);				// scan du nombre de colone
	
	tab = alloc(nb_ligne,nb_colone);    //allocation du tableau
	
	init(tab,nb_ligne,nb_colone);       // initialisation tableau

	scanf("%d",&nb_iteration);          // scan du nombre d'iteration
	scanf("%d",&torique);               // scan de si c'est torique ou non
	
	for(int i =1;i<=nb_iteration;i++){       		// Boucle for qui tourne <nb_iteration> fois
		system("clear");
		afficher(tab,nb_ligne,nb_colone);			
		printf("Nombre d'itérations : %d\n",i);     // affiche le nombre d'itération actuel
		usleep(100000);
		tour(&tab,nb_ligne,nb_colone,torique);		// appel de la fonction tour qui modifie le tableau 1 fois

	}
	

	liberer(tab,nb_ligne);   // liberation memoire du tableau
	
	return 0;
}
