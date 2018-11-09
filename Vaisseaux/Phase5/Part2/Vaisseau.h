/*
Fichier Vaisseau.h
Prototypes des classes et méthodes
History:
        1.0 - 30/11/2016 prototype classe vaisseau TD2 Phase 1 & 2
        1.1 - 01/12/2016 prototype classe vaisseau TD2 Phase 3a
                   * nouvel attribut int m_degats_arme_laser
                   * modification méthode affecter pour assignation points de dégats de l'arme au vaisseau
                   => nouveau paramètre
                   * nouvelle méthode subir_degats pour ôter des pts de vie au vaisseau
                   * nouvelle méthode get_degats_arme_laser pour récupérer les dégats infligés par un adversaire(arme laser)
                   * nouvelle méthode get_vie pour vérifier les points de vie restants
        1.2 - 02/12/2016 prototype classe vaisseau TD2 Phase 3b:
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
                    => Modification des constructeurs pour initialiser la valeur de l'attribut "m_type" à « vaisseau ».
                    => Ajout d'une méthode « attaquer_basic » qui utilise l'arme basique arme laser.
                    => Création d'une nouvelle méthode « attaquer_special » qui ne fait rien.
                    => Modification de la méthode afficher pour afficher le type
                    => Tests des modifications dans le « main ».
        1.5 - 16/12/2016 TD3 phase 3 spécialisation du croiseur
                    * Ajout méthode get_type pour retourner le type
        3.1 - 06/11/2017
                    * Adaptation des bibliothèques pour utilisation sous Ubuntu
                    => remplacement de la bibliothèque <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED

#include <string>

/*
Début du prototype de la classe vaisseau
La classe vaisseau sera la classe mère de l'ensemble des futurs types
de vaisseau créés.
*/

class vaisseau
{
public:
    // Début prototypes des méthodes de la classe vaisseau

    /*
    Prototype du constructeur par défaut
    Permet d'initialiser les attributs avec des paramètres par défaut en dur.
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	vaisseau(); // constructeur par défaut

    /*
    Prototype du constructeur de surcharge
    Permet d'initialiser des attributs avec des paramètres fournis par l'utilisateur.
    Paramètres d'entrée:
                      - string nom: nom de l'instance vaisseau
                      - int point de vie: nombre de points de vie de l'instance vaisseau
                      - int degats: dégats occasionnés par arme
    Paramètres de sortie: aucun
    */
	vaisseau(std::string nom, int pts_vie, int degats, std::string type); // constructeur surchargé

    /*
    Prototype du destructeur
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	~vaisseau(); // destructeur

    /*
    Prototype de la méthode affecter
    Cette méthode permet de demander à l'utilisateur la valeur des attributs de la classe vaisseau
    Paramètres d'entrée:
                      - string nom: nom de l'instance vaisseau
                      - int point de vie: nombre de points de vie de l'instance vaisseau
                      - int degats: dégats occasionnés par arme
    Paramètres de sortie: aucun
    */
	void affecter(std::string,int,int);

	/*
    Prototype de la méthode afficher
    Cette méthode permet d'afficher les informations du vaisseau
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	virtual void afficher();

    /*
    Prototype de la méthode subir_degats
    Cette méthode permet d'ôter des nbs de points de vie au vaisseau par l'adversaire
    Paramètres d'entrée:
                      - int dégats: nombre de dégats infligés par l'adversaire
    Paramètres de sortie: aucun
    */
    void subir_degats (int);

    /*
    Prototype de la méthode attaquer_basic
    Cette méthode permet d'ôter directement des points de vie à un vaisseau cible avec une arme basique
    Paramètres d'entrée:
                        vaisseau *: pointeur sur un vaisseau cible
    Paramètres de sortie: aucun
    */
    void attaquer_basic (vaisseau *);

    /*
    Prototype de la méthode attaquer_special
    Cette méthode permet d'ôter directement des points de vie à un vaisseau cible avec une arme speciale
    Paramètres d'entrée:
                        vaisseau *: pointeur sur un vaisseau cible
    Paramètres de sortie: aucun
    */
    virtual void attaquer_special (vaisseau *);

    /*
    Prototype de la méthode get_degats_arme_laser
    Cette méthode permet de récupérer les dégats occasionnés par l'arme laser
    Paramètres d'entrée: aucun

    Paramètres de sortie: int de la valeur des dégats occasionnés par l'arme laser
    */
    int get_degats_arme_laser ();

    /*
    Prototype de la méthode get_vie
    Cette méthode permet de récupérer vérifier les points de vie restants
    Paramètres d'entrée: aucun

    Paramètres de sortie: int de la valeur des points de vie restants
    */
    int get_vie ();

    /*
    Prototype de la méthode get_nom
    Cette méthode permet de récupérer le nom du vaisseau
    Paramètres d'entrée: aucun

    Paramètres de sortie: le nom du vaisseau
    */
    std::string get_nom ();

    /*
    Prototype de la méthode get_type
    Cette méthode permet de récupérer le type du vaisseau
    Paramètres d'entrée: aucun

    Paramètres de sortie: le type du vaisseau
    */
    std::string get_type ();

    // Fin prototypes des méthodes de la classe vaisseau

protected:  // changement de private à protected pour que les classes filles puissent hériter de ces attributs
    // Début prototype des attributs de la classe vaisseau

    // Définition des constantes
    const static int POINTS_VIE_MAX = 200; // Intégrité maximale de la coqie des vaisseaux
    const static int DEGATS_LASER_MAX = 20; // Dégats maximum des armes laser

    // Définition des attributs
    std::string m_nom; //nom de l'instance vaisseau
	int m_points_vie; // nombre de points de vie de l'instance vaisseau
	int m_degats_arme_laser; //attribut désignant les dégâts qu'inflige une arme laser.
	std::string m_type; //type de l'instance vaisseau


	// Fin prototype des attributs de la classe vaisseau
};

/* Fin du prototype de la classe vaisseau */

#endif // VAISSEAU_H_INCLUDED
