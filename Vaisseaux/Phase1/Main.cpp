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
        1.5 - 06/11/2017
                    * Adaptation des bibliothèques pour utilisation sous Ubuntu
                    => remplacement de la bibliothèque <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#include <iostream>
#include <string>
#include <cstdlib> // pour generateur de nb aléatoire
#include "Vaisseau.h"
#include <time.h>
//#include <Windows.h>
#include <stdio.h> // getchar()
#include <unistd.h>

using namespace std;

int main()
{
    cout << "         ****************************************          " << endl;
    cout << "***********************************************************" << endl;
    cout << "Welcome in star wars. Not allowed below 14 years OLD !!!!!!" << endl;
    cout << "***********************************************************" << endl;
    cout << "         ****************************************          " << endl;

    srand(time (NULL)); // Initialisation du générateur de nb aléatoire

	// Début déclaration variables locales au main saus instances vaisseau
	string nom_vaisseau1,nom_vaisseau2; // nom des deux vaisseaux
	int pts_vie1,degats1;
    int pts_vie2,degats2;
    bool type_attaque; // type d'attaque demandée à l'utilisateur. O pour basique, 1 pour spéciale

    char touche; // touche appuyée lors du combat
    int compte_a_rebours; // gère la valeur du compte à rebours
	// Fin déclaration variables locales au main

	// SAISIE des données pour vaisseau 1
	cout << "Donnez un nom au vaisseau 1 : ";
	cin >> nom_vaisseau1;
	cout << "Entrez le nombre de points de vie de votre vaisseau 1: ";
	cin >> pts_vie1;
	cout << "Entrez la valeur des degats occasionnes par votre vaisseau 1: ";
	cin >> degats1;
	// SAISIE des données pour vaisseau 2
	cout << "Donnez un nom au vaisseau 2 : ";
	cin >> nom_vaisseau2;
	cout << "Entrez le nombre de points de vie de votre vaisseau 2: ";
	cin >> pts_vie2;
	cout << "Entrez la valeur des degats occasionnes par votre vaisseau 2: ";
	cin >> degats2;

    // Déclaration des instances de la classe vaisseau
    vaisseau vaisseau1 (nom_vaisseau1, pts_vie1, degats1,"vaisseau"); // utilisation du constructeur de surcharge
    vaisseau vaisseau2 (nom_vaisseau2, pts_vie2, degats2, "vaisseau"); // utilisation du constructeur de surcharge

    // affichage des attributs de mes instances
    vaisseau1.afficher();
    vaisseau2.afficher();

    // Début implementation de la Phase 3b:

    cout << endl << "******** LE COMBAT VA COMMENCER ******** !!!" << endl << endl;
	cout << "Vaisseau " << vaisseau1.get_nom() << " se voit attribue la touche q" << endl;
	cout << "Vaisseau " << vaisseau2.get_nom() << " se voit attribue la touche m" << endl << endl;
	cout << "Au signal, le premier a appuyer sur sa touche inflige des degats a son adversaire" << endl << endl;

	cout << "Appuyez sur ENTREE pour lancer un nouvel assaut ..." << endl << endl;
	getchar();

	do {
		// COMPTE A REBOURS ENTRE 3 ET 6 SECONDES
		compte_a_rebours = rand() % (7 - 3) + 3; // génération du compte à rebours
		cout << "Tenez-vous prets a tirer ... \n\n";
		//Sleep(1000 * compte_a_rebours); // Pause de x seconds
		sleep(compte_a_rebours); // Pause de x seconds
		cout << "A L'ASSAUT ! ";
		cin >> touche;
		cout << endl;
		cin.ignore(); // prendre en compte uniquement le premier caractère sélectionné

        switch (touche)  // début du test de la touche sélectionnée
		{
		case 'q': // le joueur qui a le vaisseau 1 a appuyé le premier
			cout << "Vaisseau " << vaisseau1.get_nom() << " attaque " << "vaisseau " << vaisseau2.get_nom() << endl << endl;
			// vaisseau2.subir_degats(vaisseau1.get_degats_arme_laser()); // TD numéro 2
            cout << "Quel est le type d'attaque que vous souhaitez? 0 pour basique ou 1 pour speciale" << endl;
            cin >> type_attaque;

            if (!type_attaque) vaisseau1.attaquer_basic(&vaisseau2); // TD3 Phase 1 utilisation de la méthode attaquer_basic
            else vaisseau1.attaquer_special(&vaisseau2); // TD3 Phase 1 test de la méthode attaquer_special qui ne fait rien

			vaisseau1.afficher();// Affectation du nombre de points de vie
			vaisseau2.afficher();
			break;
		case 'm': // le joueur qui a le vaisseau 2 a appuyé le premier
			cout << "Vaisseau " << vaisseau2.get_nom() << " attaque " << "vaisseau " << vaisseau1.get_nom() << endl << endl;
			// vaisseau1.subir_degats(vaisseau2.get_degats_arme_laser()); // TD numéro 2
            cout << "Quel est le type d'attaque que vous souhaitez? 0 pour basique ou 1 pour speciale" << endl;
            cin >> type_attaque;

            if (!type_attaque) vaisseau2.attaquer_basic(&vaisseau1); // TD3 Phase 1 utilisation de la méthode attaquer_basic
            else vaisseau2.attaquer_special(&vaisseau1); // TD3 Phase 1 test de la méthode attaquer_special qui ne fait rien

			vaisseau1.afficher();
			vaisseau2.afficher();
			break;
		default:
			cout << " Mauvais choix de touche: aucun des deux vaisseaux n'a atteint sa cible" << endl << endl;
			break;
		} // fin du test de la touche sélectionnée
		cout << "Appuyez sur ENTREE pour lancer un nouvel assaut ..." << endl << endl;
		getchar();

	} while (vaisseau1.get_vie()!=0 && vaisseau2.get_vie() != 0); // duel répété jusqu'à un
                                                                  // des deux vaisseaux soit détruit
    // début du test du choix du vainqueur
	if (vaisseau1.get_vie() == 0)
	{
	cout << "Vaisseau " << vaisseau2.get_nom() << " a detruit " << "vaisseau " << vaisseau1.get_nom() << endl;
	}

	if (vaisseau2.get_vie() == 0)
	{
	cout << "Vaisseau " << vaisseau1.get_nom() << " a detruit " << "vaisseau " << vaisseau2.get_nom() << endl << endl;
	}

	// fin du test du choix du vainqueur

    cout << "         ****************************************          " << endl;
    cout << "***********************************************************" << endl;
    cout << "*** I hope you had fun. See you in star wars world ***q!!!!!" << endl;
    cout << "***********************************************************" << endl;
    cout << "         ****************************************          " << endl;


    // Fin de l'implementation de la Phase 3b

    return 0;
}
