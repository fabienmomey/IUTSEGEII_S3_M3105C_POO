/* Fichier Vaisseau.cpp
Déclaration des méthodes
History:
        1.0 - 30/11/2016 déclaration classe vaisseau TD2 Phase 1 & 2
        1.1 - 01/12/2016 déclarationclasse vaisseau TD2 Phase 3a
                * modification méthode affecter pour assignation points de dégats de l'arme au vaisseau;
                nouveau paramètre
                * nouvelle méthode subir_degats pour ôter des pts de vie au vaisseau
                * modification méthode afficher pour points de dégats
                * nouvelle méthode get_degats_arme_laser pour récupérer les dégats infligés par un adversaire(arme laser)
                * nouvelle méthode get_vie pour vérifier les points de vie restants
        1.2 - 02/12/2016 prototype classe vaisseau TD2 Phase 3b
                * definition de deux constantes pour le max de points de vie POINTS_VIE_MAX et le maximum
                  de dégats occasionnés par une arme laser DEGATS_LASER_MAX
                 => modifications de la méthode affecter pour prise en compte de POINTS_VIE_MAX et DEGATS_LASER_MAX
                 * definition du méthode get_nom pour renvoie du nom du vaisseau
        1.3 - 05/12/2016 TD2 Phase 4
                    * Définition d'un constructeur par défaut
                    * Définition d'un constructeur de surcharge
                    * Définition d'un destructeur
        1.4 - 07/12/2016 TD3 Phase 1
                    * Modifications de la classe "vaisseau"
                    => Rajout d'un attribut de type chaîne « m_type » qui spécifie le type du vaisseau
                    => Modification des constructeurs pour initialiser la valeur de l'ttribut "m_type" à « vaisseau ».
                    => Ajout d'une méthode « attaquer_basic » qui utilise l'arme basique arme laser.
                    => Création d'une nouvelle méthode « attaquer_special » qui ne fait rien.
                    => Modification de la méthode afficher pour afficher le type
                    => Tests des modifications dans le « main ».
        1.5 - 16/12/2016 TD3 phase 3 spécialisation du croiseur
                    * Ajout méthode get_type pour retourner le type
        2.1 - 06/11/2017
                    * Adaptation des bibliothèques pour utilisation sous Ubuntu
                    => remplacement de la bibliothèque <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#include <iostream>
#include <string>
#include "Vaisseau.h"

using namespace std;

/*
Début de la déclaration des méthodes de la classe vaisseau
*/

// Déclaration du constructeur implicite

vaisseau::vaisseau() : m_nom("TantiveIV"), m_points_vie(100), m_degats_arme_laser(10), m_type("vaisseau")
{
	// cout << "Appel du constructeur de la classe vaisseau par défaut pour " << m_nom << endl << endl;
}

// Déclaration du constructeur de surcharge

vaisseau::vaisseau(string nom, int pts_vie, int degats, string type) : m_nom(nom), m_type(type)
{
	// cout << endl << "Appel du constructeur de surcharge de la classe vaisseau pour le vaisseau :"<< m_nom << endl << endl;

    // Affectation du nombre de points de vie
	if (pts_vie > POINTS_VIE_MAX)
	{
		m_points_vie = POINTS_VIE_MAX;
	}
	else {
		m_points_vie = pts_vie;
	}

	// Affectation du nombre de dégats
	if (degats > DEGATS_LASER_MAX)
	{
		m_degats_arme_laser = DEGATS_LASER_MAX;
	}
	else {
		m_degats_arme_laser = degats;
	}

}

// Déclaration du destructeur

vaisseau::~vaisseau()
{
	// cout << "Appel du destructeur (desallocation memoire) du vaisseau: " << this->get_nom() << endl;

	if (this->m_points_vie == 0)
	{
		cout << this->get_nom() << " Dommage: ce vaisseau est detruit" << endl << endl;
	}
	else
	{
		cout << this->get_nom() << " Felicitations: ce vaisseau est vainqueur et quitte le champ de bataille" << endl << endl;
	}
}

// Déclaration de la méthode affecter

void vaisseau::affecter(string nom, int pts_vie, int degats)
{
 /* Pour debugger: 2 solutions
        soit pas à pas
        ou des cout comme ci-dessous */

 //   cout << "Affectation du nom:" << nom << endl << "Affectation des points de vie:" << pts_vie << endl << "Affectation des dégats:"<< degats << endl; // Pour debug

	m_nom = nom;       // Affectation du nom


    // Affectation du nombre de points de vie
	if (pts_vie > POINTS_VIE_MAX)
	{
		m_points_vie = POINTS_VIE_MAX;
	}
	else {
		m_points_vie = pts_vie;
	}

	// Affectation du nombre de dégats
	if (degats > DEGATS_LASER_MAX)
	{
		m_degats_arme_laser = DEGATS_LASER_MAX;
	}
	else {
		m_degats_arme_laser = degats;
	}

}

// Déclaration de la méthode afficher

void vaisseau::afficher()
{
    cout << "***********************************************************" << endl;
    cout << endl;
    cout << "Appel de la methode afficher() de la classe mere vaisseau" << endl;
    cout << "Le nom du vaisseau est: " << m_nom << endl << "Le nombre de points de vie est egal a: " << m_points_vie << endl << "Le nombre de points de degats est egal a: " << m_degats_arme_laser << endl << "Le type du vaisseau est: " << m_type << endl << endl;
    cout << "***********************************************************" << endl;
}

// Déclaration de la méthode subir_degats

void vaisseau::subir_degats(int degats)
{
    m_points_vie -= degats;

    if (m_points_vie <0)
    {
        m_points_vie = 0;

    }
}

// Déclaration de la méthode attaquer_basic

void vaisseau::attaquer_basic(vaisseau* cible)
{
    cout << "Le vaisseau:... " << m_nom << "  realise une attaque basique" << endl << endl;

    cible -> subir_degats (m_degats_arme_laser); // appel de la méthode subir_degats de la cible
}

// Déclaration de la méthode attaquer_special

void vaisseau::attaquer_special(vaisseau* cible)
{
    cout << "Methode attaquer_special de la classe mere vaisseau" << endl;
    cout << "Le vaisseau:..." << m_nom << "  realise une attaque speciale qui ne fait rien dans la phase 1 de ce TD" << endl << endl;
}

// Déclaration de la méthode get_degats_arme_laser

int vaisseau::get_degats_arme_laser()
{
    return m_degats_arme_laser;
}

// Déclaration de la méthode get_vie

int vaisseau::get_vie()
{
    return m_points_vie;
}

// Déclaration de la méthode get_nom

string vaisseau::get_nom()
{
    return m_nom;
}

// Déclaration de la méthode get_type

string vaisseau::get_type()
{
    return m_type;
}

/* Fin de la déclaration des méthodes de la classe vaisseau */
