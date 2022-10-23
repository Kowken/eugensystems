#include "head.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

Combat::Combat()
{

}

Combat::~Combat()
{

}

//================================= GETTERS ==============================================================

int Combat::getNombreDeTours()
{
    return m_NombreDeTours;
}

std::vector<Personnage*>* Combat::getPoolPersonnageJoueur1()
{
 return m_PoolPersonnageJoueur1;
}

std::vector<Personnage*>* Combat::getPoolPersonnageJoueur2()
{
 return m_PoolPersonnageJoueur2;
}

Personnage* Combat::getJoueur1()
{
 return m_Joueur1;
}

Personnage* Combat::getJoueur2()
{
 return m_Joueur2;
}

bool Combat::getTourJoueur1Fini()
{
 return m_TourJoueur1Fini;
}

bool Combat::getTourJoueur2Fini()
{
 return m_TourJoueur2Fini;
}

bool Combat::getJoueur1Encours()
{
    return m_Joueur1Encours;
}

bool Combat::getVictoireJoueur1()
{
    return m_VictoireJoueur1;
}

bool Combat::getVictoireJoueur2()
{
    return m_VictoireJoueur2;
}

//================================= SETTERS ===============================================================

void Combat::setNombreDeTours(int DeltaNombreDeTours)
{
    m_NombreDeTours+=DeltaNombreDeTours;
}

void Combat::setPoolPersonnageJoueur1()
{
    
}

void Combat::setPoolPersonnageJoueur2()
{

}

void Combat::setJoueur1(Personnage* DeltaJoueur1)
{
    m_Joueur1=DeltaJoueur1;
}

void Combat::setJoueur2(Personnage* DeltaJoueur2)
{
    m_Joueur2=DeltaJoueur2;
}

void Combat::setTourJoueur1Fini(bool DeltaTourJoueur1Fini)
{
    m_TourJoueur1Fini=DeltaTourJoueur1Fini;
}

void Combat::setTourJoueur2Fini(bool DeltaTourJoueur2Fini)
{
    m_TourJoueur2Fini=DeltaTourJoueur2Fini;
}

void Combat::setJoueur1Encours(bool DeltaJoueur1Encours)
{
    m_Joueur1Encours=DeltaJoueur1Encours;
}

void Combat::setVictoireJoueur1(bool DeltaVictoireJoueur1)
{
    m_VictoireJoueur1=DeltaVictoireJoueur1;
}

void Combat::setVictoireJoueur2(bool DeltaVictoireJoueur2)
{
    m_VictoireJoueur2=DeltaVictoireJoueur2;
}

//================================= AUTRES ===============================================================

void Combat::afficherCombat(Personnage* Personnage1, Personnage* Personnage2)
{
    
}

void Combat::selectionPersonnages()
{

}

void Combat::utiliserCapacité(Personnage* Attaquant, Personnage* Défenseur)
{

}


bool Combat::mortDePersonnage(Personnage* Personnage1, Personnage* Personnage2)
{
    if(Personnage1->getPV()<=0)
    {
        setVictoireJoueur2(true);
    }
    if(Personnage2->getPV()<=0)
    {
        setVictoireJoueur1(true);
    }
    if(getVictoireJoueur1()||getVictoireJoueur2()) //implémentation d'un futur cas d'égalité
    {
        return true;
    }
    return false;
}


bool Combat::finDuCombat()
{
    if(mortDePersonnage) //fonction redondante pour le moment mais possible implémentation de conditions supplémentaires de victoire
    {
        return true;
    }
    return false;
}

void Combat::Attaque(Personnage* Attaquant, Personnage* Défenseur)
{

}

void Combat::Combattre()
{
    srand(time(NULL));
    int QuiCommence=rand()%2+1;

    Personnage* Attaquant;
    Personnage* Défenseur;
    Personnage* Joueur1;
    Personnage* Joueur2;

    int ChoixAction;

    if(QuiCommence==1) //On choisit au hasard qui commence
    {
        setJoueur1Encours(true);
        std::cout<<"Le joueur 1 commence."<<std::endl;
    }
    else
    {
        setJoueur1Encours(false);
        std::cout<<"Le joueur 2 commence."<<std::endl;
    }

    do
    {
        do
        {
            if(getJoueur1Encours()) //initiation des rôles d'attaquant et de défenseur ainsi que de l'état des tours
            {
                Attaquant=Joueur1;
                Défenseur=Joueur2;
                setTourJoueur1Fini(false);
            }
            else
            {
                Attaquant=Joueur2;
                Défenseur=Joueur1;
                setTourJoueur2Fini(false);
            }

            do
            {
                
            }
            while (MenuActions(Attaquant, Défenseur)!=1||MenuActions(Attaquant, Défenseur)!=3); //cas d'attaque (1) ou d'abandon (3)

            if(getJoueur1Encours()) //changement de joueur est mise à jour de l'état de chacun
            {
                setJoueur1Encours(false);
                setTourJoueur1Fini(true);
            }
            else
            {
                setJoueur1Encours(true);
                setTourJoueur2Fini(true);
            }
        } 
        while ((!getTourJoueur1Fini()||!getTourJoueur2Fini()) || !mortDePersonnage(Joueur1, Joueur2)); //
    } 
    while (!finDuCombat());
    
}

int Combat::MenuActions(Personnage* Attaquant, Personnage* Défenseur)
{

}