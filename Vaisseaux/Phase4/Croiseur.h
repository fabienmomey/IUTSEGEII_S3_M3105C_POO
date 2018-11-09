/*
Fichier Croiseur.h
Prototypes des classes et méthodes
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

#ifndef CROISEUR_H_INCLUDED
#define CROISEUR_H_INCLUDED

#include <string>
#include "Vaisseau.h" //Prototypes de la classe vaisseau

/*
Début du prototype de la classe croiseur classe fille de la classe vaisseau
*/

class croiseur : public vaisseau
{
public:
    // Début prototypes des méthodes de la classe croiseur
    /*
    Prototype du constructeur par défaut
    Permet d'initialiser les attributs avec des paramètres par défaut en dur.
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	croiseur(); // constructeur par défaut

    /*
    Prototype du constructeur de surcharge
    Permet d'initialiser des attributs avec des paramètres fournis par l'utilisateur.
    Paramètres d'entrée:
                      - string nom: nom de l'instance croiseur
                      - int point de vie: nombre de points de vie de l'instance croiseur
                      - int degats_laser: dégats occasionnés par arme laser
                      - string type: le type de vaisseau
                      - int nb_tirs_canons: le nombre max de tirs spéciaux
                      - int degats_canons: les dégats occasionnés par la nouvelle arme
    Paramètres de sortie: N/A
    */
	croiseur(std::string nom, int pts_vie, int degats_laser, std::string type, int nb_tirs_canons, int degats_canons); // constructeur surchargé

    /*
    Prototype du destructeur
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	~croiseur(); // destructeur

    /*
    Prototype de la méthode affecter
    Redéfinition de la méthode « affecter ». qui va autoriser à modifier les attributs basiques et spéciaux.
    Cette méthode permet de demander à l'utilisateur la valeur des attributs de la classe vaisseau
    Paramètres d'entrée:
                      - string nom: nom de l'instance vaisseau
                      - int point de vie: nombre de points de vie de l'instance vaisseau
                      - int degats_laser: dégats occasionnés par arme laser
                      - int nb tirs canons: nb de tirs avec l'arme spécials
                      - int degats canons: nb de dégats infligés par l'arme canon
    Paramètres de sortie: aucun
    */
    void affecter(std::string nom, int pts_vie, int degats_laser, int nb_tirs_canons, int degats_canons); // redéfinition de l'affectation des attributs

	/*
    Prototype de la méthode afficher
    Redéfinition de la méthode afficher.
    Redéfinition de l'affichage des informations
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	virtual void afficher(); // méthode virtuelle pour mise en place du polymorphisme

    /*
    Prototype de la méthode attaquer_special
    Redéfinition de la méthode
    Cette méthode permet d'ôter directement des points de vie à un vaisseau cible avec une arme speciale
    Paramètres d'entrée:
                        vaisseau *: pointeur sur un vaisseau cible
    Paramètres de sortie: aucun
    */
    void attaquer_special (vaisseau *);

    // Fin prototypes des méthodes de la classe croiseur

protected:
    // Début prototype des attributs de la classe croiseur
    int m_degats_canons; // dégâts de l'arme spéciale (canon pour le croiseur)
	int m_nb_tirs_canons; // nombre de tirs spéciaux restants

    // Définition des constantes
    const static int NB_TIRS_CANONS_MAX = 5; // nombre max d'utilisation de l'arme spéciale
    const static int DEGATS_CANONS_MAX = 100; // attribut qui limite les dégats max infligés à l'ennemi

	// Fin prototype des attributs de la classe croiseur
};

/* Fin du prototype de la classe croiseur */

#endif // CROISEUR_H_INCLUDED
