/* Fichier : outils_saisie.h
* Auteur   : Didier Mettler
* Date     : 08.11.2016
*
* But      : Prototypes des fonctions permettant de saisir des entiers et
*			 des réels, précédées d'une phrase précisant la demande.
*
* Remarque(s) :
*
* Modifications : Date / Auteur / Raison
*		  26.04.2017/DMT : Pour Visual Studio 2017
* Compilateur : Visual Studio 2017
*/

#ifndef __OUTIL_SAISIE_H_
#define __OUTIL_SAISIE_H_

//---------------------------------------------------------------------
// Vide le ligne courante du tampon d'entree
void videBuffer(void);

//---------------------------------------------------------------------
// Affiche un message et confirme (oui/non) le chois de l'utilisateur
int confirmation(char const *invite);

//---------------------------------------------------------------------
// Lecture sans erreur d'un entier signe avec demande préalable
// Le reste de la ligne est vide
int saisieEntier(char const *invite);

//---------------------------------------------------------------------
// Lecture sans erreur d'un entier signe entre 2 bornes;
//     avec demande préalable
// Le reste de la ligne est vide
int saisieEntierBorne(char const *invite, int borne_inf, int borne_sup);

//---------------------------------------------------------------------
// Lecture sans erreur d'un reel (simple ou double) avec demande préalable
// Le reste de la ligne est vide
double saisieReel(char const *invite);

//---------------------------------------------------------------------
// Lecture sans erreur d'un reel (simple ou double) entre 2 bornes;
//     avec demande préalable
// Le reste de la ligne est vide
double saisieReelBorne(char const *invite, double borne_inf, double borne_sup);

//---------------------------------------------------------------------
// Lecture sans erreur d'une chaîne de caractères (phrase) de taille max 
//     avec demande préalable
void saisieString(char const *invite, int maxTaille, char *string);

#endif