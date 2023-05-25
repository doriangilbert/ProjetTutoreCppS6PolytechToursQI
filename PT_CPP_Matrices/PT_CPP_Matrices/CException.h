#ifndef CException_h
#define CException_h
#define PAS_ERREUR 0

class CException
{
private:
	unsigned int uiEXCValeur;
public:
	/*************************************************************
	***** CEXCEPTION : Constructeur par défaut de CException *****
	**************************************************************
	***** Entrée : ***********************************************
	***** Nécessite : ********************************************
	***** Sortie : ***********************************************
	***** Entraine : Le contructeur a initialisé un objet ********
	***** CException avec uiEXCValeur = PAS_ERREUR ***************
	*************************************************************/
	CException();

	/*********************************************************************
	***** EXCLIREVALEUR : Accesseur direct en lecture de uiEXCValeur *****
	**********************************************************************
	***** Entrée : *******************************************************
	***** Nécessite : ****************************************************
	***** Sortie : Valeur de l'attribut uiEXCValeur **********************
	***** Entraine : EXCLireValeur() = uiEXCValeur ***********************
	*********************************************************************/
	unsigned int EXCLireValeur();
	/********************************************************************************
	***** EXCMODIFIERVALEUR : Accesseur direct en écriture de uiEXCValeur ***********
	*********************************************************************************
	***** Entrée : uiValeur, entier non signé, nouvelle valeur pour uiEXCValeur *****
	***** Nécessite : uiValeur est un entier positif ********************************
	***** Sortie : ******************************************************************
	***** Entraine : uiEXCValeur = uiValeur *****************************************
	********************************************************************************/
	void EXCModifierValeur(unsigned int uiValeur);
};


/*********************************************************************
***** EXCLIREVALEUR : Accesseur direct en lecture de uiEXCValeur *****
**********************************************************************
***** Entrée : *******************************************************
***** Nécessite : ****************************************************
***** Sortie : Valeur de l'attribut uiEXCValeur **********************
***** Entraine : EXCLireValeur() = uiEXCValeur ***********************
*********************************************************************/
inline unsigned int CException::EXCLireValeur()
{
	return uiEXCValeur;
}

/********************************************************************************
***** EXCMODIFIERVALEUR : Accesseur direct en écriture de uiEXCValeur ***********
*********************************************************************************
***** Entrée : uiValeur, entier non signé, nouvelle valeur pour uiEXCValeur *****
***** Nécessite : uiValeur est un entier positif ********************************
***** Sortie : ******************************************************************
***** Entraine : uiEXCValeur = uiValeur *****************************************
********************************************************************************/
inline void CException::EXCModifierValeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}

#endif
