#include "fonctions.h"
#include<iostream>

using namespace std;
/****************************************************************************************
Programme de test :
functions flechettes
version 18.11.05
test de l'utilisation des tabeaux dynamiques
*****************************************************************************************/

int main()
{
    int nbtirs;
    int i;
    float* pt_tabx;
    float* pt_taby;
    int* pt_points;

    cout << endl << "Nbre de tirs";
    cin >> nbtirs;

    pt_tabx = new float[nbtirs];
    pt_taby = new float[nbtirs];
    pt_points = new int[nbtirs];


    for (i=0;i<nbtirs;i++)
    {
        cout << endl << "tir n° " << i+1;
        pt_tabx[i] = SaisieImpactX();
        pt_taby[i] = SaisieImpactY();
        CalculPointsJeuImpact_TAB(pt_points,pt_tabx,pt_taby,nbtirs,i);
        cout << endl << "nbr de points " << pt_points[i] << "  du tir n° " << i+1;
    }

    delete pt_tabx;
    delete pt_taby;
    delete pt_points;

    pt_tabx = NULL;
    pt_taby = NULL;
    pt_points = NULL;

    return 0;

}
