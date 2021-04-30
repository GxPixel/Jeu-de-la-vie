#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int x;
	int y;
	int** tab;
	
	scanf("%d",&x);
	scanf("%d",&y);
	
	tab = alloc(x,y);    //allocation du tableau
	
	init(tab,x,y);       // initialisation tableau

	
	
	afficher(tab,x,y);

	printf("%d\n",verifCasesAdjacentes(tab,1,1,0));		//Test de la fonction verifCasesAdjacantes
	
	
	for(int i =0;i<x;i++){
		free(tab[i]);
	}
	free(tab);
	
	return 0;
}
