#ifndef CLecteur_h
#define CLecteur_h

#include "CMatrice.h"
#include "CException.h"

#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable : 4996) //Ligne utilisée pour éviter l'erreur Visual Studio : C4996 This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS

#define NULL 0;
#define NomFichierManquant 5
#define EchecOuvertureFichier 6
#define FormatFichierInvalide 7
#define TypeMatriceFichierInvalide 8

//CLecteur est une classe utilisée pour la lecture d'un fichier formatté afin d'en récupérer une matrice de type CMatrice
class CLecteur 
{
	private:
		char* pcLECNomFichier; //Chaine de caractères, Nom du fichier à lire

	public:
		/*********************************************************
		***** CLECTEUR : Constructeur par défaut de CLecteur *****
		**********************************************************
		***** Entrée :                                       *****
		***** Nécessite :                                    *****
		***** Sortie :                                       *****
		***** Entraine : Le contructeur a initialisé un      *****
		***** objet CLecteur avec pcLECNomFichier égal       *****
		***** à NULL                                         *****
		*********************************************************/
		CLecteur();

		/*********************************************************
		***** CLECTEUR : Constructeur de recopie de CLecteur *****
		**********************************************************
		***** Entrée : LECParam, un objet de type CLecteur   *****
		***** Nécessite :                                    *****
		***** Sortie :                                       *****
		***** Entraine : Le contructeur a initialisé un      *****
		***** objet CMatrice<MTYPE> correspondant à une      *****
		***** copie de l'objet LECParam                      *****
		*********************************************************/
		CLecteur(CLecteur &LECParam);

		/*********************************************************
		***** CLECTEUR : Constructeur de confort de CLecteur *****
		**********************************************************
		***** Entrée : pcNomFichier, chaine de caractères,   *****
		***** nom du fichier à lire                          *****
		***** Nécessite :                                    *****
		***** Sortie :                                       *****
		***** Entraine : Le contructeur a initialisé un      *****
		***** objet CLecteur ayant                           *****
		***** pcLECNomFichier = pcNomFichier                 *****
		*********************************************************/
		CLecteur(char* pcNomFichier);

		/**********************************************
		***** ~CLECTEUR : Destructeur de CLecteur *****
		***********************************************
		***** Entrée :                            *****
		***** Nécessite :                         *****
		***** Sortie :                            *****
		***** Entraine : Le destructeur a         *****
		***** désalloué les pointeurs             *****
		**********************************************/
		~CLecteur();

		/*****************************************************************************
		***** LECLIRENOMFICHIER : Accesseur direct en lecture de pcLECNomFichier *****
		******************************************************************************
		***** Entrée :                                                           *****
		***** Nécessite :                                                        *****
		***** Sortie : chaine de caractères, valeur de l'attribut                *****
		***** pcLECNomFichier                                                    *****
		***** Entraine : LECLireNomFichier() = pcLECNomFichier                   *****
		*****************************************************************************/
		char* LECLireNomFichier();

		/**********************************************************************************
		***** LECMODIFIERNOMFICHIER : Accesseur direct en écriture de pcLECNomFichier *****
		***********************************************************************************
		***** Entrée : pcNomFichier, chaine de caractères, nouvelle valeur de         *****
		***** pcLECNomFichier                                                         *****
		***** Nécessite :                                                             *****
		***** Sortie :                                                                *****
		***** Entraine : pcLECNomFichier = pcNomFichier                               *****
		**********************************************************************************/
		void LECModifierNomFichier(char* pcNomFichier);

		/******************************************************************************************
		***** OPERATOR= : Surcharge de l'opérateur = de CLecteur prenant un CLecteur à droite *****
		*******************************************************************************************
		***** Entrée : LECParam, un objet de type CLecteur                                    *****
		***** Nécessite :                                                                     *****
		***** Sortie : objet CLecteur, retourné par référence                                 *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à une copie  *****
		***** de l'objet LECParam                                                             *****
		******************************************************************************************/
		CLecteur& operator=(CLecteur& LECParam);

		/*************************************************************************************************
		***** LECLIREFICHIERMATRICE : Fonction permettant de créer une matrice à partir d'un fichier *****
		**************************************************************************************************
		***** Entrée :                                                                               *****
		***** Nécessite : - pcLECNomFichier contient un nom de fichier                               *****
		***** - Le format du fichier est valide (TypeMatrice=double, NBLignes et NBColonnes égaux à  *****
		***** des entiers positifs, la matrice ne contient que des double et le nombre de            *****
		***** lignes/colonnes correspond à NBLignes et NBColonnes                                    *****
		***** Sortie : objet CMatrice<double>, retourné par référence                                *****
		***** Entraine : Un objet CMatrice<double> à été initialisé correspondant au contenu du      *****
		***** fichier OU                                                                             *****
		***** Exception NomFichierManquant : Nom de fichier manquant OU                              *****
		***** Exception EchecOuvertureFichier : Echec d'ouverture de fichier OU                      *****
		***** Exception FormatFichierInvalide : Format de fichier invalide OU                        *****
		***** Exception TypeMatriceFichierInvalide : Type de matrice non pris en charge (!= double)  *****
		*************************************************************************************************/
		CMatrice<double>& LECLireFichierMatrice(); //Méthode non faite sous la forme d'un constructeur de CMatrice car elle fait appel au constructeur CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes) et on ne peut pas appeler un contructeur sur une classe dans un contructeur de cette même classe
};

#endif