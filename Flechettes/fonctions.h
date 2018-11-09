#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

float SaisieImpactX(void);
float SaisieImpactY(void);
float CalculRayonImpact(float, float);
int CalculPointsJeuImpact(float, float);
void CalculPointsJeuImpact_TAB(int tab_points[],float tab_x[], float tab_y[], int taille, int ind);



#endif // FONCTIONS_H_INCLUDED
