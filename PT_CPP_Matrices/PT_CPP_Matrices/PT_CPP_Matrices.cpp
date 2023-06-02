// PT_CPP_Matrices.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>

#include "CMatrice.h"
#include "CLecteur.h"
using namespace std;

int main(int argc,char* argv[])
{
	int iNombreParametres = (argc - 1);
	//cout << iNombreParametres << "\n";
	//On voit si on a bien des parametres en entrée
	if (iNombreParametres > 0) {
		CMatrice<double>* LISMATListeMatrice1 = new CMatrice<double>[iNombreParametres];
		CLecteur LECLecteur;
		try {
			//Boucle pour remplir la liste de Matrice
			for (int iBoucle = 1; iBoucle < argc; iBoucle++) {
				LECLecteur.LECModifierNomFichier(argv[iBoucle]);
				CMatrice<double> MATMatrice = LECLecteur.LECLireFichierMatrice();
				LISMATListeMatrice1[iBoucle - 1] = MATMatrice;
				cout << "Resultat M" << iBoucle << "\n";
				(LISMATListeMatrice1[iBoucle - 1]).MATAfficher();
			}
			cout << "Entrer un reel c : \n";
			double c;
			// Si c'est bien un entier on peut faire la multiplication Mk*c ou Mk/c
			if (cin >> c) {
				cout << "C'est un reel : " << c << endl;
				try {
					//Resultat des Mk *c
					for (int uiBoucleIndiceListeMatrice = 0; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
						cout << "Resultat M" << uiBoucleIndiceListeMatrice + 1 << " * c \n";
						(LISMATListeMatrice1[uiBoucleIndiceListeMatrice] * c).MATAfficher();
					}
					//Resultat des Mk / c
					for (int uiBoucleIndiceListeMatrice = 0; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
						cout << "Resultat M" << uiBoucleIndiceListeMatrice + 1 << " / c \n";
						(LISMATListeMatrice1[uiBoucleIndiceListeMatrice] / c).MATAfficher();
					}
				}
				catch (CException EXCErreur) {
					if (EXCErreur.EXCLireValeur() == DivisionPar0) cout << "ERREUR : Division impossible : Division par 0\n";
				}

			}
			else cout << "ERREUR : La valeur saisie n'est pas un reel" << endl;
			// On calcule la somme des Mk et la somme des M1+M2-M3....
			cout << "Resultat MSomme (addition de toutes les matrices)\n";
			try {
				CMatrice<double> MSomme(LISMATListeMatrice1[0]);
				for (int uiBoucleIndiceListeMatrice = 1; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
					MSomme = MSomme + LISMATListeMatrice1[uiBoucleIndiceListeMatrice];
				}
				MSomme.MATAfficher();
				CMatrice<double> MSommeBizarre(LISMATListeMatrice1[0]);
				for (int uiBoucleIndiceListeMatrice = 1; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
					if (uiBoucleIndiceListeMatrice % 2 != 0) {
						MSommeBizarre = MSommeBizarre - LISMATListeMatrice1[uiBoucleIndiceListeMatrice];
					}
					else {
						MSommeBizarre = MSommeBizarre + LISMATListeMatrice1[uiBoucleIndiceListeMatrice];
					}
				}
				cout << "Resultat MSommeBizarre (alternance soustraction/somme)\n";
				MSommeBizarre.MATAfficher();
			}
			catch (CException EXCErreur) {
				cout << "ERREUR : Somme impossible : Tailles de Matrice non compatibles\n";
			}
			cout << "Resultat MProduit (produit des matrices)\n";
			try {
				CMatrice<double> MProduit(LISMATListeMatrice1[0]);
				for (int uiBoucleIndiceListeMatrice = 1; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
					MProduit = MProduit * LISMATListeMatrice1[uiBoucleIndiceListeMatrice];
				}
				MProduit.MATAfficher();
			}
			catch (CException EXCErreur) {
				cout << "ERREUR : Produit impossible : Tailles de Matrice non compatibles\n";
			}
			cout << "TEST DETERMINANT CHELOU\n";
			try {
				CMatrice<double> MTest(LISMATListeMatrice1[0]);
				MTest.MATModifierElement(0, 2, 0);
				MTest.MATAfficher();
				cout << MTest.MATDeterminantHessenbergInferieure();
			}
			catch (CException EXCErreur) {
				cout << EXCErreur.EXCLireValeur();
			}
		}
		catch (CException EXCErreur) {
			if (EXCErreur.EXCLireValeur() == NomFichierManquant) cout << "ERREUR : Nom de fichier manquant\n";
			if (EXCErreur.EXCLireValeur() == EchecOuvertureFichier) cout << "ERREUR : Echec d'ouverture de fichier\n";
			if (EXCErreur.EXCLireValeur() == FormatFichierInvalide) cout << "ERREUR : Format de fichier invalide\n";
			if (EXCErreur.EXCLireValeur() == TypeMatriceFichierInvalide) cout << "ERREUR : Type de matrice non pris en charge (seul le type double est pris en charge)\n";
			cout << "ERREUR : Code d'erreur : " << EXCErreur.EXCLireValeur() << endl;
		}
		delete[] LISMATListeMatrice1;
	}
	else {
		cout << "ERREUR : Pas de parametre \n";
	}
}