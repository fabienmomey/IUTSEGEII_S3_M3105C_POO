#include "fonctions.h"
#include <iostream>
#include<math.h>

using namespace std;




/*****************************************************************************
ver 18.10.22
cette fonction permet de saisir au clavier la coordonnée x du point d'impact
*****************************************************************************/

float SaisieImpactX(void)
{
    float local_x;
    cout << endl << "Veuillez rentrer la position X ?" << endl;
    cin >> local_x;
    return local_x;
}

/*****************************************************************************
ver 18.10.22
cette fonction permet de saisir au clavier la coordonnée y du point d'impact
*****************************************************************************/

float SaisieImpactY(void)
{

    float local_y;
    cout << endl << "Veuillez rentrer la position Y ?" << endl;
    cin >> local_y;
    return local_y;
}

/*****************************************************************************
ver 18.10.22
cette fonction permet de calculer la distance entre l'impact et el centre de la cible
*****************************************************************************/

float CalculRayonImpact(float local_x, float local_y)
{
    float rayon;
    rayon = sqrt(local_x*local_x+local_y*local_y);
    return rayon;
}



/*****************************************************************************
ver 18.10.22
cette fonction permet de calculer le nbre de points résultant d'un lancé
*****************************************************************************/

int CalculPointsJeuImpact(float local_x, float local_y)
{
    int local_points;
    int pts;
    float rayon;

    rayon = CalculRayonImpact(local_x, local_y);
    if (rayon <= 2)
        pts = 10;
    else if (rayon <= 4)
        pts = 8;
    else if (rayon <= 6)
        pts = 6;
    else if (rayon <= 8)
        pts = 4;
    else if (rayon <= 10)
        pts = 2;

    if (local_x >= 0)
    {
        if (local_y >= 0)
            local_points = pts * 0,5;
        else
            local_points = pts*3 - 10;
    }
    else
    {
        if (local_y >= 0)
            local_points = pts * 2 - 5;
        else
            local_points = pts*4;
    }
    return local_points;
}



/*****************************************************************************
ver 18.11.05
cette fonction permet de calculer le nbre de points résultant d'un lancé, elle rajoute une modif du calcul des pts en fct des scores
et également la gestion des tableaux
*****************************************************************************/

void CalculPointsJeuImpact_TAB(int tab_points[],float tab_x[], float tab_y[], int taille, int ind)
{
    int local_points;
    int score_tot;
    int pts;
    float rayon;
    int i;


    // ici j'ai fait le choix de prendre la somme des scores
    // on aurait pu prendre simplement le dernie score et donc mettre
    // score_tot =  0;
    // if (ind > 0) score_tot = tab_points[i-1];
    score_tot = 0;
    for (i=0;i<ind;i++)
    {
        score_tot = score_tot + tab_points[i];
    }

    rayon = CalculRayonImpact(tab_x[ind], tab_y[ind]);
    if (rayon <= 2)
        pts = 10;
    else if (rayon <= 4)
        pts = 8;
    else if (rayon <= 6)
        pts = 6;
    else if (rayon <= 8)
        pts = 4;
    else if (rayon <= 10)
        pts = 2;

    if (tab_x[ind] >= 0)
    {
        if (tab_y[ind] >= 0)
            local_points = pts*0.5 + score_tot*2;
        else
            local_points = pts*3 - 10+score_tot;
    }
    else
    {
        if (tab_y[ind] >= 0)
            local_points = pts * 2 - 5+score_tot;
        else
            local_points = pts*5-score_tot/2;
    }
    tab_points[ind] = local_points;
}
