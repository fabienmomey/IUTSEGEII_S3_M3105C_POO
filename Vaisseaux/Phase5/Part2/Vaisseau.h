/*
Fichier Vaisseau.h
Prototypes des classes et m�thodes
History:
        1.0 - 30/11/2016 prototype classe vaisseau TD2 Phase 1 & 2
        1.1 - 01/12/2016 prototype classe vaisseau TD2 Phase 3a
                   * nouvel attribut int m_degats_arme_laser
                   * modification m�thode affecter pour assignation points de d�gats de l'arme au vaisseau
                   => nouveau param�tre
                   * nouvelle m�thode subir_degats pour �ter des pts de vie au vaisseau
                   * nouvelle m�thode get_degats_arme_laser pour r�cup�rer les d�gats inflig�s par un adversaire(arme laser)
                   * nouvelle m�thode get_vie pour v�rifier les points de vie restants
        1.2 - 02/12/2016 prototype classe vaisseau TD2 Phase 3b:
                    * definition de deux constantes pour le max de points de vie POINTS_VIE_MAX et le maximum
                    de d�gats occasionn�s par une arme laser DEGATS_LASER_MAX
                    => modifications de la m�thode affecter pour prise en compte de POINTS_VIE_MAX et DEGATS_LASER_MAX
                    * definition du m�thode get_nom pour renvoie du nom du vaisseau
        1.3 - 05/12/2016 TD2 Phase 4
                    * D�finition d'un constructeur par d�faut
                    * D�finition d'un constructeur de surcharge
                    * D�finition d'un destructeur
        1.4 - 07/12/2016 TD3 Phase 1
                    * Modifications de la classe "vaisseau"
                    => Rajout d'un attribut de type cha�ne � m_type � qui sp�cifie le type du vaisseau
                    => Modification des constructeurs pour initialiser la valeur de l'attribut "m_type" � � vaisseau �.
                    => Ajout d'une m�thode � attaquer_basic � qui utilise l'arme basique arme laser.
                    => Cr�ation d'une nouvelle m�thode � attaquer_special � qui ne fait rien.
                    => Modification de la m�thode afficher pour afficher le type
                    => Tests des modifications dans le � main �.
        1.5 - 16/12/2016 TD3 phase 3 sp�cialisation du croiseur
                    * Ajout m�thode get_type pour retourner le type
        3.1 - 06/11/2017
                    * Adaptation des biblioth�ques pour utilisation sous Ubuntu
                    => remplacement de la biblioth�que <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#ifndef VAISSEAU_H_INCLUDED
#define VAISSEAU_H_INCLUDED

#include <string>

/*
D�but du prototype de la classe vaisseau
La classe vaisseau sera la classe m�re de l'ensemble des futurs types
de vaisseau cr��s.
*/

class vaisseau
{
public:
    // D�but prototypes des m�thodes de la classe vaisseau

    /*
    Prototype du constructeur par d�faut
    Permet d'initialiser les attributs avec des param�tres par d�faut en dur.
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	vaisseau(); // constructeur par d�faut

    /*
    Prototype du constructeur de surcharge
    Permet d'initialiser des attributs avec des param�tres fournis par l'utilisateur.
    Param�tres d'entr�e:
                      - string nom: nom de l'instance vaisseau
                      - int point de vie: nombre de points de vie de l'instance vaisseau
                      - int degats: d�gats occasionn�s par arme
    Param�tres de sortie: aucun
    */
	vaisseau(std::string nom, int pts_vie, int degats, std::string type); // constructeur surcharg�

    /*
    Prototype du destructeur
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	~vaisseau(); // destructeur

    /*
    Prototype de la m�thode affecter
    Cette m�thode permet de demander � l'utilisateur la valeur des attributs de la classe vaisseau
    Param�tres d'entr�e:
                      - string nom: nom de l'instance vaisseau
                      - int point de vie: nombre de points de vie de l'instance vaisseau
                      - int degats: d�gats occasionn�s par arme
    Param�tres de sortie: aucun
    */
	void affecter(std::string,int,int);

	/*
    Prototype de la m�thode afficher
    Cette m�thode permet d'afficher les informations du vaisseau
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	virtual void afficher();

    /*
    Prototype de la m�thode subir_degats
    Cette m�thode permet d'�ter des nbs de points de vie au vaisseau par l'adversaire
    Param�tres d'entr�e:
                      - int d�gats: nombre de d�gats inflig�s par l'adversaire
    Param�tres de sortie: aucun
    */
    void subir_degats (int);

    /*
    Prototype de la m�thode attaquer_basic
    Cette m�thode permet d'�ter directement des points de vie � un vaisseau cible avec une arme basique
    Param�tres d'entr�e:
                        vaisseau *: pointeur sur un vaisseau cible
    Param�tres de sortie: aucun
    */
    void attaquer_basic (vaisseau *);

    /*
    Prototype de la m�thode attaquer_special
    Cette m�thode permet d'�ter directement des points de vie � un vaisseau cible avec une arme speciale
    Param�tres d'entr�e:
                        vaisseau *: pointeur sur un vaisseau cible
    Param�tres de sortie: aucun
    */
    virtual void attaquer_special (vaisseau *);

    /*
    Prototype de la m�thode get_degats_arme_laser
    Cette m�thode permet de r�cup�rer les d�gats occasionn�s par l'arme laser
    Param�tres d'entr�e: aucun

    Param�tres de sortie: int de la valeur des d�gats occasionn�s par l'arme laser
    */
    int get_degats_arme_laser ();

    /*
    Prototype de la m�thode get_vie
    Cette m�thode permet de r�cup�rer v�rifier les points de vie restants
    Param�tres d'entr�e: aucun

    Param�tres de sortie: int de la valeur des points de vie restants
    */
    int get_vie ();

    /*
    Prototype de la m�thode get_nom
    Cette m�thode permet de r�cup�rer le nom du vaisseau
    Param�tres d'entr�e: aucun

    Param�tres de sortie: le nom du vaisseau
    */
    std::string get_nom ();

    /*
    Prototype de la m�thode get_type
    Cette m�thode permet de r�cup�rer le type du vaisseau
    Param�tres d'entr�e: aucun

    Param�tres de sortie: le type du vaisseau
    */
    std::string get_type ();

    // Fin prototypes des m�thodes de la classe vaisseau

protected:  // changement de private � protected pour que les classes filles puissent h�riter de ces attributs
    // D�but prototype des attributs de la classe vaisseau

    // D�finition des constantes
    const static int POINTS_VIE_MAX = 200; // Int�grit� maximale de la coqie des vaisseaux
    const static int DEGATS_LASER_MAX = 20; // D�gats maximum des armes laser

    // D�finition des attributs
    std::string m_nom; //nom de l'instance vaisseau
	int m_points_vie; // nombre de points de vie de l'instance vaisseau
	int m_degats_arme_laser; //attribut d�signant les d�g�ts qu'inflige une arme laser.
	std::string m_type; //type de l'instance vaisseau


	// Fin prototype des attributs de la classe vaisseau
};

/* Fin du prototype de la classe vaisseau */

#endif // VAISSEAU_H_INCLUDED
