/* Fichier Croiseur.cpp
Déclaration des méthodes
History:
        1.0 - 09/12/2016 TD3 phase 2 prototype d'une classe fille croiseur qui hérite de la classe vaisseau
        1.6 - 06/11/2017
                    * Adaptation des bibliothèques pour utilisation sous Ubuntu
                    => remplacement de la bibliothèque <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"

*/

#include <iostream>
#include <string>
#include "Vaisseau.h"
#include "Croiseur.h"

using namespace std;

/*
Début de la déclaration des méthodes de la classe vaisseau
*/

// Déclaration du constructeur implicite

croiseur::croiseur() : vaisseau()
{
	cout << "Appel du constructeur de la classe croiseur par defaut pour " << m_nom << endl << endl;
}

// Déclaration du constructeur de surcharge

croiseur :: croiseur (string nom, int pts_vie, int degats, string type) : vaisseau(nom,pts_vie,degats,type)
{
	cout << endl << "Appel du constructeur de surcharge de la classe croiseur pour le croiseur :"<< m_nom << endl << endl;

	m_type = "Croiseur";

}

// Déclaration du destructeur

croiseur::~croiseur()
{
	cout << "Appel du destructeur (desallocation memoire) du croiseur: " << this->get_nom() << endl;

	if (this->m_points_vie == 0)
	{
		cout << this->get_nom() << " Dommage: ce croiseur est detruit" << endl << endl;
	}
	else
	{
		cout << this->get_nom() << " Felicitations: ce croiseur est vainqueur et quitte le champ de bataille" << endl << endl;
	}
}

/* Fin de la déclaration des méthodes de la classe vaisseau */
