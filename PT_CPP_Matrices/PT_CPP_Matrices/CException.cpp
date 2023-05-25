#include "CException.h"

/*************************************************************
***** CEXCEPTION : Constructeur par défaut de CException *****
**************************************************************
***** Entrée : ***********************************************
***** Nécessite : ********************************************
***** Sortie : ***********************************************
***** Entraine : Le contructeur a initialisé un objet ********
***** CException avec uiEXCValeur = PAS_ERREUR ***************
*************************************************************/
CException::CException()
{
	uiEXCValeur = PAS_ERREUR;
}