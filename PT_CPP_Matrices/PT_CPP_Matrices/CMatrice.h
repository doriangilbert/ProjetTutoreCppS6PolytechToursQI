#ifndef CMatrice_h
#define CMatrice_h

#include "CException.h"

#include <iostream>
using namespace std;

#define NULL 0
#define TailleNonCorrespondantes 1 
#define MatriceVide 2 
#define DepassementLigneOuColonne 3 
#define DivisionPar0 4 
#define MatriceNonCarree 9

//CMatrice est un patron de classe permettant de manipuler des matrices d'éléments de type quelconque (type générique MTYPE)
template<class MTYPE> class CMatrice
{
	private:
		unsigned int uiMATNbLignes; //Entier non signé, Nombre de lignes de la matrice
		unsigned int uiMATNbColonnes; //Entier non signé, Nombre de colonnes de la matrice
		MTYPE** pMATMatrice; //Tableau 2D de MTYPE (type générique) stockant les éléments de la matrice

	public:
		/***********************************************************************
		***** CMATRICE<MTYPE> : Constructeur par défaut de CMatrice<MTYPE> *****
		************************************************************************
		***** Entrée :                                                     *****
		***** Nécessite :                                                  *****
		***** Sortie :                                                     *****
		***** Entraine : Le contructeur a initialisé un objet              *****
		***** CMatrice<MTYPE> avec uiMATNbLignes et uiMATNbColonnes égaux  *****
		***** à 0 et pMATMatrice à NULL                                    *****
		***********************************************************************/
		CMatrice<MTYPE>();

		/***********************************************************************
		***** CMATRICE<MTYPE> : Constructeur de recopie de CMatrice<MTYPE> *****
		************************************************************************
		***** Entrée : MATParam, un objet de type CMatrice<MTYPE>          *****
		***** Nécessite :                                                  *****
		***** Sortie :                                                     *****
		***** Entraine : Le contructeur a initialisé un objet              *****
		***** CMatrice<MTYPE> correspondant à une copie de l'objet         *****
		***** MATParam OU                                                  *****
		***** Exception MatriceVide : On ne recopie pas une matrice vide   *****
		***********************************************************************/
		CMatrice<MTYPE>(CMatrice<MTYPE> &MATParam);

		/***********************************************************************
		***** CMATRICE<MTYPE> : Constructeur de confort de CMatrice<MTYPE> *****
		************************************************************************
		***** Entrée : - uiNbLignes, entier non signé, nombre de lignes de *****
		***** la matrice à créer                                           *****
		***** - uiNbColonnes, entier non signé, nombre de colonnes de la   *****
		***** matrice à créer                                              *****
		***** Nécessite : uiNbLignes et uiNbColonnes entiers positifs      *****
		***** Sortie :                                                     *****
		***** Entraine : Le contructeur a initialisé un objet              *****
		***** CMatrice<MTYPE> comportant uiNbLignes et uiNbColonnes OU     *****
		***** Exception MatriceVide : On ne crée pas une matrice vide      *****
		***********************************************************************/
		CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes);

		/************************************************************
		***** ~CMATRICE<MTYPE> : Destructeur de CMatrice<MTYPE> *****
		*************************************************************
		***** Entrée :                                          *****
		***** Nécessite :                                       *****
		***** Sortie :                                          *****
		***** Entraine : Le destructeur a désalloué tous les    *****
		***** éléments de la matrice                            *****
		************************************************************/
		~CMatrice<MTYPE>();

		/*************************************************************************
		***** MATLIRENBLIGNES : Accesseur direct en lecture de uiMATNbLignes *****
		**************************************************************************
		***** Entrée :                                                       *****
		***** Nécessite :                                                    *****
		***** Sortie : entier, valeur de l'attribut uiMATNbLignes            *****
		***** Entraine : MATLireNbLignes() = uiMATNbLignes                   *****
		*************************************************************************/
		int MATLireNbLignes();

		/*****************************************************************************
		***** MATLIRENBCOLONNES : Accesseur direct en lecture de uiMATNbColonnes *****
		******************************************************************************
		***** Entrée :                                                           *****
		***** Nécessite :                                                        *****
		***** Sortie : entier, valeur de l'attribut uiMATNbColonnes              *****
		***** Entraine : MATLireNbLignes() = uiMATNbColonnes                     *****
		*****************************************************************************/
		int MATLireNbColonnes();

		/***************************************************************************************************************************************
		***** MATLIREELEMENT : Fonction permettant de lire un élément à une position donnée (accesseur indirect en lecture de pMATMatrice) *****
		****************************************************************************************************************************************
		***** Entrée : - uiIndiceLignes, entier non signé, indice de la ligne de l'élément à lire                                          *****
		***** - uiIndiceColonnes, entier non signé, indice de la colonne de l'élément à lire                                               *****
		***** Nécessite : uiIndiceLignes et uiIndiceColonnes entiers positifs correspondants à des lignes et colonnes valides              *****
		***** Sortie : type générique MTYPE, élément à la ligne uiIndiceLigne et à la colonne uiIndiceColonne                              *****
		***** Entraine : MATLireElement(uiIndiceLigne, uiIndiceColonne) = élément à la ligne et à la colonne donnés en paramètres OU       *****
		***** Exception DepassementLigneOuColonne : Accede a un element qui n'est pas dans la matrice                                      *****
		***************************************************************************************************************************************/
		MTYPE MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);

		/************************************************************************************************************************************************
		***** MATMODIFIERELEMENT : Fonction permettant de modifier un élément à une position donnée (accesseur indirect en écriture de pMATMatrice) *****
		*************************************************************************************************************************************************
		***** Entrée : - uiIndiceLignes, entier non signé, indice de la ligne de l'élément à modifier                                               *****
		***** - uiIndiceColonnes, entier non signé, indice de la colonne de l'élément à modifier                                                    *****
		***** - valeur, type générique MTYPE, valeur de l'élément à modifier                                                                        *****
		***** Nécessite : uiIndiceLignes et uiIndiceColonnes entiers positifs correspondants à des lignes et colonnes valides et valeur est du même *****
		***** type que la matrice                                                                                                                   *****
		***** Sortie :                                                                                                                              *****
		***** Entraine : élément à la ligne uiIndiceLigne et à la colonne uiIndiceColonne = valeur  OU                                              *****
		***** Exception DepassementLigneOuColonne : Modifie un element qui n'est pas dans la matrice                                                *****
		************************************************************************************************************************************************/
		void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur);

		/********************************************************************************************************
		***** OPERATOR= : Surcharge de l'opérateur = de CMatrice<MTYPE> prenant un CMatrice<MTYPE> à droite *****
		*********************************************************************************************************
		***** Entrée : MATParam, un objet de type CMatrice<MTYPE>                                           *****
		***** Nécessite :                                                                                   *****
		***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                        *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à une copie de l'objet     *****
		***** MATParam   OU                                                                                 *****
		***** Exception MatriceVide : On ne recopie pas une matrice vide                                    *****
		********************************************************************************************************/
		CMatrice<MTYPE>& operator=(CMatrice<MTYPE> &MATParam);

		/************************************************************************************************************************************************
		***** OPERATOR* : Surcharge de l'opérateur * de CMatrice<MTYPE> prenant un réel à droite permettant de multiplier une matrice par un nombre *****
		*************************************************************************************************************************************************
		***** Entrée : dParam, réel, réel avec lequel multiplier la matrice                                                                         *****
		***** Nécessite :                                                                                                                           *****
		***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                                *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat de la multiplication de la matrice avec le réel en     *****
		***** paramètre  OU                                                                                                                         *****
		***** Exception MatriceVide : On ne peut pas multiplier une matrice vide                                                                    *****
		************************************************************************************************************************************************/
		CMatrice<MTYPE>& operator*(double dParam);

		/*********************************************************************************************************************************************
		***** OPERATOR/ : Surcharge de l'opérateur / de CMatrice<MTYPE> prenant un réel à droite permettant de diviser une matrice par un nombre *****
		**********************************************************************************************************************************************
		***** Entrée : dParam, réel, réel avec lequel diviser la matrice                                                                         *****
		***** Nécessite :                                                                                                                        *****
		***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                             *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat de la division de la matrice avec le réel en        *****
		***** paramètre  OU                                                                                                                      *****
		***** Exception MatriceVide : On ne peut pas diviser une matrice vide                                                                    *****
		***** Exception DivisionPar0 : On ne peut pas diviser par 0                                                                              *****
		*********************************************************************************************************************************************/
		CMatrice<MTYPE>& operator/(double dParam);

		/*****************************************************************************
		***** MATAFFICHER : Fonction permettant d'afficher une matrice à l'écran *****
		******************************************************************************
		***** Entrée :                                                           *****
		***** Nécessite :                                                        *****
		***** Sortie :                                                           *****
		***** Entraine : La fonction à affiché le contenu de la matrice à        *****
		***** l'écran   OU                                                       *****
		***** Exception MatriceVide: On ne peut pas afficher une matrice vide    *****
		*****************************************************************************/
		void MATAfficher();

		/**************************************************************************************
		***** MATTRANSPOSER : Fonction permettant de calculer la transposée d'une matrice *****
		***************************************************************************************
		***** Entrée :                                                                    *****
		***** Nécessite :                                                                 *****
		***** Sortie : objet CMatrice<MTYPE>, retourné par référence                      *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à la     *****
		***** transposée de la matrice (les lignes et les colonnes ont été échangées) OU  *****
		***** Exception MatriceVide : On ne peut pas transposer une matrice vide          *****
		**************************************************************************************/
		CMatrice<MTYPE>& MATTransposer();

		/****************************************************************************************************************************************
		***** OPERATOR+ : Surcharge de l'opérateur + de CMatrice<MTYPE> prenant une matrice à droite permettant d'additionner deux matrices *****
		*****************************************************************************************************************************************
		***** Entrée : MATParam, un objet de type CMatrice<MTYPE>                                                                           *****
		***** Nécessite : La matrice appelante est de la même taille que MATParam                                                           *****
		***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                        *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat de l' addition de la matrice avec la matrice   *****
		***** en paramètre   OU                                                                                                             *****
		***** Exception TailleNonCorrespondantes :  La Matrice rentrée en parametre n'est pas de la même taille que l'autre                 *****
		****************************************************************************************************************************************/
		CMatrice<MTYPE>& operator+(CMatrice<MTYPE> &MATParam);

		/****************************************************************************************************************************************
		***** OPERATOR- : Surcharge de l'opérateur - de CMatrice<MTYPE> prenant une matrice à droite permettant de soustraire deux matrices *****
		*****************************************************************************************************************************************
		***** Entrée : MATParam, un objet de type CMatrice<MTYPE>                                                                           *****
		***** Nécessite : La matrice appelante est de la même taille que MATParam                                                           *****
		***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                        *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat de la soustraction de la matrice avec la       *****
		***** matrice en paramètre                                                                                                          *****
		***** Exception TailleNonCorrespondantes :  La Matrice rentrée en parametre n'est pas de la même taille que l'autre  OU             *****
		***** Exception MatriceVide :  Une des matrices est vide                                                                            *****
		****************************************************************************************************************************************/
		CMatrice<MTYPE>& operator-(CMatrice<MTYPE> &MATParam);

		/**********************************************************************************************************************************************
		***** OPERATOR* : Surcharge de l'opérateur * de CMatrice<MTYPE> prenant une matrice à droite permettant de faire le produit deux matrices *****
		***********************************************************************************************************************************************
		***** Entrée : MATParam, un objet de type CMatrice<MTYPE>                                                                                 *****
		***** Nécessite : La matrice appelante est de la même taille que MATParam                                                                 *****
		***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                              *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat du produit de la matrice avec la matrice en          *****
		***** paramètre                                                                                                                           *****
		***** Exception TailleNonCorrespondantes :  La Matrice rentrée en parametre ne possede pas le même nombre de colonne que le nombre de     *****
		***** lignes de la premiere OU                                                                                                            *****
		***** Exception MatriceVide :  Une des matrices est vide                                                                                  *****
		**********************************************************************************************************************************************/
		CMatrice<MTYPE>& operator*(CMatrice<MTYPE> &MATParam); //Produit terme à terme ou produit matriciel

		/********************************************************************************************************************
		***** MATSUPPRIMERCOLONNE : Fonction permettant de supprimer une colonne à une position donnée dans une matrice *****
		*********************************************************************************************************************
		***** Entrée : uiPositionColonne, entier non signé, position dans la matrice de la colonne à supprimer          *****
		***** Nécessite :                                                                                               *****
		***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                    *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à la matrice de départ soustraite de   *****
		***** la colonne à la position uiPositionColonne OU                                                             *****
		***** Exception DepassementLigneOuColonne : On tente de supprimer une colonne qui n'est pas dans la matrice     *****
		********************************************************************************************************************/
		CMatrice<MTYPE>& MATSupprimerColonne(unsigned int uiPositionColonne);

		/****************************************************************************************************************
		***** MATSUPPRIMERLIGNE : Fonction permettant de supprimer une ligne à une position donnée dans une matrice *****
		*****************************************************************************************************************
		***** Entrée : uiPositionLignes, entier non signé, position dans la matrice de la ligne à supprimer         *****
		***** Nécessite :                                                                                           *****
		***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à la matrice de départ soustraite  *****
		***** de la ligne à la position uiPositionLignes OU                                                         *****
		***** Exception DepassementLigneOuColonne : On tente de supprimer une ligne qui n'est pas dans la matrice   *****
		****************************************************************************************************************/
		CMatrice<MTYPE>& MATSupprimerLigne(unsigned int uiPositionLignes);

		/*************************************************************************************************************************************
		***** MATDETERMINANTHESSENBERGINFERIEURE : Fonction permettant de calculer le déterminant d'une matrice de Hessenberg inférieure *****
		**************************************************************************************************************************************
		***** Entrée :                                                                                                                   *****
		***** Nécessite :                                                                                                                *****
		***** Sortie : réel, valeur du déterminant de la matrice                                                                         *****
		***** Entraine : MATDeterminantHessenbergInferieure() = déterminant de la matrice                                                *****
		*************************************************************************************************************************************/
		double MATDeterminantHessenbergInferieure();

};

#include "CMatrice.cpp"

#endif