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


void Combat::mortDePersonnage()
{

}


void Combat::finDuCombat()
{

}

void Combat::Attaque(Personnage* Attaquant, Personnage* Défenseur)
{

}

void Combat::Combattre()
{

}