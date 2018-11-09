/*
Fichier Escadron.h
Prototypes des classes et méthodes
History:
        1.0 - 09/12/2016 TD3 phase 2 prototype d'une classe fille escadron qui hérite de la classe vaisseau
        1.6 - 06/11/2017
                    * Adaptation des bibliothèques pour utilisation sous Ubuntu
                    => remplacement de la bibliothèque <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#ifndef ESCADRON_H_INCLUDED
#define ESCADRON_H_INCLUDED

#include <string>
#include "Vaisseau.h" //Prototypes de la classe vaisseau

/*
Début du prototype de la classe escadron classe fille de la classe vaisseau
*/

class escadron : public vaisseau
{
public:

    // Début prototypes des méthodes de la classe escadron
    /*
    Prototype du constructeur par défaut
    Permet d'initialiser les attributs avec des paramètres par défaut en dur.
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	escadron(); // constructeur par défaut

    /*
    Prototype du constructeur de surcharge
    Permet d'initialiser des attributs avec des paramètres fournis par l'utilisateur.
    Paramètres d'entrée:
                      - string nom: nom de l'instance escadron
                      - int point de vie: nombre de points de vie de l'instance croiseur
                      - int degats: dégats occasionnés par arme
    Paramètres de sortie: aucun
    */
	escadron(std::string nom, int pts_vie, int degats, std::string type); // constructeur surchargé

    /*
    Prototype du destructeur
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	~escadron(); // destructeur

    // Fin prototypes des méthodes de la classe croiseur

private:
    // Début prototype des attributs de la classe escadron


	// Fin prototype des attributs de la classe escadron
};

/* Fin du prototype de la classe croiseur */

#endif // ESCADRON_H_INCLUDED
