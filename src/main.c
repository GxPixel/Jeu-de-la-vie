#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int x;
	int y;
	int** tab;
	
	scanf("%d",&x);
	scanf("%d",&y);
	
	tab = malloc(x * sizeof(int*));
	for(int i =0;i<x;i++){
		tab[i] = malloc(y * sizeof(int));
	}

	
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			scanf("%d",&tab[i][j]);
		}
	}
	
	
	
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
