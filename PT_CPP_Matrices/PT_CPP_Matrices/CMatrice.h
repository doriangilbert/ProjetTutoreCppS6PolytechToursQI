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

//CMatrice est un patron de classe permettant de manipuler des matrices d'�l�ments de type quelconque (type g�n�rique MTYPE)
template<class MTYPE> class CMatrice
{
	private:
		unsigned int uiMATNbLignes; //Entier non sign�, Nombre de lignes de la matrice
		unsigned int uiMATNbColonnes; //Entier non sign�, Nombre de colonnes de la matrice
		MTYPE** pMATMatrice; //Tableau 2D de MTYPE (type g�n�rique) stockant les �l�ments de la matrice

	public:
		/***********************************************************************
		***** CMATRICE<MTYPE> : Constructeur par d�faut de CMatrice<MTYPE> *****
		************************************************************************
		***** Entr�e :                                                     *****
		***** N�cessite :                                                  *****
		***** Sortie :                                                     *****
		***** Entraine : Le contructeur a initialis� un objet              *****
		***** CMatrice<MTYPE> avec uiMATNbLignes et uiMATNbColonnes �gaux  *****
		***** � 0 et pMATMatrice � NULL                                    *****
		***********************************************************************/
		CMatrice<MTYPE>();

		/***********************************************************************
		***** CMATRICE<MTYPE> : Constructeur de recopie de CMatrice<MTYPE> *****
		************************************************************************
		***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>          *****
		***** N�cessite :                                                  *****
		***** Sortie :                                                     *****
		***** Entraine : Le contructeur a initialis� un objet              *****
		***** CMatrice<MTYPE> correspondant � une copie de l'objet         *****
		***** MATParam OU                                                  *****
		***** Exception MatriceVide : On ne recopie pas une matrice vide   *****
		***********************************************************************/
		CMatrice<MTYPE>(CMatrice<MTYPE> &MATParam);

		/***********************************************************************
		***** CMATRICE<MTYPE> : Constructeur de confort de CMatrice<MTYPE> *****
		************************************************************************
		***** Entr�e : - uiNbLignes, entier non sign�, nombre de lignes de *****
		***** la matrice � cr�er                                           *****
		***** - uiNbColonnes, entier non sign�, nombre de colonnes de la   *****
		***** matrice � cr�er                                              *****
		***** N�cessite : uiNbLignes et uiNbColonnes entiers positifs      *****
		***** Sortie :                                                     *****
		***** Entraine : Le contructeur a initialis� un objet              *****
		***** CMatrice<MTYPE> comportant uiNbLignes et uiNbColonnes OU     *****
		***** Exception MatriceVide : On ne cr�e pas une matrice vide      *****
		***********************************************************************/
		CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes);

		/************************************************************
		***** ~CMATRICE<MTYPE> : Destructeur de CMatrice<MTYPE> *****
		*************************************************************
		***** Entr�e :                                          *****
		***** N�cessite :                                       *****
		***** Sortie :                                          *****
		***** Entraine : Le destructeur a d�sallou� tous les    *****
		***** �l�ments de la matrice                            *****
		************************************************************/
		~CMatrice<MTYPE>();

		/*************************************************************************
		***** MATLIRENBLIGNES : Accesseur direct en lecture de uiMATNbLignes *****
		**************************************************************************
		***** Entr�e :                                                       *****
		***** N�cessite :                                                    *****
		***** Sortie : entier, valeur de l'attribut uiMATNbLignes            *****
		***** Entraine : MATLireNbLignes() = uiMATNbLignes                   *****
		*************************************************************************/
		int MATLireNbLignes();

		/*****************************************************************************
		***** MATLIRENBCOLONNES : Accesseur direct en lecture de uiMATNbColonnes *****
		******************************************************************************
		***** Entr�e :                                                           *****
		***** N�cessite :                                                        *****
		***** Sortie : entier, valeur de l'attribut uiMATNbColonnes              *****
		***** Entraine : MATLireNbLignes() = uiMATNbColonnes                     *****
		*****************************************************************************/
		int MATLireNbColonnes();

		/***************************************************************************************************************************************
		***** MATLIREELEMENT : Fonction permettant de lire un �l�ment � une position donn�e (accesseur indirect en lecture de pMATMatrice) *****
		****************************************************************************************************************************************
		***** Entr�e : - uiIndiceLignes, entier non sign�, indice de la ligne de l'�l�ment � lire                                          *****
		***** - uiIndiceColonnes, entier non sign�, indice de la colonne de l'�l�ment � lire                                               *****
		***** N�cessite : uiIndiceLignes et uiIndiceColonnes entiers positifs correspondants � des lignes et colonnes valides              *****
		***** Sortie : type g�n�rique MTYPE, �l�ment � la ligne uiIndiceLigne et � la colonne uiIndiceColonne                              *****
		***** Entraine : MATLireElement(uiIndiceLigne, uiIndiceColonne) = �l�ment � la ligne et � la colonne donn�s en param�tres OU       *****
		***** Exception DepassementLigneOuColonne : Accede a un element qui n'est pas dans la matrice                                      *****
		***************************************************************************************************************************************/
		MTYPE MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);

		/************************************************************************************************************************************************
		***** MATMODIFIERELEMENT : Fonction permettant de modifier un �l�ment � une position donn�e (accesseur indirect en �criture de pMATMatrice) *****
		*************************************************************************************************************************************************
		***** Entr�e : - uiIndiceLignes, entier non sign�, indice de la ligne de l'�l�ment � modifier                                               *****
		***** - uiIndiceColonnes, entier non sign�, indice de la colonne de l'�l�ment � modifier                                                    *****
		***** - valeur, type g�n�rique MTYPE, valeur de l'�l�ment � modifier                                                                        *****
		***** N�cessite : uiIndiceLignes et uiIndiceColonnes entiers positifs correspondants � des lignes et colonnes valides et valeur est du m�me *****
		***** type que la matrice                                                                                                                   *****
		***** Sortie :                                                                                                                              *****
		***** Entraine : �l�ment � la ligne uiIndiceLigne et � la colonne uiIndiceColonne = valeur  OU                                              *****
		***** Exception DepassementLigneOuColonne : Modifie un element qui n'est pas dans la matrice                                                *****
		************************************************************************************************************************************************/
		void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur);

		/********************************************************************************************************
		***** OPERATOR= : Surcharge de l'op�rateur = de CMatrice<MTYPE> prenant un CMatrice<MTYPE> � droite *****
		*********************************************************************************************************
		***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>                                           *****
		***** N�cessite :                                                                                   *****
		***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                        *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � une copie de l'objet     *****
		***** MATParam   OU                                                                                 *****
		***** Exception MatriceVide : On ne recopie pas une matrice vide                                    *****
		********************************************************************************************************/
		CMatrice<MTYPE>& operator=(CMatrice<MTYPE> &MATParam);

		/************************************************************************************************************************************************
		***** OPERATOR* : Surcharge de l'op�rateur * de CMatrice<MTYPE> prenant un r�el � droite permettant de multiplier une matrice par un nombre *****
		*************************************************************************************************************************************************
		***** Entr�e : dParam, r�el, r�el avec lequel multiplier la matrice                                                                         *****
		***** N�cessite :                                                                                                                           *****
		***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                                *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de la multiplication de la matrice avec le r�el en     *****
		***** param�tre  OU                                                                                                                         *****
		***** Exception MatriceVide : On ne peut pas multiplier une matrice vide                                                                    *****
		************************************************************************************************************************************************/
		CMatrice<MTYPE>& operator*(double dParam);

		/*********************************************************************************************************************************************
		***** OPERATOR/ : Surcharge de l'op�rateur / de CMatrice<MTYPE> prenant un r�el � droite permettant de diviser une matrice par un nombre *****
		**********************************************************************************************************************************************
		***** Entr�e : dParam, r�el, r�el avec lequel diviser la matrice                                                                         *****
		***** N�cessite :                                                                                                                        *****
		***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                             *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de la division de la matrice avec le r�el en        *****
		***** param�tre  OU                                                                                                                      *****
		***** Exception MatriceVide : On ne peut pas diviser une matrice vide                                                                    *****
		***** Exception DivisionPar0 : On ne peut pas diviser par 0                                                                              *****
		*********************************************************************************************************************************************/
		CMatrice<MTYPE>& operator/(double dParam);

		/*****************************************************************************
		***** MATAFFICHER : Fonction permettant d'afficher une matrice � l'�cran *****
		******************************************************************************
		***** Entr�e :                                                           *****
		***** N�cessite :                                                        *****
		***** Sortie :                                                           *****
		***** Entraine : La fonction � affich� le contenu de la matrice �        *****
		***** l'�cran   OU                                                       *****
		***** Exception MatriceVide: On ne peut pas afficher une matrice vide    *****
		*****************************************************************************/
		void MATAfficher();

		/**************************************************************************************
		***** MATTRANSPOSER : Fonction permettant de calculer la transpos�e d'une matrice *****
		***************************************************************************************
		***** Entr�e :                                                                    *****
		***** N�cessite :                                                                 *****
		***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                      *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � la     *****
		***** transpos�e de la matrice (les lignes et les colonnes ont �t� �chang�es) OU  *****
		***** Exception MatriceVide : On ne peut pas transposer une matrice vide          *****
		**************************************************************************************/
		CMatrice<MTYPE>& MATTransposer();

		/****************************************************************************************************************************************
		***** OPERATOR+ : Surcharge de l'op�rateur + de CMatrice<MTYPE> prenant une matrice � droite permettant d'additionner deux matrices *****
		*****************************************************************************************************************************************
		***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>                                                                           *****
		***** N�cessite : La matrice appelante est de la m�me taille que MATParam                                                           *****
		***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                        *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de l' addition de la matrice avec la matrice   *****
		***** en param�tre   OU                                                                                                             *****
		***** Exception TailleNonCorrespondantes :  La Matrice rentr�e en parametre n'est pas de la m�me taille que l'autre                 *****
		****************************************************************************************************************************************/
		CMatrice<MTYPE>& operator+(CMatrice<MTYPE> &MATParam);

		/****************************************************************************************************************************************
		***** OPERATOR- : Surcharge de l'op�rateur - de CMatrice<MTYPE> prenant une matrice � droite permettant de soustraire deux matrices *****
		*****************************************************************************************************************************************
		***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>                                                                           *****
		***** N�cessite : La matrice appelante est de la m�me taille que MATParam                                                           *****
		***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                        *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de la soustraction de la matrice avec la       *****
		***** matrice en param�tre                                                                                                          *****
		***** Exception TailleNonCorrespondantes :  La Matrice rentr�e en parametre n'est pas de la m�me taille que l'autre  OU             *****
		***** Exception MatriceVide :  Une des matrices est vide                                                                            *****
		****************************************************************************************************************************************/
		CMatrice<MTYPE>& operator-(CMatrice<MTYPE> &MATParam);

		/**********************************************************************************************************************************************
		***** OPERATOR* : Surcharge de l'op�rateur * de CMatrice<MTYPE> prenant une matrice � droite permettant de faire le produit deux matrices *****
		***********************************************************************************************************************************************
		***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>                                                                                 *****
		***** N�cessite : La matrice appelante est de la m�me taille que MATParam                                                                 *****
		***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                              *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat du produit de la matrice avec la matrice en          *****
		***** param�tre                                                                                                                           *****
		***** Exception TailleNonCorrespondantes :  La Matrice rentr�e en parametre ne possede pas le m�me nombre de colonne que le nombre de     *****
		***** lignes de la premiere OU                                                                                                            *****
		***** Exception MatriceVide :  Une des matrices est vide                                                                                  *****
		**********************************************************************************************************************************************/
		CMatrice<MTYPE>& operator*(CMatrice<MTYPE> &MATParam); //Produit terme � terme ou produit matriciel

		/********************************************************************************************************************
		***** MATSUPPRIMERCOLONNE : Fonction permettant de supprimer une colonne � une position donn�e dans une matrice *****
		*********************************************************************************************************************
		***** Entr�e : uiPositionColonne, entier non sign�, position dans la matrice de la colonne � supprimer          *****
		***** N�cessite :                                                                                               *****
		***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                    *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � la matrice de d�part soustraite de   *****
		***** la colonne � la position uiPositionColonne OU                                                             *****
		***** Exception DepassementLigneOuColonne : On tente de supprimer une colonne qui n'est pas dans la matrice     *****
		********************************************************************************************************************/
		CMatrice<MTYPE>& MATSupprimerColonne(unsigned int uiPositionColonne);

		/****************************************************************************************************************
		***** MATSUPPRIMERLIGNE : Fonction permettant de supprimer une ligne � une position donn�e dans une matrice *****
		*****************************************************************************************************************
		***** Entr�e : uiPositionLignes, entier non sign�, position dans la matrice de la ligne � supprimer         *****
		***** N�cessite :                                                                                           *****
		***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � la matrice de d�part soustraite  *****
		***** de la ligne � la position uiPositionLignes OU                                                         *****
		***** Exception DepassementLigneOuColonne : On tente de supprimer une ligne qui n'est pas dans la matrice   *****
		****************************************************************************************************************/
		CMatrice<MTYPE>& MATSupprimerLigne(unsigned int uiPositionLignes);

		/*************************************************************************************************************************************
		***** MATDETERMINANTHESSENBERGINFERIEURE : Fonction permettant de calculer le d�terminant d'une matrice de Hessenberg inf�rieure *****
		**************************************************************************************************************************************
		***** Entr�e :                                                                                                                   *****
		***** N�cessite :                                                                                                                *****
		***** Sortie : r�el, valeur du d�terminant de la matrice                                                                         *****
		***** Entraine : MATDeterminantHessenbergInferieure() = d�terminant de la matrice                                                *****
		*************************************************************************************************************************************/
		double MATDeterminantHessenbergInferieure();

};

#include "CMatrice.cpp"

#endif