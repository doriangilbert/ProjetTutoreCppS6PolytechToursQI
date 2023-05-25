#include "CLecteur.h"

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
CLecteur::CLecteur()
{
	pcLECNomFichier = NULL;
}

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
CLecteur::CLecteur(CLecteur &LECParam) 
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
}

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
CLecteur::CLecteur(char* pcNomFichier)
{
	pcLECNomFichier = new char[strlen(pcNomFichier)];
	strcpy(pcLECNomFichier, pcNomFichier);
}

/**********************************************
***** ~CLECTEUR : Destructeur de CLecteur *****
***********************************************
***** Entrée :                            *****
***** Nécessite :                         *****
***** Sortie :                            *****
***** Entraine : Le destructeur a         *****
***** désalloué les pointeurs             *****
**********************************************/
CLecteur::~CLecteur()
{
	pcLECNomFichier = NULL;
}

/*****************************************************************************
***** LECLIRENOMFICHIER : Accesseur direct en lecture de pcLECNomFichier *****
******************************************************************************
***** Entrée :                                                           *****
***** Nécessite :                                                        *****
***** Sortie : chaine de caractères, valeur de l'attribut                *****
***** pcLECNomFichier                                                    *****
***** Entraine : LECLireNomFichier() = pcLECNomFichier                   *****
*****************************************************************************/
char* CLecteur::LECLireNomFichier()
{
	return pcLECNomFichier;
}

/**********************************************************************************
***** LECMODIFIERNOMFICHIER : Accesseur direct en écriture de pcLECNomFichier *****
***********************************************************************************
***** Entrée : pcNomFichier, chaine de caractères, nouvelle valeur de         *****
***** pcLECNomFichier                                                         *****
***** Nécessite :                                                             *****
***** Sortie :                                                                *****
***** Entraine : pcLECNomFichier = pcNomFichier                               *****
**********************************************************************************/
void CLecteur::LECModifierNomFichier(char* pcNomFichier)
{
	pcLECNomFichier = new char[strlen(pcNomFichier)];
	strcpy(pcLECNomFichier, pcNomFichier);
}

/******************************************************************************************
***** OPERATOR= : Surcharge de l'opérateur = de CLecteur prenant un CLecteur à droite *****
*******************************************************************************************
***** Entrée : LECParam, un objet de type CLecteur                                    *****
***** Nécessite :                                                                     *****
***** Sortie : objet CLecteur, retourné par référence                                 *****
***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à une copie  *****
***** de l'objet LECParam                                                             *****
******************************************************************************************/
CLecteur& CLecteur::operator=(CLecteur& LECParam) 
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
	return *this;
}

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
CMatrice<double>& CLecteur::LECLireFichierMatrice()
{
	//On vérifie la présence d'un nom de fichier
	if (!pcLECNomFichier) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(NomFichierManquant);
		throw EXCErreur;
	}
	//Ouverture du fichier en mode lecture seule, erreur si l'ouverture échoue
	FILE* fichier = fopen(pcLECNomFichier, "r");
	if (!fichier) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(EchecOuvertureFichier);
		throw EXCErreur;
	}
	char pcLigne[1024] = ""; //Chaine permettant de stocker la ligne courante
	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	char pcTypeMatrice[1024] = "";
	//Vérification de la présence de TypeMatrice=
	if (strncmp(pcLigne, "TypeMatrice=", 12) != 0) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else 
	{
		//Récupération de la valeur de TypeMatrice
		sscanf(pcLigne, "TypeMatrice=%s", pcTypeMatrice);
		//On vérifie que le type est bien "double"
		if (strcmp(pcTypeMatrice, "double") != 0)
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(TypeMatriceFichierInvalide);
			throw EXCErreur;
		}
	}
	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	int iNBLignes = 0;
	unsigned int uiNBLignes = 0;
	//Vérification de la présence de NBLignes=
	if (strncmp(pcLigne, "NBLignes=", 9) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else
	{
		//Récupération de la valeur de NBLignes
		sscanf(pcLigne, "NBLignes=%d", &iNBLignes);
		if (iNBLignes < 0) 
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		else 
		{
			uiNBLignes = iNBLignes;
		}
	}
	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	int iNBColonnes = 0;
	unsigned int uiNBColonnes = 0;
	//Vérification de la présence de NBColonnes=
	if (strncmp(pcLigne, "NBColonnes=", 11) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else
	{
		//Récupération de la valeur de NBColonnes
		sscanf(pcLigne, "NBColonnes=%d", &iNBColonnes);
		if (iNBColonnes < 0) 
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		else {
			uiNBColonnes = iNBColonnes;
		}
	}
	CMatrice<double>* MATMatrice = new CMatrice<double>(uiNBLignes, uiNBColonnes);
	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//Vérification de la présence de Matrice=[
	if (strncmp(pcLigne, "Matrice=[", 9) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//Parcours des lignes
	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiNBLignes; uiBoucleIndiceLigne++)
	{
		//Lecture de la ligne suivante et erreur si la ligne est absente
		if (!fgets(pcLigne, 1024, fichier))
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		//Vérification de la présence de ]
		if (strncmp(pcLigne, "]", 1) == 0)
		{
			//ERREUR : Pas assez de lignes par rapport au NBLignes indiqué
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		double dElement = 0;
		char* pcParcoursChaine = pcLigne;
		unsigned int uiBoucleIndiceColonne = 0;
		//Parcours des colonnes de chaque ligne
		while (*pcParcoursChaine != '\n')
		{
			//Récupération de la valeur de l'élément
			sscanf(pcParcoursChaine, "%lf", &dElement);
			if (uiBoucleIndiceColonne < uiNBColonnes) {
				//On ajoute l'élément à la matrice
				MATMatrice->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, dElement);
			}
			if (strchr(pcParcoursChaine, ' ')) 
			{
				//On passe à l'élément suivant
				pcParcoursChaine = strchr(pcParcoursChaine, ' ');
				pcParcoursChaine++;
			}
			else
			{
				//On va directement à la fin de la chaine si pas d'élément suivant
				pcParcoursChaine = strchr(pcParcoursChaine, '\n');
			}
			uiBoucleIndiceColonne++;
		}
		//On vérifie la concordance du nombre de colonnes
		if (uiBoucleIndiceColonne != uiNBColonnes) 
		{
			//ERREUR : Différence entre le NBColonnes indiqué et le nombre réel de valeurs dans la ligne
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
	}
	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//Vérification de la présence de ]
	if (strncmp(pcLigne, "]", 1) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//Si le fichier à été ouvert, on le ferme
	if (fichier)
	{
		fclose(fichier);
	}
	return *MATMatrice;
}