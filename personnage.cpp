#include "head.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================
Personnage::Personnage(std::string Nom, int PVMax, int AttaqueBasique, int PVBouclier, Capacité* Capacité)
:m_Nom(Nom), m_PVMax(PVMax), m_AttaqueBasique(AttaqueBasique), m_PVBouclier(PVBouclier), m_Capacité(Capacité)
{

}

Personnage::~Personnage()
{

}

//================================= GETTERS ==============================================================

std::string Personnage::getNom()
{
    return m_Nom;
}

int Personnage::getPV()
{
    return m_PV;
}

int Personnage::getPVMax()
{
    return m_PVMax;
}

int Personnage::getAttaqueBasique()
{
    return m_AttaqueBasique;
}

int Personnage::getCoeffAttaque()
{
    return m_CoeffAttaque;
}

int Personnage::getPVBouclier()
{
    return m_PVBouclier;
}

Capacité* Personnage::getCapacité()
{
    return m_Capacité;
}

bool Personnage::getVivant()
{
    return m_Vivant;
}

bool Personnage::getStun()
{
    return m_Stun;
}

//================================= SETTERS ===============================================================

void Personnage::setNom(std::string deltaNom)
{
    m_Nom=deltaNom;
}       

void Personnage::setPV(int deltaPV)
{
    m_PV+=deltaPV;
    m_PV=std::max(m_PV,0);
}

void Personnage::setPVMax(int deltaPVMax)
{
    m_PVMax+=deltaPVMax;
}

void Personnage::setAttaqueBasique(int deltaAttaqueBasique)
{
    m_AttaqueBasique+=deltaAttaqueBasique;
}

void Personnage::setCoeffAttaque(int deltaCoeffAttaque)
{
    m_CoeffAttaque*=deltaCoeffAttaque;
}

int Personnage::setPVBouclier(int detlaPVBouclier)
{
    int DégâtsRésiduels;
    m_PVBouclier+=detlaPVBouclier;
    if(m_PVBouclier<0)
    {
        DégâtsRésiduels=std::abs(m_PVBouclier);
        m_PVBouclier=0;
        return DégâtsRésiduels;
    }
    else
    {
        return 0;
    }
}

void Personnage::setCapacité(Capacité* deltaCapacité)
{
    m_Capacité=deltaCapacité;
}

void Personnage::setVivant(bool deltaVivant)
{
    m_Vivant=deltaVivant;
}

void Personnage::setStun(bool deltaStun)
{
    m_Stun=deltaStun;
}

//================================= AUTRES ==============================================================
void Personnage::afficherStatut()
{
    std::cout<<"Nom: "<<getNom()<<std::endl;
    std::cout<<"PV: "<<getPVMax()<<" / "<<getPV()<<std::endl;
    std::cout<<"Bouclier: "<<getPVBouclier()<<std::endl;
    std::cout<<"Capacité: "<<getCapacité()->getNom()<<" Temps de chargement restant: "<<getCapacité()->getCooldown()<<std::endl;
}

void Personnage::attaquer(Personnage* Défenseur)
{
    std::cout<<getNom()<<" attaque "<<Défenseur->getNom()<<" !"<<std::endl;
    Défenseur->calculDéfense(this);
}

void Personnage::calculDéfense(Personnage* Attaquant)
{

}

void Personnage::utiliserCapacité()
{

}

void Personnage::problemeStatut()
{

}