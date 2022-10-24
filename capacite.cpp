#include "head.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================



Capacité::Capacité(Personnage* Utilisateur)
:m_Utilisateur(Utilisateur)
{

}

Capacité::~Capacité()
{

}

//================================= GETTERS ==============================================================

std::string Capacité::getNom()
{
    return m_Nom;
}

int Capacité::getCooldown()
{
 return m_Cooldown;
}

Personnage* Capacité::getUtilisateur()
{
    return m_Utilisateur;
}

//================================= SETTERS ===============================================================

void Capacité::setNom(std::string deltaNom)
{
    m_Nom=deltaNom;
}

void Capacité::setCooldown(int deltaCooldown)
{
    m_Cooldown+=deltaCooldown;
    m_Cooldown=std::max(m_Cooldown,0);
}

void Capacité::setUtilisateur(Personnage* deltaUtilisateur)
{
    m_Utilisateur=deltaUtilisateur;
}

//================================= AUTRES ===============================================================

void Capacité::description()
{

}

void Capacité::effetImmédiat(Personnage* Attaquant)
{

}

void Capacité::réinitialisationEffet(Personnage* Attaquant)
{

}

void Capacité::effetParTour(Personnage* Attaquant)
{

}

void Capacité::processusRéinitialsationEffet(Personnage* Attaquant)
{

}