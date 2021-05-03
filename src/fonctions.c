#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int** alloc(int nb_ligne, int nb_colone){
	int** tab;
	
	tab = malloc(nb_ligne * sizeof(int*));
	for(int i =0;i<nb_ligne;i++){
		tab[i] = malloc(nb_colone * sizeof(int));
	}
	
	return tab;
}

void init(int** tab, int nb_ligne, int nb_colone){
	for(int i=0;i<nb_ligne;i++){
		for(int j=0;j<nb_colone;j++){
			scanf("%d",&tab[i][j]);
		}
	}
}

void liberer(int** tab, int nb_ligne){
	for(int i =0;i<nb_ligne;i++){
			free(tab[i]);
		}
	free(tab);	
}

void afficher(int** tab, int nb_ligne, int nb_colone){
	    for(int i=0; i<nb_ligne; i++){
			printf("+");			
			for(int colone=0; colone<nb_colone; colone++){
				printf("---+");
			}
		    	printf("\n");			
			for(int j=0; j<nb_colone; j++){				
				printf("|");
				if (tab[i][j] == 1){
					printf(" 0 ");
				}				
				else{
					printf("   ");
				}
			}
			printf("|\n");
		}
		printf("+");			
		for(int colone=0; colone<nb_colone; colone++){
			printf("---+");
		}
		printf("\n");
}

int verifCasesAdjacentes(int** tab, int nb_ligne, int nb_colone, int colone, int ligne, int torique){
	int nbCasesAdjPleines = 0;
	if (torique){

	}
	
	else{
		if (colone == 0) nbCasesAdjPleines =tab[colone][ligne-1] + tab[colone+1][ligne-1]+ tab[colone+1][ligne] + tab[colone][ligne+1] + tab[colone+1][ligne+1];																		//verif si la case est sur la ligne du haut
		else{
			if (colone == nb_ligne-1) nbCasesAdjPleines = tab[colone-1][ligne-1] + tab[colone][ligne-1] + tab[colone-1][ligne]+ tab[colone-1][ligne+1] + tab[colone][ligne+1];															//verif si la case est sur la ligne du bas
			else{
				if (ligne == 0) nbCasesAdjPleines =tab[colone-1][ligne] + tab[colone+1][ligne] + tab[colone-1][ligne+1] + tab[colone][ligne+1] + tab[colone+1][ligne+1];																//verif si la case est sur la colone de gauche
				else{
					if (ligne == nb_colone-1) nbCasesAdjPleines = tab[colone-1][ligne-1] + tab[colone][ligne-1] + tab[colone+1][ligne-1] + tab[colone-1][ligne] + tab[colone+1][ligne];												//verif si la case est sur la colone de droite
					else{
						if (colone == 0 && ligne == 0) nbCasesAdjPleines = tab [colone+1][ligne] + tab[colone][ligne+1] + tab[colone+1][ligne+1];																		//verif si on est en haut à gauche
						else{
							if (colone == nb_ligne-1 && ligne == 0) nbCasesAdjPleines = tab [colone-1][ligne] + tab[colone][ligne+1] + tab[colone-1][ligne+1];															//verif si on est en bas à gauche
							else{
								if (colone == 0 && ligne == nb_colone-1) nbCasesAdjPleines = tab [colone][ligne-1] + tab[colone+1][ligne-1] + tab[colone+1][ligne];														//verif si on est en haut à droite
								else{
									if (colone == nb_ligne-1 && ligne == nb_colone-1) nbCasesAdjPleines = tab [colone-1][ligne-1] + tab[colone][ligne-1] + tab[colone-1][ligne];											//verif si on est en bas à droite
									else{
										nbCasesAdjPleines = tab[colone-1][ligne-1] + tab[colone][ligne-1] + tab[colone+1][ligne-1] + tab[colone-1][ligne] + tab[colone+1][ligne] + tab[colone-1][ligne+1] + tab[colone][ligne+1] + tab[colone+1][ligne+1];	//verif pour tout le reste
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return nbCasesAdjPleines;
}


int nouvellevaleur(int nb_voisin,int valeur_case){
	if(valeur_case == 0){                       // Si la case est vide au départ
		if(nb_voisin == 3){							// Si elle a 3 voisins
			return 1;									// On creé un nouvelle cellule
		}else{										// Sinon
			return 0;									// La case reste vide
		}
	}else{										// Si il ligne a deja un cellule
		if(nb_voisin == 3 || nb_voisin == 2){		// Si il ligne a 2 ou 3 voisins
			return 1;									// La cellule reste en vie
		}else{									//Sinon
			return 0;								// La cellule meurt
		}
	}
}

void tour(int** tab,int nb_ligne,int nb_colone,int torique){
	int** t_temp;
	t_temp = alloc(nb_ligne,nb_colone);   //allocation du tableau temporaire

	// initialisation des valeur du tableau temporaire
	for(int i=0;i<nb_ligne;i++){
		for(int j=0;j<nb_colone;j++){
			int nb_voisin = verifCasesAdjacentes(tab,nb_ligne,nb_colone,i,j,torique);
			int valeur_case = tab[i][j];
			t_temp[i][j]= nouvellevaleur(nb_voisin,valeur_case);
		}
	}

	tab = t_temp;   // le tableau prend ses nouvelles valeurs

	liberer(t_temp,nb_ligne);   // liberation tableau temporaire
}
