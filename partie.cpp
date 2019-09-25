#include "partie.h"
#include <cstdlib>
#include <time.h>  

Partie::Partie()
{
    srand (time(NULL));
    jouer();
}

void Partie::demarrerPartie()
{
    cout<<"********************************************************************************"<<endl;
    cout<<"*               BIENVENUE SUR LE JEU DES PETITS CHEVAUX                        *"<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"*                                             |\x5c    /|                         *"<<endl;
    cout<<"*                                          ___| \x5c,,/_/                         *"<<endl;
    cout<<"*                                      ---__/ \x5c/     \x5c                         *"<<endl;
    cout<<"*                                      __--/     (D)  \x5c                        *"<<endl;
    cout<<"*                                      _ -/    (_      \x5c                       *"<<endl;
    cout<<"*                                     // /        \x5c_ /==\x5c                      *"<<endl;
    cout<<"*             __-------_____--___--/            /  \x5c_ O o)                     *"<<endl;
    cout<<"*             /                                 /   \x5c== /`                     *"<<endl;
    cout<<"*             /                                 /                              *"<<endl;
    cout<<"*             ||          )                   \x5c_/\x5c                             *"<<endl;
    cout<<"*            ||         /              _      /  |                             *"<<endl;
    cout<<"*           | |      /--______      ___\x5c    /\x5c  :                              *"<<endl;
    cout<<"*            | /   __-  - _/   ------    |  |   \x5c \x5c                            *"<<endl;
    cout<<"*             |   -  -   /               | |     \x5c )                           *"<<endl;
    cout<<"*             |  |   -  |                | )     | |                           *"<<endl;
    cout<<"*             | |    | |                 | |      | |                          *"<<endl;
    cout<<"*             | |    < |                 | |      |_/                          *"<<endl;
    cout<<"*             < |    /__\x5c               <  \x5c                                   *"<<endl;
    cout<<"*            /__\x5c                       /___\x5c            © Sylvain Bourbousse  *"<<endl;
    cout<<"********************************************************************************"<<endl;


    int nbJoueurs;
    do
    {
        cout<<"*                Entrez le nombre de joueurs ( entre 2 et 4 )                  *"<<endl;
        cout<<"********************************************************************************"<<endl;


        cin>>nbJoueurs;cin.ignore(1);
    } while (!(nbJoueurs<=4 && nbJoueurs>=2));

    for (int i=0 ; i<nbJoueurs ; i++)
    {
        string nomJoueur;
        string couleur;
        int position;

        vecJoueur.push_back(Joueur());

        cout<<endl;
        cout<<"  ________________________________________________"<<endl;
        cout<<" /                                                \x5c"<<endl;
        cout<<"|        Entrez le nom du joueur "<<i+1<<"                |"<<endl;
        cout<<" \x5c                                                /"<<endl;
        cout<<"  \x5c__       _____________________________________/"<<endl;
        cout<<"     \x5c     /"<<endl;
        cout<<"      \x5c    /"<<endl;
        cout<<"       \x5c   /"<<endl;
        cout<<"        \x5c /   ***********"<<endl;
        cout<<"           ***** ***********"<<endl;
        cout<<"        ** ****** *** ********"<<endl;
        cout<<"       ****  ******  ** *******"<<endl;
        cout<<"       ***     ******* ** ******"<<endl;
        cout<<"       ***       **        *  **"<<endl;
        cout<<"        *|/------  -------\x5c ** *"<<endl;
        cout<<"         |       |=|       :===**"<<endl;
        cout<<"          |  O  |   | O   |  }|*"<<endl;
        cout<<"           |---- |   ----  |  |*"<<endl;
        cout<<"           |    |___       |\x5c/"<<endl;
        cout<<"           |              |"<<endl;
        cout<<"           \x5c   -----     |"<<endl;
        cout<<"            \x5c           |"<<endl;
        cout<<"              -__ -- -/"<<endl;

        getline(cin,nomJoueur);
        if(i==0) vecJoueur[i]=Joueur(nomJoueur, "jaune", i, -1);
        else
        {
            if(i==1) vecJoueur[i]=Joueur(nomJoueur, "bleu", i, -1);
            else
            {
                if (i==2) vecJoueur[i]=Joueur(nomJoueur, "vert", i, -1);
                else
                {
                    vecJoueur[i]=Joueur(nomJoueur, "rouge", i, -1);
                }   
            }  
        }
    }
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

    /*
        Joueur jaune = joueur 1 , depart case 1 - fin tour 0
        Joueur bleu = joueur 2 , depart case 15 - fin tour 14
        Joueur vert = joueur 3 , depart case 29 - fin tour 28
        Joueur rouge = joueur 4 , depart case 43 - fin tour 42
    */

}

void Partie::jouer()
{
    demarrerPartie();
    //Tant qu'il y a un joueur, les tours continuent
    while(!(vecJoueur.size()==0))
    {
        for (int i = 0 ; i<vecJoueur.size() ; i++)
        {
            tour(i);
        }
    }
    //Affichage du classement
    for(int i=0 ; i<vecClassement.size() ; i++)
    {

            if (i==0) cout<<"En premier : "<<endl;
            else if (i==1) cout<<"En deuxieme : "<<endl;
            else if (i==2) cout<<"En troisieme : "<<endl;
            else cout<<"En dernier : "<<endl;
            vecClassement[i].afficheInfos();
        
    }
}

void Partie::tour(int numTour)
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"*                            C'EST AU TOUR DE                                  *"<<endl;
    cout<<"*                                                                              *"<<endl;
    cout<<"*                                  ";vecJoueur[numTour].direNom();cout<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"*               Appuyez sur une touche pour lancer le dé ...                   *"<<endl;
    cout<<"********************************************************************************"<<endl;

    cin.get();
    int valeurDe=rand() % 6 + 1;

    cout<<"*                                Vous avez fait "<<valeurDe<<"                              *"<<endl;
    cout<<"*                                                                              *"<<endl;


    //Le joueur fait avancer son pion
    vecJoueur[numTour].j_lancerDe(valeurDe);

    vecJoueur[numTour].dessineChevaux();
    cout<<"********************************************************************************"<<endl;

        /* Init. */
        time_t start_time = 0;
        time_t current_time = 0;
    
        /* Operate. */
        start_time = time(NULL);
        // Où 2 est le nombre de secondes
        while(current_time-start_time+1 <= 4)
        {
            current_time = time(NULL);
        }


    // Si la methode du joueur renvoie 1, cela veut dire que son pion est sur la case 106
    if (vecJoueur[numTour].j_termine()==1)
    {
        //On ajoute le joueur dans le tableau des classement
        vecClassement.push_back(vecJoueur[numTour]);
        //On retire le joueur de la partie
        vecJoueur.erase (vecJoueur.begin()+numTour);
    }

    /*if (vecJoueur.size()==1)
    {
        int numTourEt1;
        numTourEt1=numTour+1;
        vecClassement.push_back(vecJoueur[numTourEt1]);
        vecJoueur.erase (vecJoueur.begin()+numTourEt1);
    }*/

    

}
