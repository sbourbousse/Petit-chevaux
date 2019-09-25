#include "joueur.h"

class Partie{
    private:
        vector <Joueur> vecJoueur;
        vector <Joueur> vecClassement;

    public:
        Partie();
        void demarrerPartie();
        void jouer();
        void tour(int numTour);

};