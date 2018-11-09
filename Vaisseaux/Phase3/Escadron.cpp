/* Fichier Escadron.cpp
D�claration des m�thodes
History:
        1.0 - 09/12/2016 TD3 phase 2 prototype d'une classe fille escadron qui h�rite de la classe vaisseau
        1.6 - 06/11/2017
                    * Adaptation des biblioth�ques pour utilisation sous Ubuntu
                    => remplacement de la biblioth�que <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#include <iostream>
#include <string>
#include "Vaisseau.h"
#include "Escadron.h"

using namespace std;

/*
D�but de la d�claration des m�thodes de la classe vaisseau
*/

// D�claration du constructeur implicite

escadron::escadron() : vaisseau ()
{
	// cout << "Appel du constructeur de la classe vaisseau par defaut pour " << m_nom << endl << endl;
}

// D�claration du constructeur de surcharge

escadron :: escadron (string nom, int pts_vie, int degats, string type) : vaisseau(nom,pts_vie,degats,type)
{
	cout << endl << "Appel du constructeur de surcharge de la classe escadron pour l'escadron :"<< m_nom << endl << endl;

	m_type = "Escadron";

}

// D�claration du destructeur

escadron::~escadron()
{
	cout << "Appel du destructeur (desallocation memoire) de l'escadron: " << this->get_nom() << endl;

	if (this->m_points_vie == 0)
	{
		cout << this->get_nom() << " Dommage: cet escadron est detruit" << endl << endl;
	}
	else
	{
		cout << this->get_nom() << " Felicitations: cet escadron est vainqueur et quitte le champ de bataille" << endl << endl;
	}
}

/* Fin de la d�claration des m�thodes de la classe vaisseau */
