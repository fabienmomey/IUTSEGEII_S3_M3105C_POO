/*
Fichier main.cpp

TD Synthèse Classes & Encapsulation : classes felin et mammifere_ongule

Programme de test

History:
        1.0 - 05/12/2018 (Phase 1) Test de manipulation d'instances de la classe felin
        1.1 - 05/12/2018 (Phase 2) Test de manipulation d'instances de la classe mammifere_ongule
        1.3 - 05/12/2018 (Phase 3) Test de la méthode "se_nourrir" de la classe mammifere_ongule
        1.4 - 05/12/2018 (Phase 4) Test de la méthode "chasser" de la classe felin
*/

#include<iostream>
#include<math.h>
#include"felin.h"
#include"mammifere_ongule.h"

using namespace std;

int main()
{
    cout << "*** BIENVENUE A FELINIC PARK ***" << endl;

    /* Déclaration des 2 félins */
    felin *simba = new felin("Lion","Simba",'m',15,"Fils de Mufasa.", 10, 0.5);
    felin *mufasa = new felin("Lion","Mufasa",'m',15,"Large criniere, cicatrice à l'oeil gauche.", 150, 1.5);

    /* Affichage des informations des félins */
    mufasa->afficher();
    simba->afficher();

    /* Déclaration des 2 mammifères ongulés */
    mammifere_ongule *bambi = new mammifere_ongule("Antilope","Bambi",'f',0.5,"Taches blanches sur le dos.",8,0.7);
    mammifere_ongule *ragnar = new mammifere_ongule("Gnou","Ragnar",'m',8,"Corne gauche cassée.",200,2);

    /* Affichage des informations des mammifères ongulés */
    bambi->afficher();
    ragnar->afficher();

    /* Simulation de l'alimentation du mammifère ongulé "ragnar" */
    ragnar->se_nourrir(4);
    ragnar->afficher();

    /* Simulation de l'alimentation du mammifère ongulé "bambi" */
    bambi->se_nourrir(5);
    bambi->afficher();

    /* Simulation de chasse du félin "mufasa" sur la proie "bambi" */
    if (mufasa->chasser(bambi))
    {
        delete bambi;
        bambi = NULL;
    }

    mufasa->afficher();

    /* Simulation de chasse du félin "simba" sur la proie "ragnar" */
    if (simba->chasser(ragnar))
    {
        delete ragnar;
        ragnar = NULL;
    }
    simba->afficher();

    /* Désallocations */
    if (mufasa != NULL)
    {
        delete mufasa;
    }
    if (simba != NULL)
    {
        delete simba;
    }
    if (ragnar != NULL)
    {
        delete ragnar;
    }
    if (bambi != NULL)
    {
        delete bambi;
    }

    return 0;
}
