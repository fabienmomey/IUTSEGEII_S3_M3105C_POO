/* Fichier Vaisseau.cpp
D�claration des m�thodes
History:
        1.0 - 30/11/2016 d�claration classe vaisseau TD2 Phase 1 & 2
        1.1 - 01/12/2016 d�clarationclasse vaisseau TD2 Phase 3a
                * modification m�thode affecter pour assignation points de d�gats de l'arme au vaisseau;
                nouveau param�tre
                * nouvelle m�thode subir_degats pour �ter des pts de vie au vaisseau
                * modification m�thode afficher pour points de d�gats
                * nouvelle m�thode get_degats_arme_laser pour r�cup�rer les d�gats inflig�s par un adversaire(arme laser)
                * nouvelle m�thode get_vie pour v�rifier les points de vie restants
        1.2 - 02/12/2016 prototype classe vaisseau TD2 Phase 3b
                * definition de deux constantes pour le max de points de vie POINTS_VIE_MAX et le maximum
                  de d�gats occasionn�s par une arme laser DEGATS_LASER_MAX
                 => modifications de la m�thode affecter pour prise en compte de POINTS_VIE_MAX et DEGATS_LASER_MAX
                 * definition du m�thode get_nom pour renvoie du nom du vaisseau
        1.3 - 05/12/2016 TD2 Phase 4
                    * D�finition d'un constructeur par d�faut
                    * D�finition d'un constructeur de surcharge
                    * D�finition d'un destructeur
        1.4 - 06/11/2017
                    * Adaptation des biblioth�ques pour utilisation sous Ubuntu
                    => remplacement de la biblioth�que <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"

*/

#include <iostream>
#include <string>
#include "Vaisseau.h"

using namespace std;

/*
D�but de la d�claration des m�thodes de la classe vaisseau
*/

// D�claration du constructeur implicite

vaisseau::vaisseau() : m_nom("TantiveIV"), m_points_vie(100), m_degats_arme_laser(10)
{
	cout << "Appel du constructeur de la classe vaisseau par d�faut pour " << m_nom << endl << endl;
}

// D�claration du constructeur de surcharge

vaisseau::vaisseau(string nom, int pts_vie, int degats) : m_nom(nom)
{
	cout << endl << "Appel du constructeur de surcharge de la classe vaisseau pour le vaisseau :"<< m_nom << endl << endl;

    // Affectation du nombre de points de vie
	if (pts_vie > POINTS_VIE_MAX)
	{
		m_points_vie = POINTS_VIE_MAX;
	}
	else {
		m_points_vie = pts_vie;
	}

	// Affectation du nombre de d�gats
	if (degats > DEGATS_LASER_MAX)
	{
		m_degats_arme_laser = DEGATS_LASER_MAX;
	}
	else {
		m_degats_arme_laser = degats;
	}

}

// D�claration du destructeur

vaisseau::~vaisseau()
{
	cout << "Appel du destructeur (desallocation memoire) du vaisseau: " << this->get_nom() << endl;

	if (this->m_points_vie == 0)
	{
		cout << this->get_nom() << " Dommage: ce vaisseau est detruit" << endl << endl;
	}
	else
	{
		cout << this->get_nom() << " Felicitations: ce vaisseau est vainqueur et quitte le champ de bataille" << endl << endl;
	}
}

// D�claration de la m�thode affecter

void vaisseau::affecter(string nom, int pts_vie, int degats)
{
 /* Pour debugger: 2 solutions
        soit pas � pas
        ou des cout comme ci-dessous */

 //   cout << "Affectation du nom:" << nom << endl << "Affectation des points de vie:" << pts_vie << endl << "Affectation des d�gats:"<< degats << endl; // Pour debug

	m_nom = nom;       // Affectation du nom


    // Affectation du nombre de points de vie
	if (pts_vie > POINTS_VIE_MAX)
	{
		m_points_vie = POINTS_VIE_MAX;
	}
	else {
		m_points_vie = pts_vie;
	}

	// Affectation du nombre de d�gats
	if (degats > DEGATS_LASER_MAX)
	{
		m_degats_arme_laser = DEGATS_LASER_MAX;
	}
	else {
		m_degats_arme_laser = degats;
	}

}

// D�claration de la m�thode afficher

void vaisseau::afficher()
{
    cout << endl;
    cout << "Le nom du vaisseau est: " << m_nom << endl << "Le nombre de points de vie est egal a: " << m_points_vie << endl << "Le nombre de points de degats est egal a: " << m_degats_arme_laser << endl << endl;
}

// D�claration de la m�thode subir_degats

void vaisseau::subir_degats(int degats)
{
    m_points_vie -= degats;

    if (m_points_vie <0)
    {
        m_points_vie = 0;

    }
}

// D�claration de la m�thode attaquer_basic

void vaisseau::attaquer(vaisseau* cible)
{
    cout << "Le vaisseau:... " << m_nom << "  realise une attaque basique" << endl << endl;

    cible -> subir_degats (m_degats_arme_laser); // appel de la m�thode subir_degats de la cible
}

// D�claration de la m�thode get_degats_arme_laser

int vaisseau::get_degats_arme_laser()
{
    return m_degats_arme_laser;
}

// D�claration de la m�thode get_vie

int vaisseau::get_vie()
{
    return m_points_vie;
}

// D�claration de la m�thode get_nom

string vaisseau::get_nom()
{
    return m_nom;
}

/* Fin de la d�claration des m�thodes de la classe vaisseau */
