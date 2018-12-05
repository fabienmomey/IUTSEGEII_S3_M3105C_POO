/*
Fichier felin.cpp

TD Synthèse Classes & Encapsulation : classes felin et mammifere_ongule

Définition des méthodes

History:
        1.0 - 05/12/2018 (Phase 1) Définition des méthodes de la classe felin
                            - constructeurs
                            - affichage des informations
                            - calcul et renvoi de la vitesse
                            - modification du sexe
*/

#include<iostream>
#include<math.h>
#include<limits>
#include"felin.h"

using namespace std;

/*
Constructeur par défaut
=> on définit un individu de l'espèce guépard de sexe femelle, d'âge 0 ans (nouveau-né),
de poids 0.3kg (300g) et de taille 0.03m (30cm)
*/
felin::felin() :
    m_famille("Felin"),
    m_espece("Guepard"),
    m_nom("Anonyme"),
    m_sexe('f'),
    m_age(0),
    m_poids(0.3),
    m_taille(0.03)
{
    m_signes_distinctifs = "aucun signe particulier";
}

/*
Constructeur de surcharge
=> le constructeur teste si la valeur du sexe est valide
*/
felin::felin(std::string espece,
    std::string nom,
    char sexe,
    float age,
    std::string signes,
    float poids,
    float taille) :
    m_famille("Felin"),
    m_espece(espece),
    m_nom(nom),
    m_age(age),
    m_poids(poids),
    m_taille(taille)
{
    cout << sexe << endl;
    if (sexe != 'f' && sexe != 'F' && sexe != 'm' && sexe != 'M')
    {
        cout << "Sexe invalide, re-définir : " << endl;
        cout << "- femelle : 'f' ou 'F' " << endl;
        cout << "- male : 'm' ou 'M' " << endl;
        while (!(cin>>sexe) || (sexe != 'f' && sexe != 'F' && sexe != 'm' && sexe != 'M'))
        {
            cout << "Sexe invalide, re-définir : " << endl;
            cout << "- femelle : 'f' ou 'F' " << endl;
            cout << "- male : 'm' ou 'M' " << endl;
	    if (cin.fail())
            {
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    m_sexe = sexe;
    m_signes_distinctifs = signes;
}

/*
Destructeur
*/
felin::~felin()
{
    felin::afficher();
    cout << "=> Suppression de l'individu" << endl;
}

/*
Méthode d'affichage des informations du félin
*/
void felin::afficher() const
{
    cout << endl << "****************" << endl;
    cout << "Individu : " << m_nom << endl;
    cout << "Famille : " << m_famille << " | " << "Espece : " << m_espece << endl;
    cout << "Age : " << m_age << "ans | " << "Poids : " << m_poids << "kg | " << "Taille : " << m_taille << "m" << endl;
    cout << "Vitesse : " << felin::donner_vitesse() << "km/h"<< endl;
    cout << "Signes distinctifs : " << m_signes_distinctifs << endl << "****************" << endl;
}

/*
Méthode de calcul et renvoi de la vitesse (en km/h)
*/
float felin::donner_vitesse() const
{
    return log10(1+exp(m_taille/m_poids))*100;
}

/*
Méthode de modification du sexe
*/
void felin::modifier_sexe(char sexe)
{
    if (sexe != 'f' && sexe != 'F' && sexe != 'm' && sexe != 'M')
    {
        cout << "Sexe invalide, re-définir : " << endl;
        cout << "- femelle : 'f' ou 'F' " << endl;
        cout << "- male : 'm' ou 'M' " << endl;
        while (!(cin>>sexe) || (sexe != 'f' && sexe != 'F' && sexe != 'm' && sexe != 'M'))
        {
            cout << "Sexe invalide, re-définir : " << endl;
            cout << "- femelle : 'f' ou 'F' " << endl;
            cout << "- male : 'm' ou 'M' " << endl;
	    if (cin.fail())
            {
                std::cin.clear();
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    m_sexe = sexe;
}


