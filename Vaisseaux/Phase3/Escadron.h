/*
Fichier Escadron.h
Prototypes des classes et m�thodes
History:
        1.0 - 09/12/2016 TD3 phase 2 prototype d'une classe fille escadron qui h�rite de la classe vaisseau
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
                      - int point de vie: nombre de points de vie de l'instance croiseur
                      - int degats: d�gats occasionn�s par arme
    Param�tres de sortie: aucun
    */
	escadron(std::string nom, int pts_vie, int degats, std::string type); // constructeur surcharg�

    /*
    Prototype du destructeur
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	~escadron(); // destructeur

    // Fin prototypes des m�thodes de la classe croiseur

private:
    // D�but prototype des attributs de la classe escadron


	// Fin prototype des attributs de la classe escadron
};

/* Fin du prototype de la classe croiseur */

#endif // ESCADRON_H_INCLUDED
