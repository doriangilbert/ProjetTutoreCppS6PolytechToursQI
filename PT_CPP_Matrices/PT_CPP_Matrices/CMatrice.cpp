#ifndef CMatrice_cpp
#define CMatrice_cpp

#include "CMatrice.h"
#include <math.h>

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
template<class MTYPE> CMatrice<MTYPE>::CMatrice()
{
	uiMATNbLignes = 0;
	uiMATNbColonnes = 0;
	pMATMatrice = NULL;
};

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
template<class MTYPE> CMatrice<MTYPE>::CMatrice(CMatrice<MTYPE>& MATParam)
{
	//On teste si la matrice est vide 
	if (MATParam.MATLireNbColonnes() == 0 || MATParam.MATLireNbLignes() == 0) {
		uiMATNbColonnes = 0;
		uiMATNbLignes = 0;
		pMATMatrice = NULL;
	}
	else {
		uiMATNbColonnes = MATParam.MATLireNbColonnes();
		uiMATNbLignes = MATParam.MATLireNbLignes();
		pMATMatrice = new MTYPE*[uiMATNbLignes];
		for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
			pMATMatrice[uiBoucleIndiceLigne] = new MTYPE[uiMATNbColonnes];
		}
		for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
			for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
				pMATMatrice[uiBoucleIndiceLigne][uiBoucleIndiceColonne] = MATParam.MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne);
			}
		}
	}
	
};

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
template<class MTYPE> CMatrice<MTYPE>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	//On teste si la matrice est vide
	if (uiNbLignes == 0 || uiNbColonnes == 0) {
		uiMATNbColonnes = 0;
		uiMATNbLignes = 0;
		pMATMatrice = NULL;
	}
	else {
		uiMATNbLignes = uiNbLignes;
		uiMATNbColonnes = uiNbColonnes;
		pMATMatrice = new MTYPE*[uiMATNbLignes];
		for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
			pMATMatrice[uiBoucleIndiceLigne] = new MTYPE[uiMATNbColonnes];
		}
		for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
			for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
				pMATMatrice[uiBoucleIndiceLigne][uiBoucleIndiceColonne] = NULL;
			}
		}
	}
};

/************************************************************
***** ~CMATRICE<MTYPE> : Destructeur de CMatrice<MTYPE> *****
*************************************************************
***** Entr�e :                                          *****
***** N�cessite :                                       *****
***** Sortie :                                          *****
***** Entraine : Le destructeur a d�sallou� tous les    *****
***** �l�ments de la matrice                            *****
************************************************************/
template<class MTYPE> CMatrice<MTYPE>::~CMatrice()
{
	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiMATNbLignes;uiBoucleLignes++) {
		delete[] pMATMatrice[uiBoucleLignes];
	}
	delete[] pMATMatrice;
};

/*************************************************************************
***** MATLIRENBLIGNES : Accesseur direct en lecture de uiMATNbLignes *****
**************************************************************************
***** Entr�e :                                                       *****
***** N�cessite :                                                    *****
***** Sortie : entier, valeur de l'attribut uiMATNbLignes            *****
***** Entraine : MATLireNbLignes() = uiMATNbLignes                   *****
*************************************************************************/
template<class MTYPE> int CMatrice<MTYPE>::MATLireNbLignes()
{
	return uiMATNbLignes;
};

/*****************************************************************************
***** MATLIRENBCOLONNES : Accesseur direct en lecture de uiMATNbColonnes *****
******************************************************************************
***** Entr�e :                                                           *****
***** N�cessite :                                                        *****
***** Sortie : entier, valeur de l'attribut uiMATNbColonnes              *****
***** Entraine : MATLireNbLignes() = uiMATNbColonnes                     *****
*****************************************************************************/
template<class MTYPE> int CMatrice<MTYPE>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
};

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
template<class MTYPE> MTYPE CMatrice<MTYPE>::MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne)
{
	//On teste si on ne depasse pas la taille m�moire de la matrice
	if (uiIndiceLigne >= uiMATNbLignes || uiIndiceColonne >= uiMATNbColonnes) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementLigneOuColonne);
		throw EXCErreur;
	}
	return pMATMatrice[uiIndiceLigne][uiIndiceColonne];
};

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
template<class MTYPE> void CMatrice<MTYPE>::MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur)
{
	//On teste si on ne depasse pas la taille m�moire de la matrice
	if (uiIndiceLigne >= uiMATNbLignes || uiIndiceColonne >= uiMATNbColonnes) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementLigneOuColonne);
		throw EXCErreur;
	}
	pMATMatrice[uiIndiceLigne][uiIndiceColonne] = valeur;
};

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
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator=(CMatrice<MTYPE>& MATParam) 
{
	//On teste si la matrice est vide
	if (MATParam.MATLireNbColonnes() == 0 || MATParam.MATLireNbLignes() == 0) {
		uiMATNbColonnes = 0;
		uiMATNbLignes = 0;
		pMATMatrice = NULL;
		return *this;
	}

	//si la matrice n'est pas vide on vide la matrice avant de recopie l'autre matrice
	if (pMATMatrice != nullptr) {
		for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
			delete[] pMATMatrice[uiBoucleIndiceLigne];
		}
		delete [] pMATMatrice;
	}
	

	uiMATNbColonnes = MATParam.MATLireNbColonnes();
	uiMATNbLignes = MATParam.MATLireNbLignes();

	pMATMatrice = new MTYPE*[uiMATNbLignes];
	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		pMATMatrice[uiBoucleIndiceLigne] = new MTYPE[uiMATNbColonnes];
	}

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
			pMATMatrice[uiBoucleIndiceLigne][uiBoucleIndiceColonne] = MATParam.MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne);
		}
	}
	return *this;
};

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
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator*(double dParam) 
{
	//On teste si la matrice est vide
	if (uiMATNbColonnes == 0 || uiMATNbLignes == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(MatriceVide);
		throw EXCErreur;
	}
	CMatrice<MTYPE>* M1=new CMatrice<MTYPE>(uiMATNbLignes,uiMATNbColonnes);

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
			M1->MATModifierElement(uiBoucleIndiceLigne,uiBoucleIndiceColonne, pMATMatrice[uiBoucleIndiceLigne][uiBoucleIndiceColonne]*dParam);
		}
	}
	return *M1;
};

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
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator/(double dParam)
{
	//On teste si l'entier est 0 car on ne peut pas diviser par 0 
	if (dParam == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DivisionPar0);
		throw EXCErreur;
	}

	if (uiMATNbColonnes == 0 || uiMATNbLignes == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(MatriceVide);
		throw EXCErreur;
	}
	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
			M1->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, (MTYPE)(pMATMatrice[uiBoucleIndiceLigne][uiBoucleIndiceColonne] / dParam));
		}
	}
	return *M1;
};

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
template<class MTYPE> void CMatrice<MTYPE>::MATAfficher() 
{
	//On teste si la matrice est vide
	if (uiMATNbColonnes == 0 || uiMATNbLignes == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(MatriceVide);
		throw EXCErreur;
	}
	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
			cout << pMATMatrice[uiBoucleIndiceLigne][uiBoucleIndiceColonne] << " ";
		}
		cout << "\n";
	}
}

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
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::MATTransposer()
{	
	//On teste si la matrice est vide
	if (uiMATNbColonnes == 0 || uiMATNbLignes == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(MatriceVide);
		throw EXCErreur;
	}

	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbColonnes,uiMATNbLignes);

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
			M1->MATModifierElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne, pMATMatrice[uiBoucleIndiceLigne][uiBoucleIndiceColonne]);
		}
	}
	return *M1;
};

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
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator+(CMatrice<MTYPE> &MATParam) 
{
	//On teste si les matrices sont de m�me taille
	if (uiMATNbColonnes != MATParam.MATLireNbColonnes() || uiMATNbLignes != MATParam.MATLireNbLignes()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(TailleNonCorrespondantes);
		throw EXCErreur;
	}

	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
			M1->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, pMATMatrice[uiBoucleIndiceLigne][uiBoucleIndiceColonne]+ MATParam.MATLireElement(uiBoucleIndiceLigne,uiBoucleIndiceColonne));
		}
	}
	return *M1;
};

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
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator-(CMatrice<MTYPE> &MATParam) 
{
	//On teste si une des matrice est vide
	if (uiMATNbColonnes == 0 || uiMATNbLignes == 0 || MATParam.MATLireNbColonnes() == 0 || MATParam.MATLireNbLignes() == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(MatriceVide);
		throw EXCErreur;
	}
	
	if (uiMATNbColonnes != MATParam.MATLireNbColonnes() || uiMATNbLignes != MATParam.MATLireNbLignes()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(TailleNonCorrespondantes);
		throw EXCErreur;
	}

	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
			M1->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, pMATMatrice[uiBoucleIndiceLigne][uiBoucleIndiceColonne] - MATParam.MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne));
		}
	}
	return *M1;
}

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
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator*(CMatrice<MTYPE> &MATParam) 
{
	//On teste si une des matrice est vide
	if (uiMATNbColonnes == 0 || uiMATNbLignes == 0 || MATParam.MATLireNbColonnes() == 0 || MATParam.MATLireNbLignes() == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(MatriceVide);
		throw EXCErreur;
	}
	if (uiMATNbLignes != MATParam.MATLireNbColonnes()) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(TailleNonCorrespondantes);
		throw EXCErreur;
	}
	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, MATParam.MATLireNbColonnes());

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < MATParam.MATLireNbColonnes(); uiBoucleIndiceColonne++) {
			MTYPE C=pMATMatrice[uiBoucleIndiceLigne][0]* MATParam.MATLireElement(0, uiBoucleIndiceColonne);
			for (unsigned int uiKiemeColonne = 1; uiKiemeColonne < uiMATNbColonnes; uiKiemeColonne++) {
				C = C + pMATMatrice[uiBoucleIndiceLigne][uiKiemeColonne] * MATParam.MATLireElement(uiKiemeColonne, uiBoucleIndiceColonne);
			}
			M1->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, C);
		}
	}
	return *M1;
}

/*****************************************************************************************************************************************************
***** OPERATOR* : Surcharge de l'op�rateur * prenant un r�el � gauche et une matrice � droite permettant de multiplier une matrice par un nombre *****
******************************************************************************************************************************************************
***** Entr�e : - dParam, r�el, r�el avec lequel multiplier la matrice                                                                            *****
***** - MATParam, un objet de type CMatrice<MTYPE>                                                                                               *****
***** N�cessite :                                                                                                                                *****
***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                                     *****
***** Entraine:Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de la multiplication de la matrice avec le r�el en param�tre  *****
***** OU Exception MatriceVide : On ne peut pas diviser une matrice vide par un nombre                                                           *****
*****************************************************************************************************************************************************/
template<class MTYPE> CMatrice<MTYPE>& operator*(double dParam, CMatrice<MTYPE> MATParam) 
{
	unsigned int uiMATNbLignes, uiMATNbColonnes;
	uiMATNbLignes = MATParam.MATLireNbLignes();
	uiMATNbColonnes = MATParam.MATLireNbColonnes();
	
	//On teste si la matrice est vide
	if (uiMATNbColonnes == 0 || uiMATNbLignes == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(MatriceVide);
		throw EXCErreur;
	}
	CMatrice<MTYPE>* M1=new CMatrice<MTYPE>(uiMATNbLignes,uiMATNbColonnes);

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
			M1->MATModifierElement(uiBoucleIndiceLigne,uiBoucleIndiceColonne, MATParam.MATLireElement(uiBoucleIndiceLigne,uiBoucleIndiceColonne)*dParam);
		}
	}
	return *M1;
}

/**************************************************************************************************************************************************
***** OPERATOR/ : Surcharge de l'op�rateur / prenant un r�el � gauche et une matrice � droite permettant de diviser une matrice par un nombre *****
***************************************************************************************************************************************************
***** Entr�e : - dParam, r�el, r�el avec lequel diviser la matrice                                                                            *****
***** - MATParam, un objet de type CMatrice<MTYPE>                                                                                            *****
***** N�cessite :                                                                                                                             *****
***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                                  *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de la division de la matrice avec le r�el en param�tre   *****
***** OU Exception MatriceVide : On ne peut pas diviser une matrice vide par un nombre                                                        *****
***** Exception DivisionPar0 : On ne peut pas diviser par 0                                                                                   *****
**************************************************************************************************************************************************/
template<class MTYPE> CMatrice<MTYPE>& operator/(double dParam, CMatrice<MTYPE> MATParam) 
{
	unsigned int uiMATNbLignes, uiMATNbColonnes;
	uiMATNbLignes = MATParam.MATLireNbLignes();
	uiMATNbColonnes = MATParam.MATLireNbColonnes();

	//On teste si l'entier rentr�e en parametre est egale a 0 car on ne peut pas diviser par 0
	if (dParam == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DivisionPar0);
		throw EXCErreur;
	}
	if (uiMATNbColonnes == 0 || uiMATNbLignes == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(MatriceVide);
		throw EXCErreur;
	}
	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiMATNbLignes; uiBoucleIndiceLigne++) {
		for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonnes; uiBoucleIndiceColonne++) {
			M1->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATParam.MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne)/dParam);
		}
	}
	return *M1;
}

template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::MATSupprimerColonne(unsigned int uiPositionColonne) {
	
	if (uiPositionColonne >= uiMATNbColonnes) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementLigneOuColonne);
		throw EXCErreur;
	}
	unsigned int uiNbLignes, uiNbColonnes;
	uiNbLignes = uiMATNbLignes;
	uiNbColonnes = uiMATNbColonnes-1;
	if (uiNbColonnes == 0 || uiNbLignes == 0) {
		CMatrice<MTYPE>* MATParam = new CMatrice<MTYPE>();
		return *MATParam;
	}
	CMatrice<MTYPE>* MATParam = new CMatrice<MTYPE>(uiNbLignes, uiNbColonnes);
	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiNbLignes; uiBoucleLignes++) {
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiPositionColonne; uiBoucleColonne++) {
			MATParam->MATModifierElement(uiBoucleLignes, uiBoucleColonne, pMATMatrice[uiBoucleLignes][uiBoucleColonne]);
		}
		for (unsigned int uiBoucleColonne = uiPositionColonne; uiBoucleColonne < uiNbColonnes; uiBoucleColonne++) {
			MATParam->MATModifierElement(uiBoucleLignes, uiBoucleColonne, pMATMatrice[uiBoucleLignes][uiBoucleColonne+1]);
		}
	}
	return *MATParam;
}

template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::MATSupprimerLigne(unsigned int uiPositionLigne) {

	if (uiPositionLigne >= uiMATNbLignes) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementLigneOuColonne);
		throw EXCErreur;
	}
	unsigned int uiNbLignes, uiNbColonnes;
	uiNbLignes = uiMATNbLignes-1;
	uiNbColonnes = uiMATNbColonnes;
	if (uiNbColonnes == 0 || uiNbLignes == 0) {
		CMatrice<MTYPE>* MATParam = new CMatrice<MTYPE>();
		return *MATParam;
	}
	CMatrice<MTYPE>* MATParam = new CMatrice<MTYPE>(uiNbLignes, uiNbColonnes);
	for (unsigned int uiBoucleLignes = 0; uiBoucleLignes < uiPositionLigne; uiBoucleLignes++) {
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiNbColonnes; uiBoucleColonne++) {
			MATParam->MATModifierElement(uiBoucleLignes, uiBoucleColonne, pMATMatrice[uiBoucleLignes][uiBoucleColonne]);
		}
	}
	for (unsigned int uiBoucleLignes = uiPositionLigne; uiBoucleLignes < uiNbLignes; uiBoucleLignes++) {
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiNbColonnes; uiBoucleColonne++) {
			MATParam->MATModifierElement(uiBoucleLignes, uiBoucleColonne, pMATMatrice[uiBoucleLignes+1][uiBoucleColonne]);
		}
	}
	return *MATParam;
}

template<class MTYPE> double CMatrice<MTYPE>::MATDeterminantHessenbergInferieure(){
	if (uiMATNbColonnes != uiMATNbLignes) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(10);
		throw EXCErreur;
	}
	if (uiMATNbColonnes == 0) {
		return 1;
	}
	if (uiMATNbColonnes == 1) {
		return pMATMatrice[0][0];
	}
	double Somme = pMATMatrice[uiMATNbColonnes-1][uiMATNbLignes-1];
	CMatrice<MTYPE> MATParam = (*this).MATSupprimerColonne(uiMATNbColonnes - 1);
	MATParam = MATParam.MATSupprimerLigne(uiMATNbColonnes - 1);
	Somme = Somme + MATParam.MATDeterminantHessenbergInferieure();
	double Somme2=0;
	for (unsigned int uiBoucle = 0; uiBoucle < uiMATNbColonnes - 1; uiBoucle++) {
		double Somme3 = pow(-1, uiMATNbColonnes - (uiBoucle + 1));
		for (unsigned int uiBoucle2 = uiBoucle; uiBoucle2 < uiMATNbColonnes - 1; uiBoucle2++) {
			Somme3 = Somme3 *pMATMatrice[uiBoucle2][uiBoucle2 + 1];
		}
		Somme3 = Somme3 * pMATMatrice[uiMATNbColonnes - 1][uiBoucle];
		if (uiBoucle + 1 - 1 == 0) {
			CMatrice<MTYPE>* MATParam2 = new CMatrice<MTYPE>();
			Somme3 = Somme3 * MATParam2->MATDeterminantHessenbergInferieure();
		}
		else{
			CMatrice<MTYPE> MATParam2 =*this;
			for (unsigned int uiBoucle2 = uiMATNbColonnes - 1; uiBoucle2 > uiBoucle; uiBoucle--) {
				MATParam2 = MATParam2.MATSupprimerColonne(uiBoucle2);
				MATParam2 = MATParam2.MATSupprimerLigne(uiBoucle2);
			}
			Somme3 = Somme3 * MATParam2.MATDeterminantHessenbergInferieure();
		}
		Somme2 = Somme2 + Somme3;
	}
	return Somme + Somme2;
}

#endif