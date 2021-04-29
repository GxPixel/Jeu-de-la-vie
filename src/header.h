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

#endif
