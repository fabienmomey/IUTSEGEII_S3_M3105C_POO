/* Fichier Croiseur.cpp
Déclaration des méthodes
History:
        1.0 - 09/12/2016 TD3 phase 2 prototype d'une classe fille croiseur qui hérite de la classe vaisseau
        1.1 - 16/12/2016 TD3 phase 3 spécialisation du croiseur
                * Redéfinition de la méthode « attaquer_special » qui va infliger des dégâts d'une nouvelle arme
                spécifique : le canon.
                * Définition d'un nouvel attribut qui limite le nombre d'utilisation de l'arme spéciale NB_TIRS_CANONS_MAX.
                (l’attaque spéciale n’ait qu’une chance sur deux de réussir).
                Définition d'un nouvel attribut qui limite les dégats max. DEGATS_CANONS_MAX
                * Redéfinition de  la méthode « affecter » qui autorise à modifier les attributs basiques et
                spéciaux.
                * Redéfinition de la méthode « afficher » pour prendre en compte les nouvelles informations du
                « croiseur ».
                * Redéfinition du constructeur de la classe « croiseur » pour initialiser le/les nouveaux attributs.
        1.6 - 06/11/2017
                    * Adaptation des bibliothèques pour utilisation sous Ubuntu
                    => remplacement de la bibliothèque <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#include <iostream>
#include <string>
#include <cstdlib> // pour generateur de nb aléatoire
#include "Vaisseau.h"
#include "Croiseur.h"

using namespace std;

/*
Début de la déclaration des méthodes de la classe vaisseau
*/

// Déclaration du constructeur implicite

croiseur::croiseur() : vaisseau ()
{
	// cout << "Appel du constructeur de la classe vaisseau par defaut pour " << m_nom << endl << endl;
}

// Déclaration du constructeur de surcharge
croiseur :: croiseur (string nom, int pts_vie, int degats_laser, string type, int nb_tirs_canons, int degats_canons) : vaisseau(nom,pts_vie,degats_laser,type)
{
	// cout << endl << "Appel du constructeur de surcharge de la classe croiseur pour le croiseur :"<< m_nom << endl << endl;

	m_type = "Croiseur";

    if (nb_tirs_canons > NB_TIRS_CANONS_MAX)
	{
		m_nb_tirs_canons = NB_TIRS_CANONS_MAX;
	}
	else {
		m_nb_tirs_canons = nb_tirs_canons;
	}
	if (degats_canons > DEGATS_CANONS_MAX)
	{
		m_degats_canons = DEGATS_CANONS_MAX;
	}
	else {
		m_degats_canons = degats_canons;
	}
}

// Déclaration du destructeur

croiseur::~croiseur()
{
	// cout << "Appel du destructeur (desallocation memoire) du croiseur: " << this->get_nom() << endl;

	if (this->m_points_vie == 0)
	{
		cout << this->get_nom() << " Dommage: ce croiseur est detruit" << endl << endl;
	}
	else
	{
		cout << this->get_nom() << " Felicitations: ce croiseur est vainqueur et quitte le champ de bataille" << endl << endl;
	}
}

// Déclaration de la méthode affecter

void croiseur::affecter(string nom, int pts_vie, int degats_laser, int nb_tirs_canons, int degats_canons)
{
	m_nom = nom;       // Affectation du nom

	// Affectation du nombre de dégats

	if (pts_vie > POINTS_VIE_MAX) // Affectation du nombre de points de vie
	{
		m_points_vie = POINTS_VIE_MAX;
	}
	else {
		m_points_vie = pts_vie;
	}
	if (degats_laser > DEGATS_LASER_MAX)
	{
		m_degats_arme_laser = DEGATS_LASER_MAX;
	}
	else {
		m_degats_arme_laser = degats_laser;
	}
	if (nb_tirs_canons > NB_TIRS_CANONS_MAX)
	{
		m_nb_tirs_canons = NB_TIRS_CANONS_MAX;
	}
	else {
		m_nb_tirs_canons = nb_tirs_canons;
	}
	if (degats_canons > DEGATS_CANONS_MAX)
	{
		m_degats_canons = DEGATS_CANONS_MAX;
	}
	else {
		m_degats_canons = degats_canons;
	}
}

// Déclaration de la méthode afficher

void croiseur::afficher()
{
    cout << "***********************************************************" << endl;
    cout << endl;
    cout << "Appel de la methode afficher() de la classe fille croiseur" << endl;
    cout << "Le " << m_type << " qui se nomme " << m_nom << " avec pour points de vie restant " << m_points_vie << " ,et pour degats de l'arme laser " << m_degats_arme_laser;
	cout << " a pour degats des canons = " << m_degats_canons << endl << endl;
	cout << "***********************************************************" << endl;
}

// Déclaration de la méthode attaquer_special

void croiseur::attaquer_special(vaisseau* cible)
{
    cout << "Methode attaquer_special de la classe fille croiseur" << endl;
 	if (cible->get_vie() > 0)
	{
		if (m_nb_tirs_canons)
		{
			cout << this->get_type() << " " << this->get_nom() << " tire au canon sur " << cible->get_type() << " " << cible->get_nom() << endl << endl;

			// Une chance sur deux que le tir spécial réussisse
			if (rand() % 2)
			{
				cout << "TOUCHE !" << endl << endl;
				cible->subir_degats(m_degats_canons);
			}
			else
			{
				cout << "MANQUE" << endl << endl;
			}
			// On décrémente le nombre de tirs disponibles
			m_nb_tirs_canons--;
		}
		else
		{
			cout << "Plus de tirs canons ! " << this->get_type() << " " << this->get_nom() << " ne peut plus tirer avec son tir special !" << endl << endl;
		}
	}
	else
	{
		// On décrémente le nombre de tirs disponibles
		m_nb_tirs_canons--;
		cout << cible->get_type() << " " << cible->get_type() << "est deja detruit ! " << this->get_type() << " " << this->get_nom() << " tire dans le vide !" << endl << endl;
	}
}

/* Fin de la déclaration des méthodes de la classe vaisseau */
