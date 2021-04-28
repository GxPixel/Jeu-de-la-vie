#include "header.h"
#include <stdio.h>

int** alloc(int lignes, int colones){
	int** tab;
	
	tab = malloc(lignes * sizeof(int*));
	for(int i =0;i<lignes;i++){
		tab[i] = malloc(colones * sizeof(int));
	}
	
	return tab;
}

void init(int** tab, int lignes, int colones){
	for(int i=0;i<lignes;i++){
		for(int j=0;j<colones;j++){
			scanf("%d",&tab[i][j]);
		}
	}
}
