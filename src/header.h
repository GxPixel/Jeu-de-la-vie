#ifndef HEADER_H
#define HEADER_H

/* Nom : Faucher Noé
 * Date : 28/04/2021 12:22
 * 
 * Allocation du tableau
 */
int** alloc(int lignes, int colones);

/* Nom : Faucher Noé
 * Date : 28/04/2021 12:30
 * 
 * Initialisation du tableau
 */
void init(int** tab, int lignes, int colones);

/*  Nom : Hennuy Baptiste
	Date : 29/04/2021 14:26
	
	Affiche la grille
*/
void afficher(int** tab, int lignes, int colones);

/*	Nom : Hennuy Baptiste
 *	Date : 30/04/2021	17:30 
 *
 *	Vérifie les cases adjacentes d'une certaine case et retourne le nombre de cases pleines adjacentes
 *	Paramètres d'entrée: tableau de pointeurs, x de la case à vérifier, y de la case à vérifier, grille torique (0 = non torique, 1 = torique)
 */
int verifCasesAdjacentes(int** tab, int x, int y, int torique);


#endif
