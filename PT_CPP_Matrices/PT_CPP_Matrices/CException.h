#ifndef CException_h
#define CException_h
#define PAS_ERREUR 0

class CException
{
private:
	unsigned int uiEXCValeur;
public:
	/*************************************************************
	***** CEXCEPTION : Constructeur par d�faut de CException *****
	**************************************************************
	***** Entr�e : ***********************************************
	***** N�cessite : ********************************************
	***** Sortie : ***********************************************
	***** Entraine : Le contructeur a initialis� un objet ********
	***** CException avec uiEXCValeur = PAS_ERREUR ***************
	*************************************************************/
	CException();

	/*********************************************************************
	***** EXCLIREVALEUR : Accesseur direct en lecture de uiEXCValeur *****
	**********************************************************************
	***** Entr�e : *******************************************************
	***** N�cessite : ****************************************************
	***** Sortie : Valeur de l'attribut uiEXCValeur **********************
	***** Entraine : EXCLireValeur() = uiEXCValeur ***********************
	*********************************************************************/
	unsigned int EXCLireValeur();
	/********************************************************************************
	***** EXCMODIFIERVALEUR : Accesseur direct en �criture de uiEXCValeur ***********
	*********************************************************************************
	***** Entr�e : uiValeur, entier non sign�, nouvelle valeur pour uiEXCValeur *****
	***** N�cessite : uiValeur est un entier positif ********************************
	***** Sortie : ******************************************************************
	***** Entraine : uiEXCValeur = uiValeur *****************************************
	********************************************************************************/
	void EXCModifierValeur(unsigned int uiValeur);
};


/*********************************************************************
***** EXCLIREVALEUR : Accesseur direct en lecture de uiEXCValeur *****
**********************************************************************
***** Entr�e : *******************************************************
***** N�cessite : ****************************************************
***** Sortie : Valeur de l'attribut uiEXCValeur **********************
***** Entraine : EXCLireValeur() = uiEXCValeur ***********************
*********************************************************************/
inline unsigned int CException::EXCLireValeur()
{
	return uiEXCValeur;
}

/********************************************************************************
***** EXCMODIFIERVALEUR : Accesseur direct en �criture de uiEXCValeur ***********
*********************************************************************************
***** Entr�e : uiValeur, entier non sign�, nouvelle valeur pour uiEXCValeur *****
***** N�cessite : uiValeur est un entier positif ********************************
***** Sortie : ******************************************************************
***** Entraine : uiEXCValeur = uiValeur *****************************************
********************************************************************************/
inline void CException::EXCModifierValeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}

#endif
