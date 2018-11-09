/* Fichier Main.cpp
Point d'entr�e
History:
        1.0 - 30/11/2016 TD2 Phase 1 & 2
        1.1 - 01/12/2016 TD2 Phase 3a
        1.2 - 02/12/2016 TD2 Phase 3b
                * R�alisation d'un compte � rebours + demander saisie d'un caract�re
                * A la fin compte � rebours demander saisie d'un caract�re
                * En fct du caract�re saisi: q pour vaisseau 2 et m vaisseau 1
                * R�p�ter le duel jusqu'� ce qu'un des deux vaisseaux soit d�truit
                * Afficher le vainqueur
        1.3 - 05/12/2016 TD2 Phase 4
                * D�finition d'un constructeur par d�faut
                * D�finition d'un constructeur de surcharge
                * Dans le main.cpp initalisation de deux instances sans utiliser la m�thode affecter
                * D�finition d'un desctructeur
        1.4 - 07/12/2016 TD3 Phase 1
                * Modifications de la classe "vaisseau"
                    => Rajout d'un attribut de type cha�ne � m_type � qui sp�cifie le type du vaisseau
                    => Modification des constructeurs pour initialiser la valeur de l'ttribut "m_type" � � vaisseau �.
                    => Ajout d'une m�thode � attaquer_basic � qui utilise l'arme basique arme laser.
                    => Cr�ation d'une nouvelle m�thode � attaquer_special � qui ne fait rien.
                    => Modification de la m�thode afficher pour afficher le type
                    => Tests des modifications dans le � main �.
        1.5 - 09/12/2016 TD3 Phase 2
                * cr�ation d'une instance de croiseur et une instance d'escadron :
                    => duel (comme dans le TD n�2) entre le croiseur et l'escadron en utilisant l'attaque basique.
                    => duel (comme dans le TD n�2) entre le croiseur et l'escadron en utilisant l'attaque sp�ciale.
        3.0 - 19/12/2016 TD3 Phase 5
        Sujet: Creer une classe pour que votre � main � se r�sume � l�appel de deux m�thodes : � initialiser_jeu � et � lancer_jeu �.
        3.1 - 06/11/2017
                    * Adaptation des biblioth�ques pour utilisation sous Ubuntu
                    => remplacement de la biblioth�que <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#include "Jeu.h"

using namespace std;

int main()
{
    // initialisations de l'instance jeu
	jeu duel;

    // initialisation des param�tres du jeu
	duel.initialiser_jeu();

	// lancement du jeu
	duel.lancer_jeu();

    return 0;
}
