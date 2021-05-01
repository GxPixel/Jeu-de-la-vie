#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int nbligne;
	int nbcolone;
	int** tab;
	
	scanf("%d",&nbligne);
	scanf("%d",&nbcolone);
	
	tab = alloc(nbligne,nbcolone);    //allocation du tableau
	
	init(tab,nbligne,nbcolone);       // initialisation tableau

	
	
	afficher(tab,nbligne,nbcolone);

	printf("%d\n",verifCasesAdjacentes(tab,1,1,0));		//Test de la fonction verifCasesAdjacantes
	
	
	liberer(tab,nbligne);
	
	return 0;
}
