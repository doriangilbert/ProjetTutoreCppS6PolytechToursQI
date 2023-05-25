#ifndef CLecteur_h
#define CLecteur_h

#include "CMatrice.h"
#include "CException.h"

#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable : 4996) //Ligne utilis�e pour �viter l'erreur Visual Studio : C4996 This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS

#define NULL 0;
#define NomFichierManquant 5
#define EchecOuvertureFichier 6
#define FormatFichierInvalide 7
#define TypeMatriceFichierInvalide 8

//CLecteur est une classe utilis�e pour la lecture d'un fichier formatt� afin d'en r�cup�rer une matrice de type CMatrice
class CLecteur 
{
	private:
		char* pcLECNomFichier; //Chaine de caract�res, Nom du fichier � lire

	public:
		/*********************************************************
		***** CLECTEUR : Constructeur par d�faut de CLecteur *****
		**********************************************************
		***** Entr�e :                                       *****
		***** N�cessite :                                    *****
		***** Sortie :                                       *****
		***** Entraine : Le contructeur a initialis� un      *****
		***** objet CLecteur avec pcLECNomFichier �gal       *****
		***** � NULL                                         *****
		*********************************************************/
		CLecteur();

		/*********************************************************
		***** CLECTEUR : Constructeur de recopie de CLecteur *****
		**********************************************************
		***** Entr�e : LECParam, un objet de type CLecteur   *****
		***** N�cessite :                                    *****
		***** Sortie :                                       *****
		***** Entraine : Le contructeur a initialis� un      *****
		***** objet CMatrice<MTYPE> correspondant � une      *****
		***** copie de l'objet LECParam                      *****
		*********************************************************/
		CLecteur(CLecteur &LECParam);

		/*********************************************************
		***** CLECTEUR : Constructeur de confort de CLecteur *****
		**********************************************************
		***** Entr�e : pcNomFichier, chaine de caract�res,   *****
		***** nom du fichier � lire                          *****
		***** N�cessite :                                    *****
		***** Sortie :                                       *****
		***** Entraine : Le contructeur a initialis� un      *****
		***** objet CLecteur ayant                           *****
		***** pcLECNomFichier = pcNomFichier                 *****
		*********************************************************/
		CLecteur(char* pcNomFichier);

		/**********************************************
		***** ~CLECTEUR : Destructeur de CLecteur *****
		***********************************************
		***** Entr�e :                            *****
		***** N�cessite :                         *****
		***** Sortie :                            *****
		***** Entraine : Le destructeur a         *****
		***** d�sallou� les pointeurs             *****
		**********************************************/
		~CLecteur();

		/*****************************************************************************
		***** LECLIRENOMFICHIER : Accesseur direct en lecture de pcLECNomFichier *****
		******************************************************************************
		***** Entr�e :                                                           *****
		***** N�cessite :                                                        *****
		***** Sortie : chaine de caract�res, valeur de l'attribut                *****
		***** pcLECNomFichier                                                    *****
		***** Entraine : LECLireNomFichier() = pcLECNomFichier                   *****
		*****************************************************************************/
		char* LECLireNomFichier();

		/**********************************************************************************
		***** LECMODIFIERNOMFICHIER : Accesseur direct en �criture de pcLECNomFichier *****
		***********************************************************************************
		***** Entr�e : pcNomFichier, chaine de caract�res, nouvelle valeur de         *****
		***** pcLECNomFichier                                                         *****
		***** N�cessite :                                                             *****
		***** Sortie :                                                                *****
		***** Entraine : pcLECNomFichier = pcNomFichier                               *****
		**********************************************************************************/
		void LECModifierNomFichier(char* pcNomFichier);

		/******************************************************************************************
		***** OPERATOR= : Surcharge de l'op�rateur = de CLecteur prenant un CLecteur � droite *****
		*******************************************************************************************
		***** Entr�e : LECParam, un objet de type CLecteur                                    *****
		***** N�cessite :                                                                     *****
		***** Sortie : objet CLecteur, retourn� par r�f�rence                                 *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � une copie  *****
		***** de l'objet LECParam                                                             *****
		******************************************************************************************/
		CLecteur& operator=(CLecteur& LECParam);

		/*************************************************************************************************
		***** LECLIREFICHIERMATRICE : Fonction permettant de cr�er une matrice � partir d'un fichier *****
		**************************************************************************************************
		***** Entr�e :                                                                               *****
		***** N�cessite : - pcLECNomFichier contient un nom de fichier                               *****
		***** - Le format du fichier est valide (TypeMatrice=double, NBLignes et NBColonnes �gaux �  *****
		***** des entiers positifs, la matrice ne contient que des double et le nombre de            *****
		***** lignes/colonnes correspond � NBLignes et NBColonnes                                    *****
		***** Sortie : objet CMatrice<double>, retourn� par r�f�rence                                *****
		***** Entraine : Un objet CMatrice<double> � �t� initialis� correspondant au contenu du      *****
		***** fichier OU                                                                             *****
		***** Exception NomFichierManquant : Nom de fichier manquant OU                              *****
		***** Exception EchecOuvertureFichier : Echec d'ouverture de fichier OU                      *****
		***** Exception FormatFichierInvalide : Format de fichier invalide OU                        *****
		***** Exception TypeMatriceFichierInvalide : Type de matrice non pris en charge (!= double)  *****
		*************************************************************************************************/
		CMatrice<double>& LECLireFichierMatrice(); //M�thode non faite sous la forme d'un constructeur de CMatrice car elle fait appel au constructeur CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes) et on ne peut pas appeler un contructeur sur une classe dans un contructeur de cette m�me classe
};

#endif