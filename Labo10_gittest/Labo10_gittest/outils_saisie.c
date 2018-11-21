/* Fichier : outils_saisie.c
 * Auteur  : Quentin M�ller / Julien Leuenberger
 * Date    : 20.11.2018
 *
 * Description : Librairie qui facilite
 *						- vide le buffer du scanf
 *						- confirmation de la s�lection
 *						- des nombres entier born�s ou non
 *						- des nombres r�els born�s ou non
 *						- des chaines de caract�res (string)
 *
 * Remarque(s) : (Exemples: "Probl�mes rencont�s", Erreurs, etc.)
 *
 * Modifications : Date / Auteur / Raison
 *
 * Compilateur : Visual Studio 2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outils_saisie.h"

void videBuffer(void)
{
	while (getchar() != '\n');
}

int confirmation(char const *invite)
{
	int Conf,saisieDone = 0, saisieOk;
	char Confirmation;
	do
	{
		printf("%s", invite);
		saisieOk = scanf("%c", &Confirmation);
		videBuffer();
		if (saisieOk == 1)
		{
			switch (Confirmation)
			{
				case '1':
				case 'o':
				case 'O':
				{
					Conf = 1;
					saisieDone = 1;
					break;
				}
				case '0':
				case 'n':
				case 'N':
				{
					Conf = 0;
					saisieDone = 1;
					break;
				}
				default :
				{
					printf("Commande pas reconnue");
					break;
				}
			}
		}
		else
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
	} while (!saisieDone);
	return Conf;
}

int saisieEntier(char const *invite)
{
	int Entier_saisit,saisieDone = 0,saisieOk;
	do
	{
		printf("%s", invite);
		saisieOk = scanf("%d", &Entier_saisit);
		videBuffer();
		if (saisieOk != 1)
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
		else
		{
			saisieDone = 1;
		}

	} while (!saisieDone);
	return Entier_saisit;
}

int saisieEntierBorne(char const *invite, int borne_inf, int borne_sup)
{
	int Entier_saisit, saisieDone = 0, saisieOk;

	do
	{
		printf("%s", invite);
		saisieOk = scanf("%d", &Entier_saisit);
		videBuffer();
		if ((saisieOk != 1) || (Entier_saisit < borne_inf) || (Entier_saisit > borne_sup))
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
		else
		{
			saisieDone = 1;
		}

	} while (!saisieDone);
	return Entier_saisit;
}

double saisieReel(char const *invite)
{
	int saisieDone = 0;
	int saisieOk;
	double entree;
	do
	{
		printf("%s", invite);
		saisieOk = scanf("%lf", &entree);
		videBuffer();
		if (saisieOk != 1)
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
		else
		{
			saisieDone = 1;
		}
	} while (!saisieDone);
	return entree;
}

double saisieReelBorne(char const *invite, double borne_inf, double borne_sup)
{
	int saisieDone = 0;
	int saisieOk;
	double entree;
	do
	{
		printf("%s", invite);
		saisieOk = scanf("%lf", &entree);
		videBuffer();
		if ((saisieOk != 1) || (entree < borne_inf) || (entree > borne_sup))
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
		else
		{
			saisieDone = 1;
		}
	} while (!saisieDone);
	return entree;
}

void saisieString(char const *invite, int maxTaille, char *string)
{
	int saisieDone = 0;
	int saisieOk;

	do
	{
		printf("%s ", invite);
		saisieOk = scanf("%s", string);
		videBuffer();
		if ((saisieOk != 1) || (strlen(string) > maxTaille))
		{
			printf("La valeur saisie n'est pas valide.\n");
		}
		else
		{
			saisieDone = 1;
		}
	} while (!saisieDone);
}