#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int nb_ligne;
	int nb_colone;
	int nb_iteration;
	int torique;
	int** tab;
	
	scanf("%d",&nb_ligne);
	scanf("%d",&nb_colone);
	
	tab = alloc(nb_ligne,nb_colone);    //allocation du tableau
	
	init(tab,nb_ligne,nb_colone);       // initialisation tableau

	scanf("%d",&nb_iteration);
	scanf("%d",&torique);
	
	for(int i =0;i<nb_iteration;i++){
		system("clear");
		afficher(tab,nb_ligne,nb_colone);
		printf("Nombre d'iteration : %d",i);
		usleep(1000000);
		tour(&tab,nb_ligne,nb_colone,torique);

	}
	


	//printf("%d\n",verifCasesAdjacentes(tab,nb_ligne, nb_colone,3,3,torique));		//Test de la fonction verifCasesAdjacantes
	
	
	
	liberer(tab,nb_ligne);   // liberation memoire du tableau
	
	return 0;
}
