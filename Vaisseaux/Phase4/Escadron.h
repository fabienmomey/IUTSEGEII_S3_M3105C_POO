/*
Fichier Escadron.h
Prototypes des classes et m�thodes
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
        1.6 - 06/11/2017
                    * Adaptation des biblioth�ques pour utilisation sous Ubuntu
                    => remplacement de la biblioth�que <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#ifndef ESCADRON_H_INCLUDED
#define ESCADRON_H_INCLUDED

#include <string>
#include "Vaisseau.h" //Prototypes de la classe vaisseau

/*
D�but du prototype de la classe escadron classe fille de la classe vaisseau
*/

class escadron : public vaisseau
{
public:
    // D�but prototypes des m�thodes de la classe escadron
    /*
    Prototype du constructeur par d�faut
    Permet d'initialiser les attributs avec des param�tres par d�faut en dur.
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	escadron(); // constructeur par d�faut

    /*
    Prototype du constructeur de surcharge
    Permet d'initialiser des attributs avec des param�tres fournis par l'utilisateur.
    Param�tres d'entr�e:
                      - string nom: nom de l'instance escadron
                      - int point de vie: nombre de points de vie de l'instance escadron
                      - int degats_laser: d�gats occasionn�s par arme laser
                      - string type: le type de vaisseau
                      - int nb_tirs_torpilles: le nombre max de tirs sp�ciaux
                      - int degats_torpilles: les d�gats occasionn�s par la nouvelle arme
    Param�tres de sortie: N/A
    */
	escadron(std::string nom, int pts_vie, int degats_laser, std::string type, int nb_tirs_torpilles, int degats_torpilles); // constructeur surcharg�

    /*
    Prototype du destructeur
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	~escadron(); // destructeur

    /*
    Prototype de la m�thode affecter
    Red�finition de la m�thode � affecter �. qui va autoriser � modifier les attributs basiques et sp�ciaux.
    Cette m�thode permet de demander � l'utilisateur la valeur des attributs de la classe vaisseau
    Param�tres d'entr�e:
                      - string nom: nom de l'instance vaisseau
                      - int point de vie: nombre de points de vie de l'instance vaisseau
                      - int degats_laser: d�gats occasionn�s par arme laser
                      - int nb tirs torpilles: nb de tirs avec l'arme sp�cials
                      - int degats torpilles: nb de d�gats inflig�s par l'arme torpille
    Param�tres de sortie: aucun
    */
    void affecter(std::string nom, int pts_vie, int degats_laser, int nb_tirs_torpilles, int degats_torpilles); // red�finition de l'affectation des attributs

	/*
    Prototype de la m�thode afficher
    Red�finition de la m�thode afficher.
    Red�finition de l'affichage des informations
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	virtual void afficher(); // m�thode virtuelle pour mise en place du polymorphisme

    /*
    Prototype de la m�thode attaquer_special
    Red�finition de la m�thode
    Cette m�thode permet d'�ter directement des points de vie � un vaisseau cible avec une arme speciale
    Param�tres d'entr�e:
                        vaisseau *: pointeur sur un vaisseau cible
    Param�tres de sortie: aucun
    */
    virtual void attaquer_special (vaisseau *);

    // Fin prototypes des m�thodes de la classe escadron

protected:
    // D�but prototype des attributs de la classe escadron
    int m_degats_torpilles; // d�g�ts de l'arme sp�ciale (torpille pour le escadron)
	int m_nb_tirs_torpilles; // nombre de tirs sp�ciaux restants

    // D�finition des constantes
    const static int NB_TIRS_CANONS_MAX = 5; // nombre max d'utilisation de l'arme sp�ciale
    const static int DEGATS_CANONS_MAX = 100; // attribut qui limite les d�gats max inflig�s � l'ennemi

	// Fin prototype des attributs de la classe escadron
};

/* Fin du prototype de la classe escadron */

#endif // ESCADRON_H_INCLUDED
