#include "head.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

Capacité::Capacité(std::string nomUtilisateur)
:m_nomUtilisateur(nomUtilisateur)
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

std::string Capacité::getNomUtilisateur()
{
    return m_nomUtilisateur;
}

//================================= SETTERS ===============================================================

void Capacité::setNom(std::string deltaNom)
{
    m_Nom=deltaNom;
}

void Capacité::setCooldown(int deltaCooldown)
{
    m_Cooldown+=deltaCooldown;
}

void Capacité::setNomUtilisateur(std::string deltaNomUtilisateur)
{
    m_nomUtilisateur=deltaNomUtilisateur;
}

//================================= AUTRES ===============================================================

void Capacité::description()
{

}

void Capacité::effetImmédiat()
{

}

void Capacité::réinitialisationEffet()
{

}

void Capacité::effetParTour()
{

}

void Capacité::processusRéinitialsationEffet()
{

}