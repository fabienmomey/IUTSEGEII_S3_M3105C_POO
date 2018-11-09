/* Fichier Main.cpp
Point d'entrée
History:
        1.0 - 30/11/2016 TD2 Phase 1 & 2
        1.1 - 01/12/2016 TD2 Phase 3a
        1.2 - 02/12/2016 TD2 Phase 3b
                * Réalisation d'un compte à rebours + demander saisie d'un caractère
                * A la fin compte à rebours demander saisie d'un caractère
                * En fct du caractère saisi: q pour vaisseau 2 et m vaisseau 1
                * Répéter le duel jusqu'à ce qu'un des deux vaisseaux soit détruit
                * Afficher le vainqueur
        1.3 - 05/12/2016 TD2 Phase 4
                * Définition d'un constructeur par défaut
                * Définition d'un constructeur de surcharge
                * Dans le main.cpp initalisation de deux instances sans utiliser la méthode affecter
                * Définition d'un desctructeur
        1.4 - 07/12/2016 TD3 Phase 1
                * Modifications de la classe "vaisseau"
                    => Rajout d'un attribut de type chaîne « m_type » qui spécifie le type du vaisseau
                    => Modification des constructeurs pour initialiser la valeur de l'ttribut "m_type" à « vaisseau ».
                    => Ajout d'une méthode « attaquer_basic » qui utilise l'arme basique arme laser.
                    => Création d'une nouvelle méthode « attaquer_special » qui ne fait rien.
                    => Modification de la méthode afficher pour afficher le type
                    => Tests des modifications dans le « main ».
        1.5 - 09/12/2016 TD3 Phase 2
                * création d'une instance de croiseur et une instance d'escadron :
                    => duel (comme dans le TD n°2) entre le croiseur et l'escadron en utilisant l'attaque basique.
                    => duel (comme dans le TD n°2) entre le croiseur et l'escadron en utilisant l'attaque spéciale.
        3.0 - 19/12/2016 TD3 Phase 5
        Sujet: Creer une classe pour que votre « main » se résume à l’appel de deux méthodes : « initialiser_jeu » et « lancer_jeu ».
        3.1 - 06/11/2017
                    * Adaptation des bibliothèques pour utilisation sous Ubuntu
                    => remplacement de la bibliothèque <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#include "Jeu.h"

using namespace std;

int main()
{
    // initialisations de l'instance jeu
	jeu duel;

    // initialisation des paramètres du jeu
	duel.initialiser_jeu();

	// lancement du jeu
	duel.lancer_jeu();

    return 0;
}
