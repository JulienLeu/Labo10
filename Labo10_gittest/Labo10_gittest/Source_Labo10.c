/* Fichier : Source_Labo10.c
 * Auteur  : Quentin Müller / Julien Leuenberger
 * Date    : 20.11.2018
 *
 * Description :	Programme qui permet de tester chaque fonctions 
 *						de la librairie "outil_saisie.c"
 *
 * Remarque(s) : (Exemples: "Problèmes rencontés", Erreurs, etc.)
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
#define TAILLE_MIN_CM 40
#define TAILLE_MAX_CM 250
#define TAILLE_MIN_M 0.4
#define TAILLE_MAX_M 2.5

int main(void)
{
	/* Variable du programme */
	int choix_menu;
	char tableau[TAILLE_TABLEAU];

	printf("\n\nProgramme permettant de tester la librairie outils_saisie");

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

		choix_menu = saisirEntier("Choix -> ");

		switch (choix_menu)
		{
			case 0: // Quitter le programme
			{
				if (confirmer("Voulez vous vraiment quitter <O/N> "))
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
				printf("Votre taille: %d cm\n", saisirEntier("Entrer votre taille en cm : "));
				break;
			}
			case 2:
			{
				printf("Votre taille: %d cm\n", saisirEntierBorne("Entrer votre taille en cm [40 -250] : "
					,TAILLE_MIN_CM,TAILLE_MAX_CM));
				break;
			}
			case 3:
			{
				printf("Votre taille: %lf m\n", saisirReel("Entrer votre taille en m : "));
				break;
			}
			case 4:
			{
				printf("Votre taille: %lf m\n", 
					saisirReelBorne("Entrer votre taille en m [0.4 - 2.5] : "
						,TAILLE_MIN_M,TAILLE_MAX_M));
				break;
			}
			case 5:
			{
				saisirString("Texte a afficher ",TAILLE_TABLEAU,tableau);
				printf("%s", tableau);
				break;
			}
			default: // Valeur correspondant à aucun menu
			{
				printf("\nLa valeur saisie n'est pas valide.");
				break;
			}
		}
	} while (choix_menu != 0);
	return EXIT_SUCCESS;
}