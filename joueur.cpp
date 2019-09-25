#include "joueur.h"

Joueur::Joueur()
{
    nom="nobody";
    etat=-1;
}

Joueur::Joueur(string j_nom, string couleurPion, int numeroPion, int positionPion)
{
    nom=j_nom;
    monCheval=Pion(couleurPion, numeroPion, positionPion);
    etat=0;
}

void Joueur::direNom()
{
    if(monCheval.returnCouleur()=="jaune")
    {
        cout<<"\033[93m"<<nom<<"\033[0m";
    }
    else
    {
        if(monCheval.returnCouleur()=="bleu") cout<<"\033[34m"<<nom<<"\033[0m";
        else 
        {
            if(monCheval.returnCouleur()=="vert") cout<<"\033[32m"<<nom<<"\033[0m";
            else
            {
                if(monCheval.returnCouleur()=="rouge") cout<<"\033[31m"<<nom<<"\033[0m";
            }
        }
    }
    
}

void Joueur::j_lancerDe(int valeurDe)
{
    // Utiliser la methode avancerCase du pion du joueur
    monCheval.avancerCase(valeurDe);
}

int Joueur::j_termine()
{
    // Si la methode termine du pion du joueur renvoie 1, cela veut dire que le pion est sur la case 106
    if (monCheval.termine()==true)
    {
        cout<<nom<<" quitte la partie"<<endl;
        etat=1;
        return 1;
    }
    else return 0;
}

void Joueur::afficheInfos()
{
    cout<<"Nom : "<<nom<<"  Couleur : "<<monCheval.returnCouleur()<<endl;
}

void Joueur::dessineChevaux()
{
    if(monCheval.returnCouleur()=="jaune")
    {
        cout<<"\033[93m";
    }
    else
    {
        if(monCheval.returnCouleur()=="bleu") cout<<"\033[34m";
        else 
        {
            if(monCheval.returnCouleur()=="vert") cout<<"\033[32m";
            else
            {
                if(monCheval.returnCouleur()=="rouge") cout<<"\033[31m";
            }
        }
    }
    cout<<"*                    _|\x5c _/|_,                 ._|\x5c_ /|_                       *"<<endl;
    cout<<"*                  ,((\x5c\x5c``-\x5c\x5c\x5c\x5c_             _////-''//)).                     *"<<endl;
    cout<<"*                ,(())      `))\x5c             //(('     (()).                   *"<<endl;
    cout<<"*              ,(()))        < \x5c             / >       ((()).                  *"<<endl;
    cout<<"*             ((())'   |        \x5c           /        |  `(())).                *"<<endl;
    cout<<"*             )))))     >.__     \x5c         /     __.<     (((((                *"<<endl;
    cout<<"*             ((('     /    `-. .d|       |b. .-'    \x5c     `)))                *"<<endl;
    cout<<"*                     /        `-`'       `'-'\x5c                                *"<<endl;
    cout<<"*                                                                              *"<<endl;
    cout<<"*                                                                              *"<<endl;
    cout<<"*                                                                              *"<<endl;
    cout<<"*                                                                              *"<<endl;
    cout<<"\033[0m";
    monCheval.affichePlateau();


}