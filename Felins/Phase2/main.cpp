/*
Fichier main.cpp

TD Synthèse Classes & Encapsulation : classes felin et mammifere_ongule

Programme de test

History:
        1.0 - 05/12/2018 (Phase 1) Test de manipulation d'instances de la classe felin
        1.1 - 05/12/2018 (Phase 2) Test de manipulation d'instances de la classe mammifere_ongule
*/

#include<iostream>
#include<math.h>
#include"felin.h"
#include"mammifere_ongule.h"

using namespace std;

int main()
{
    cout << "*** BIENVENUE A FELINIC PARK ***" << endl;

    /* Déclaration des 2 félins par 2 méthodes différentes */
    felin simba;
    felin mufasa("Lion","Mufasa",'m',15,"Large criniere, cicatrice à l'oeil gauche.", 150, 1.5);

    /* Affichage des informations des félins */
    simba.afficher();
    mufasa.afficher();

    /* Modification des caractéristiques du félin "simba" */
    simba.modifier_espece("Lion");
    simba.modifier_nom("Simba");
    simba.modifier_sexe('g');
    simba.modifier_age(1);
    simba.modifier_signes_distinctifs("Fils de Mufasa.");
    simba.modifier_poids(10);
    simba.modifier_taille(0.5);

    /* Ré-affichage des informations du félin "simba" */
    simba.afficher();

    /* Déclaration des 2 mammifères ongulés par 2 méthodes différentes */
    mammifere_ongule bambi;
    mammifere_ongule ragnar("Gnou","Ragnar",'m',8,"Corne gauche cassée.",200,2);

    /* Affichage des informations des mammifères ongulés */
    bambi.afficher();
    ragnar.afficher();

    /* Modification des caractéristiques du mammifère ongulé "bambi" */
    bambi.modifier_nom("Bambi");
    bambi.modifier_sexe('t');
    bambi.modifier_age(0.5);
    bambi.modifier_signes_distinctifs("Taches blanches sur le dos.");
    bambi.modifier_poids(8);
    bambi.modifier_taille(0.7);

    /* Ré-affichage des informations du mammifère ongulé "bambi" */
    bambi.afficher();

    return 0;
}
