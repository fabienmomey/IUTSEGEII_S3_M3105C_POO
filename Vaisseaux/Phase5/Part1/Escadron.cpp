/* Fichier Escadron.cpp
D�claration des m�thodes
History:
        1.0 - 09/12/2016 TD3 phase 2 prototype d'une classe fille escadron qui h�rite de la classe vaisseau
        1.1 - 16/12/2016 TD3 phase 3 sp�cialisation du escadron
                * Red�finition de la m�thode � attaquer_special � qui va infliger des d�g�ts d'une nouvelle arme
                sp�cifique : le torpille.
                * D�finition d'un nouvel attribut qui limite le nombre d'utilisation de l'arme sp�ciale NB_TIRS_CANONS_MAX.
                (l�attaque sp�ciale n�ait qu�une chance sur deux de r�ussir).
                D�finition d'un nouvel attribut qui limite les d�gats max. DEGATS_CANONS_MAX
                * Red�finition de  la m�thode � affecter � qui autorise � modifier les attributs basiques et
                sp�ciaux.
                * Red�finition de la m�thode � afficher � pour prendre en compte les nouvelles informations du
                � escadron �.
                * Red�finition du constructeur de la classe � escadron � pour initialiser le/les nouveaux attributs.
        2.1 - 06/11/2017
                    * Adaptation des biblioth�ques pour utilisation sous Ubuntu
                    => remplacement de la biblioth�que <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#include <iostream>
#include <string>
#include <cstdlib> // pour generateur de nb al�atoire
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
escadron :: escadron (string nom, int pts_vie, int degats_laser, string type, int nb_tirs_torpilles, int degats_torpilles) : vaisseau(nom,pts_vie,degats_laser,type)
{
	// cout << endl << "Appel du constructeur de surcharge de la classe escadron pour le escadron :"<< m_nom << endl << endl;

	m_type = "Escadron";

    if (nb_tirs_torpilles > NB_TIRS_CANONS_MAX)
	{
		m_nb_tirs_torpilles = NB_TIRS_CANONS_MAX;
	}
	else {
		m_nb_tirs_torpilles = nb_tirs_torpilles;
	}
	if (degats_torpilles > DEGATS_CANONS_MAX)
	{
		m_degats_torpilles = DEGATS_CANONS_MAX;
	}
	else {
		m_degats_torpilles = degats_torpilles;
	}
}

// D�claration du destructeur

escadron::~escadron()
{
	// cout << "Appel du destructeur (desallocation memoire) du escadron: " << this->get_nom() << endl;

	if (this->m_points_vie == 0)
	{
		cout << this->get_nom() << " Dommage: ce escadron est detruit" << endl << endl;
	}
	else
	{
		cout << this->get_nom() << " Felicitations: ce escadron est vainqueur et quitte le champ de bataille" << endl << endl;
	}
}

// D�claration de la m�thode affecter

void escadron::affecter(string nom, int pts_vie, int degats_laser, int nb_tirs_torpilles, int degats_torpilles)
{
	m_nom = nom;       // Affectation du nom

	// Affectation du nombre de d�gats

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
	if (nb_tirs_torpilles > NB_TIRS_CANONS_MAX)
	{
		m_nb_tirs_torpilles = NB_TIRS_CANONS_MAX;
	}
	else {
		m_nb_tirs_torpilles = nb_tirs_torpilles;
	}
	if (degats_torpilles > DEGATS_CANONS_MAX)
	{
		m_degats_torpilles = DEGATS_CANONS_MAX;
	}
	else {
		m_degats_torpilles = degats_torpilles;
	}
}

// D�claration de la m�thode afficher

void escadron::afficher()
{
    cout << "***********************************************************" << endl;
    cout << endl;
    cout << "Appel de la methode afficher() de la classe fille escadron" << endl;
    cout << "Le " << m_type << " qui se nomme " << m_nom << " avec pour points de vie restant " << m_points_vie << " ,et pour degats de l'arme laser " << m_degats_arme_laser;
	cout << " a pour degats des torpilles = " << m_degats_torpilles << endl << endl;
	cout << "***********************************************************" << endl;
}

// D�claration de la m�thode attaquer_special

void escadron::attaquer_special(vaisseau* cible)
{
    cout << "Methode attaquer_special de la classe fille escadron" << endl;
 	if (cible->get_vie() > 0)
	{
		if (m_nb_tirs_torpilles)
		{
			cout << this->get_type() << " " << this->get_nom() << " tire au torpille sur " << cible->get_type() << " " << cible->get_nom() << endl << endl;

			// Une chance sur deux que le tir sp�cial r�ussisse
			if (rand() % 2)
			{
				cout << "TOUCHE !" << endl << endl;
				cible->subir_degats(m_degats_torpilles);
			}
			else
			{
				cout << "MANQUE" << endl << endl;
			}
			// On d�cr�mente le nombre de tirs disponibles
			m_nb_tirs_torpilles--;
		}
		else
		{
			cout << "Plus de tirs torpilles ! " << this->get_type() << " " << this->get_nom() << " ne peut plus tirer avec son tir special !" << endl << endl;
		}
	}
	else
	{
		// On d�cr�mente le nombre de tirs disponibles
		m_nb_tirs_torpilles--;
		cout << cible->get_type() << " " << cible->get_type() << "est deja detruit ! " << this->get_type() << " " << this->get_nom() << " tire dans le vide !" << endl << endl;
	}
}

/* Fin de la d�claration des m�thodes de la classe vaisseau */
