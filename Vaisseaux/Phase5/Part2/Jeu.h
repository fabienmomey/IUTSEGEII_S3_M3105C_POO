/*
Fichier Jeu.h
Prototypes des classes et m�thodes
History:
        1.0 - 19/12/2016 prototype classe jeu TD3 Phase 5
        Sujet: Creer une classe pour que votre � main � se r�sume � l�appel de deux m�thodes : � initialiser_jeu � et � lancer_jeu �.
        3.1 - 06/11/2017
                    * Adaptation des biblioth�ques pour utilisation sous Ubuntu
                    => remplacement de la biblioth�que <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <string>
#include "Vaisseau.h"

/*
D�but du prototype de la classe jeu
La classe jeu g�rera l'ensemble des vaisseaux de tous types, initialisera le jeu et lancera le jeu.
*/

class jeu
{
public:
    // D�but prototypes des m�thodes de la classe jeu

    /*
    Prototype du constructeur par d�faut
    Permet d'initialiser les attributs avec des param�tres par d�faut en dur.
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	jeu(); // constructeur par d�faut

    /*
    Prototype du destructeur
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	~jeu(); // destructeur

    /*
    Prototype de la m�thode initialiser_jeu
    Cette m�thode permet d'initialiser l'ensemble des donn�es du jeu
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	void initialiser_jeu(void);

	/*
    Prototype de la m�thode lancer_jeu
    Cette m�thode permet de lancer le jeu
    Param�tres d'entr�e: aucun
    Param�tres de sortie: aucun
    */
	void lancer_jeu();

    // Fin prototypes des m�thodes de la classe jeu

protected:
    // D�but prototype des attributs de la classe jeu

    // D�finition des constantes

    // D�finition des attributs
	vaisseau * m_destroyer; // sera sp�cialis� en croiseur
	vaisseau * m_chasseur; // sera sp�cialis� en escadron

	// Fin prototype des attributs de la classe jeu
};

/* Fin du prototype de la classe vaisseau */

#endif // JEU_H_INCLUDED
