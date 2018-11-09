/* Fichier Jeu.cpp
D�claration des m�thodes
History:
        1.0 - 19/12/2016 prototype classe jeu TD3 Phase 5
        Sujet: Creer une classe pour que votre � main � se r�sume � l�appel de deux m�thodes : � initialiser_jeu � et � lancer_jeu �.
        3.1 - 06/11/2017
                    * Adaptation des biblioth�ques pour utilisation sous Ubuntu
                    => remplacement de la biblioth�que <Windows.h> par <unistd.h> pour utiliser la fonction sleep
                    au lieu de Sleep
                    * Correction d'un bug : #include "Vaisseau.h" au lieu de #include "vaisseau.h"
*/

#include <iostream>
#include <string>
#include <cstdlib> // pour generateur de nb al�atoire
#include "Vaisseau.h"
#include "Croiseur.h"
#include "Jeu.h"
#include "Escadron.h"
#include <time.h>
//#include <Windows.h>
#include <unistd.h>
#include <stdio.h> // getchar()

using namespace std;

/*
D�but de la d�claration des m�thodes de la classe jeu
*/

// D�claration du constructeur implicite

jeu::jeu()
{
	// cout << "Appel du constructeur de la classe jeu " << endl << endl;
}

// D�claration du destructeur

jeu::~jeu()
{
	// cout << "Appel du destructeur (desallocation memoire) du jeu: " << endl;

}

// D�claration de la m�thode initialiser_jeu

void jeu::initialiser_jeu(void)
{
    cout << "         ****************************************          " << endl;
    cout << "***********************************************************" << endl;
    cout << "Welcome in star wars. Not allowed below 14 years OLD !!!!!!" << endl;
    cout << "***********************************************************" << endl;
    cout << "         ****************************************          " << endl;


	// D�but d�claration variables locales au main saus instances vaisseau
        // Vaisseaux de type  croiseur
	string nom_croiseur_c1;
	int pts_vie_c1,degats_laser_c1,nb_tirs_canonsmax_c1,degats_canons_c1;

        // Vaisseaux de type  croiseur
	string nom_escadron_e1;
	int pts_vie_e1,degats_laser_e1,nb_tirs_torpmax_e1,degats_torp_e1;

	// SAISIE des donn�es pour vaisseau de type croiseur
	cout << "***********************************************************" << endl;
	cout << "Donnez un nom au destroyer du type croiseur: ";
	cin >> nom_croiseur_c1;
	cout << "Entrez le nombre de points de vie de votre destroyer du type croiseur: ";
	cin >> pts_vie_c1;
	cout << "Entrez la valeur des degats occasionnes par le laser de votre destroyer du type croiseur: ";
	cin >> degats_laser_c1;
	cout << "Entrez le maximum d'attaque par canon de votre destroyer du type croiseur: ";
	cin >> nb_tirs_canonsmax_c1;
	cout << "Entrez la valeur des degats occasionnes par les canons de votre destroyer du type croiseur: ";
	cin >> degats_canons_c1;
	cout << "***********************************************************" << endl;

	// SAISIE des donn�es pour vaisseau de type escadron
	cout << "***********************************************************" << endl;
	cout << "Donnez un nom au chasseur du type escadron : ";
	cin >> nom_escadron_e1;
	cout << "Entrez le nombre de points de vie du chasseur de type escadron: ";
	cin >> pts_vie_e1;
	cout << "Entrez la valeur des degats occasionnes par votre chasseur de type escadron: ";
	cin >> degats_laser_e1;
	cout << "Entrez le maximum d'attaque par torpille de votre chasseur de type escadron: ";
	cin >> nb_tirs_torpmax_e1;
	cout << "Entrez la valeur des degats occasionnes par les torpilles de votre chasseur de type escadron: ";
	cin >> degats_torp_e1;
	cout << "***********************************************************" << endl;

    // D�claration des instances de la classe croiseur

        // Illustration du polymorphisme
        // Manipulation d'un objet d'une classe fille "croiseur" � partir d'un pointeur
        // de sa classe m�re "vaisseau" avec le m�canisme des fonctions virtuelles comme afficher()
        m_destroyer = new croiseur (nom_croiseur_c1, pts_vie_c1, degats_laser_c1,"destroyer fantastique",nb_tirs_canonsmax_c1,degats_canons_c1);

    // D�claration des instances de la classe escadron

        // Illustration du polymorphisme
        // Manipulation d'un objet d'une classe fille "escadron" � partir d'un pointeur
        // de sa classe m�re "vaisseau" avec le m�canisme des fonctions virtuelles comme afficher()
        m_chasseur = new escadron (nom_escadron_e1, pts_vie_e1, degats_laser_e1,"chasseur fou",nb_tirs_torpmax_e1,degats_torp_e1);

    // affichage des attributs de mes instances croiseurs
    m_destroyer->afficher(); //avec le m�canisme du polymorphisme appelle de la m�thode afficher() de la classe croiseur
    // affichage des attributs de mes instances escadron
    m_chasseur->afficher(); //avec le m�canisme du polymorphisme appelle de la m�thode afficher() de la classe croiseur
}

// D�claration de la m�thode lancer_jeu

void jeu::lancer_jeu()
{
    // D�claration  variables
    bool type_attaque; // type d'attaque s�lectionn�e FAUX pour basique VRAI pour sp�ciale
    char touche; // touche appuy�e lors du combat
    int compte_a_rebours; // g�re la valeur du compte � rebours

    srand(time (NULL)); // Initialisation du g�n�rateur de nb al�atoire

    cout << "***********************************************************" << endl;
    cout << endl << "******** LE COMBAT VA COMMENCER ******** !!!" << endl << endl;
	cout << "Le destroyer de type croiseur " << m_destroyer->get_nom() << " se voit attribue la touche q" << endl;
	cout << "Le chasseur de type escadron " << m_chasseur->get_nom() << " se voit attribue la touche m" << endl << endl;
	cout << "Au signal, le premier a appuyer sur sa touche inflige des degats a son adversaire" << endl << endl;

	cout << "Appuyez sur ENTREE pour lancer un nouvel assaut ..." << endl << endl;
	getchar();

	do {
		// COMPTE A REBOURS ENTRE 3 ET 6 SECONDES
		compte_a_rebours = rand() % (7 - 3) + 3; // g�n�ration du compte � rebours
		cout << "Tenez-vous prets a tirer ... \n\n";
		//Sleep(1000 * compte_a_rebours); // Pause de x seconds
		sleep(compte_a_rebours); // Pause de x seconds
		cout << "A L'ASSAUT ! ";
		cin >> touche;
		cout << endl;
		cin.ignore(); // prendre en compte uniquement le premier caract�re s�lectionn�

        switch (touche)  // d�but du test de la touche s�lectionn�e
		{
		case 'q': // le joueur qui a le croiseur 1 a appuy� le premier
            cout << "Le destroyer de type croiseur " << m_destroyer->get_nom() << " attaque " << "le chasseur de type escadron " << m_chasseur->get_nom() << endl << endl;

            cout << "Quel est le type d'attaque que vous souhaitez? 0 pour basique ou 1 pour speciale" << endl;
            cin >> type_attaque;

            if (!type_attaque) m_destroyer->attaquer_basic(m_chasseur); // utilisation m�thode attaquer_basic
            else m_destroyer->attaquer_special(m_chasseur); // utilisation m�thode attaquer_special

			m_destroyer->afficher();
			m_chasseur->afficher();
			break;
		case 'm': // le joueur qui a le vaisseau 2 a appuy� le premier
			cout << "Le chasseur de type escadron " << m_chasseur->get_nom() << " attaque " << "le destroyer de type croiseur " << m_destroyer->get_nom() << endl << endl;

            cout << "Quel est le type d'attaque que vous souhaitez? 0 pour basique ou 1 pour speciale" << endl;
            cin >> type_attaque;

            if (!type_attaque) m_chasseur->attaquer_basic(m_destroyer); // utilisation m�thode attaquer_basic
            else m_chasseur->attaquer_special(m_destroyer); // utilisation m�thode attaquer_special

			m_destroyer->afficher();
			m_chasseur->afficher();
			break;
		default:
			cout << " Mauvais choix de touche: aucun des deux vaisseaux n'a atteint sa cible" << endl << endl;
			break;
		} // fin du test de la touche s�lectionn�e
		cout << "Appuyez sur ENTREE pour lancer un nouvel assaut ..." << endl << endl;
		getchar();

	} while (m_destroyer->get_vie()!=0 && m_chasseur->get_vie() != 0); // duel r�p�t� jusqu'� un
                                                                  // des deux vaisseaux soit d�truit
    // d�but du test du choix du vainqueur
	if (m_destroyer->get_vie() == 0)
	{
	cout << "Le chasseur de type escadron " << m_chasseur->get_nom() << " a detruit " << "le destroyer de type croiseur " << m_destroyer->get_nom() << endl;
	}

	if (m_chasseur->get_vie() == 0)
	{
	cout << "Le destroyer de type croiseur " << m_destroyer->get_nom() << " a detruit " << "le chasseur de type escadron " << m_chasseur->get_nom() << endl << endl;
	}

	// fin du test du choix du vainqueur

    cout << "         ****************************************          " << endl;
    cout << "***********************************************************" << endl;
    cout << "*** I hope you had fun. See you in star wars world ***q!!!!!" << endl;
    cout << "***********************************************************" << endl;
    cout << "         ****************************************          " << endl;

    // Fin de l'implementation de la Phase 3b

}

/* Fin de la d�claration des m�thodes de la classe  jeu */
