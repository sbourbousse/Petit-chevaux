#include "pion.h"
Pion::Pion()
{
    numero=-1;
}

Pion::Pion(string p_couleur, int p_numero, int p_position)
{
    couleur=p_couleur;
    numero=p_numero;
    position=p_position;
    nombreCaseAvance=0;
    for(int i=0 ; i<56 ; i++)
    {
        plateau.push_back("_");
    }
}

void Pion::avancerCase(int lanceDe)
{
    // Si la position du pion est inferieur à 100 (debut du jeu)
    if (position<100)
    {
        // Si le pion est à la position -1, il doit faire un 6 pour rentrer sur la première case qui lui correspond
        if (position==-1)
        {
            if (lanceDe==6)
            {
                std::cout<<"*     -Vous pouvez commencer à jouer.                                          *"<<endl;

                // Si le joueur est le numero 0, il commence sur la case 1
                if (numero == 0) position = 1;
                else
                {
                    // Si le joueur est le numero 1, il commence sur la case 15
                    if(numero == 1) position = 15;
                    else
                    {
                        // Si le joueur est le numero 2, il commence sur la case 29
                        if(numero == 2) position = 29;
                        // Sinon (numero 3) , il commence sur la case 43
                        else position = 43;
                    }
                }  
            }
        }
        else
        {
            // Si la somme de la valeur du dé et de la case de la position du pion est superieur à 56 mais inferieur à 100, le joueur retourne à la case 0
            if (position+lanceDe >= 56 && position+lanceDe < 100)
            {
                position = position + lanceDe - 56; //Car la case 0 existe
            }
            // Sinon tout se deroule normalement, le pion avance le nombre de case de la valuer du dé
            else
            {
                position=position+lanceDe;
            }
            nombreCaseAvance=nombreCaseAvance+lanceDe;
        }

        // Si le pion numero 0 depasse la case 0, la derniere case lui correspondant, il arrive à la case 100
        if (numero == 0 && position > 0 && nombreCaseAvance>56 && position < 100) position = position+100;
            else
            {
                // Si le pion numero 1 depasse la case 14, la derniere case lui correspondant, il arrive à la case 100
                if (numero == 1 && position > 14 && nombreCaseAvance>56 && position < 100) position = position-14+100;
                else
                {
                    // Si le pion numero 2 depasse la case 28, la derniere case lui correspondant, il arrive à la case 100
                    if (numero == 2 && position > 28 && nombreCaseAvance>56 && position < 100) position = position-28+100;
                    else
                    {
                        // Si le pion numero 3 depasse la case 42, la derniere case lui correspondant, il arrive à la case 100
                        if (numero == 3 && position > 42 && nombreCaseAvance>56 && position < 100) position = position-42+100;
                    }
                        
                }        
            }


    }
    // Sinon (si la position est suprieur ou egal à 100)
    else
    {
        // Si le pion tombe sur la case 106, il à gagné
        if (position+lanceDe==106)
        {
            std::cout<<"Vous avez gagné"<<endl;
            position=position+lanceDe;
        }
        else
        {
            // Si arrive au dessus de la case 106
            if (position+lanceDe>106)
            {
                int calculRecul = position+lanceDe-106;
                std::cout<<"Vous avez fait trop, vous reculez de "<<calculRecul<<" cases."<<endl;
                // faire reculer le pion
                position= 106-calculRecul;
            }
            else
            {
                // Tout se passe normalement
                if(position+lanceDe<106)
                {
                    position=position+lanceDe;
                }
            }
            
        }
    }
    if(position>9 || position<0) std::cout<<"*     -Vous etes sur la case "<<position<<"                                                *"<<endl;
    else  std::cout<<"*     -Vous etes sur la case "<<position<<"                                                 *"<<endl;

}

bool Pion::termine()
{
    // Si le pion est sur la case 106 on retourne la valeur 1
    return position==106;
}

string Pion::returnCouleur()
{
    return couleur;
}

void Pion::affichePlateau()
{
    std::cout<<"*           ";
    if (position>=-1 && position<=56)
    {
        for(int i = 0; i<plateau.size() ; i++)
        {
            if(numero==0 && i==1) std::cout<<"[]";
            else
            {
                if(numero==1 && i==15) std::cout<<"[]";
                else
                {
                    if(numero==2 && i==29) std::cout<<"[]";
                    else
                    {
                        if (numero==3 && i==43) std::cout<<"[]";
                    }
                }    
            }
            
            if (position==i) std::cout<<"♞";
            else std::cout<<plateau[i];

            
        }
    }
    else
    {
        if (position==100) std::cout<<"[*][][][][][][]";
        else
        {
            if(position==101) std::cout<<"[][*][][][][][]";
            else
            {
                if(position==102) std::cout<<"[][][*][][][][]";
                else
                {
                    if(position==103) std::cout<<"[][][][*][][][]";
                    else
                    {
                        if(position==104) std::cout<<"[][][][][*][][]";
                        else
                        {
                            if(position==105) std::cout<<"[][][][][][*][]";
                            else std::cout<<"[][][][][][][$]";
                        }
                        
                    }
                            
                }
                
            }
            
        }
    }
    std::cout<<"         *"<<endl;
}