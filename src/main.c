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

	
	
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			printf("[ %d ]",tab[i][j]);
		}
		printf("\n");
	}
	

	
	
	
	for(int i =0;i<x;i++){
		free(tab[i]);
	}
	free(tab);
	
	return 0;
}
