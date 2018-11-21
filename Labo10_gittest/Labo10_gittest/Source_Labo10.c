/* Fichier : Source_Labo10.c
 * Auteur  : Quentin M�ller / Julien Leuenberger
 * Date    : 20.11.2018
 *
 * Description :	Programme qui permet de tester chaque fonctions 
 *						de la librairie "outil_saisie.c"
 *
 * Remarque(s) : (Exemples: "Probl�mes rencont�s", Erreurs, etc.)
 *
 * Modifications : Date / Auteur / Raison
 *
 * Compilateur : Visual Studio 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include "outils_saisie.h"

/* Constantes et Variables globales */
#define TAILLE_TABLEAU 100

int main(void)
{
	/* Variable du programme */
	int choix_menu;
	char tableau[TAILLE_TABLEAU];

	printf("\n\nProgramme permettant de tester la librairie outils_saisie");
	printf("Essai de modif\n");

	do
	{
		/* Interface pour choisir le bon menu */
		printf("\n\n=========== MENU ===========");
		printf("\n1 - Saisie entier");
		printf("\n2 - Saisie entier borne");
		printf("\n3 - Saisie reel");
		printf("\n4 - Saisie reel borne");
		printf("\n5 - Saisie string");
		printf("\n0 - Quitter - Confirmation\n");

		choix_menu = saisieEntier("Choix -> ");

		switch (choix_menu)
		{
			case 0: // Quitter le programme
			{
				if (confirmation("Voulez vous vraiment quitter <O/N> "))
				{
					printf("Vous avez choisit de quitter l'application\n");
				}
				else
				{
					choix_menu = 6;
					printf("Alors on continue");
				}
				break;
			}
			case 1:
			{
				printf("Valeur entree %d\n", saisieEntier("Hauteur "));
				break;
			}
			case 2:
			{
				printf("Valeur entree %d\n", saisieEntierBorne("Hauteur entre 2 et 20 ",2,20));
				break;
			}
			case 3:
			{
				printf("Valeur entree %lf\n", saisieReel("Longueur livre "));
				break;
			}
			case 4:
			{
				printf("Valeur entree %lf\n", 
					saisieReelBorne("Longueur livre entre 1.0 et 50.0 ",1.0,50.0));
				break;
			}
			case 5:
			{
				saisieString("Texte a afficher ",50,tableau);
				printf("%s", tableau);
				break;
			}
			default: // Valeur correspondant � aucun menu
			{
				printf("\nLa valeur saisie n'est pas valide.");
				break;
			}
		}
	} while (choix_menu != 0);
	return EXIT_SUCCESS;
}