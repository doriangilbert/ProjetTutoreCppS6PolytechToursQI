#include "CException.h"

/*************************************************************
***** CEXCEPTION : Constructeur par d�faut de CException *****
**************************************************************
***** Entr�e : ***********************************************
***** N�cessite : ********************************************
***** Sortie : ***********************************************
***** Entraine : Le contructeur a initialis� un objet ********
***** CException avec uiEXCValeur = PAS_ERREUR ***************
*************************************************************/
CException::CException()
{
	uiEXCValeur = PAS_ERREUR;
}