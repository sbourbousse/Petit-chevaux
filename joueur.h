#include "pion.h"

class Joueur{
    private:
        string nom;
        Pion monCheval;
        int etat;
    public:
        Joueur();
        Joueur(string j_nom, string couleurPion, int numeroPion, int positionPion);
        void direNom();
        void j_lancerDe(int valeurDe);
        int j_termine();
        void afficheInfos();
        void dessineChevaux();
};