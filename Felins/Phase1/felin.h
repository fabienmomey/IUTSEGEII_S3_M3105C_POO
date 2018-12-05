/*
Fichier felin.h

TD Synthèse Classes & Encapsulation : classes felin et mammifere_ongule

Prototypes des classes et méthodes

History:
        1.0 - 05/12/2018 (Phase 1) Définition de la classe felin
*/

#ifndef FELIN_H_INCLUDED
#define FELIN_H_INCLUDED

/*
Définition de la classe FELIN
*/
class felin {

    /* Méthodes */
    public:
        // Constructeur par défaut
        felin();
        // Constructeur de surcharge
        felin(std::string espece, std::string nom, char sexe, float age, std::string signes, float poids, float taille);
        // Destructeur
        ~felin();
        // Affichage des informations du félin
        void afficher() const;
        // Calcul et renvoi de la vitesse (en km/h)
        float donner_vitesse() const;
        // Méthodes "setter" définies en ligne (sauf modifier_sexe) de modification d'attributs
        void modifier_espece(std::string espece) {m_espece = espece;}
        void modifier_nom(std::string nom) {m_nom = nom;}
        void modifier_sexe(char sexe);
        void modifier_age(float age) {m_age = age;}
        void modifier_signes_distinctifs(std::string signes) {m_signes_distinctifs = signes;}
        void modifier_poids(float poids) {m_poids = poids;}
        void modifier_taille(float taille) {m_taille = taille;}
        // Méthodes "getter" définies en ligne de renvoi de valeurs d'attributs
        std::string donner_famille() const {return m_famille;}
        std::string donner_espece() const {return m_espece;}
        std::string donner_nom() const {return m_nom;}
        char donner_sexe() const {return m_sexe;}
        float donner_age() const {return m_age;}
        std::string donner_signes_distinctifs() const {return m_signes_distinctifs;}
        float donner_poids() const {return m_poids;}
        float donner_taille() const {return m_taille;}

    /* Attributs */
    private:
        // Nom de la famille : "felin"
        std::string m_famille;
        // Nom de l'espece : "lion", "guépard", "léopard", etc.
        std::string m_espece;
        // Nom de l’individu
        std::string m_nom;
        // Sexe de l’individu ('m' ou 'f' ou 'M' ou 'F')
        char m_sexe;
        // Age de l’individu (en années)
        float m_age;
        // Signes distinctifs
        std::string m_signes_distinctifs;
        // Poids de l'individu (en kg)
        float m_poids;
        // Taille de l'individu (en m)
        float m_taille;
};

#endif // FELIN_H_INCLUDED
