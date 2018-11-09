/*
Fichier Jeu.h
Prototypes des classes et méthodes
History:
        1.0 - 19/12/2016 prototype classe jeu TD3 Phase 5
        Sujet: Creer une classe pour que votre « main » se résume à l’appel de deux méthodes : « initialiser_jeu » et « lancer_jeu ».
        3.1 - 06/11/2017
                    * Adaptation des bibliothèques pour utilisation sous Ubuntu
                    => remplacement de la bibliothèque <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <string>
#include "Vaisseau.h"

/*
Début du prototype de la classe jeu
La classe jeu gérera l'ensemble des vaisseaux de tous types, initialisera le jeu et lancera le jeu.
*/

class jeu
{
public:
    // Début prototypes des méthodes de la classe jeu

    /*
    Prototype du constructeur par défaut
    Permet d'initialiser les attributs avec des paramètres par défaut en dur.
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	jeu(); // constructeur par défaut

    /*
    Prototype du destructeur
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	~jeu(); // destructeur

    /*
    Prototype de la méthode initialiser_jeu
    Cette méthode permet d'initialiser l'ensemble des données du jeu
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	void initialiser_jeu(void);

	/*
    Prototype de la méthode lancer_jeu
    Cette méthode permet de lancer le jeu
    Paramètres d'entrée: aucun
    Paramètres de sortie: aucun
    */
	void lancer_jeu();

    // Fin prototypes des méthodes de la classe jeu

protected:
    // Début prototype des attributs de la classe jeu

    // Définition des constantes

    // Définition des attributs
	vaisseau * m_destroyer; // sera spécialisé en croiseur
	vaisseau * m_chasseur; // sera spécialisé en escadron

	// Fin prototype des attributs de la classe jeu
};

/* Fin du prototype de la classe vaisseau */

#endif // JEU_H_INCLUDED
