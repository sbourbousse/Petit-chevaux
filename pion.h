#include <iostream>
#include <vector>
using namespace std;

class Pion{
    private:
        string couleur;
        int numero;
        int position;
        int nombreCaseAvance;
        vector<string> plateau;
        
    public:
        Pion();
        Pion(string p_couleur, int p_numero, int p_position);
        void avancerCase(int lanceDe);
        bool termine();
        string returnCouleur();
        void affichePlateau();
};