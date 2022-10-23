#include "head.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================
Personnage::Personnage(std::string Nom, int PVMax, int AttaqueBasique, int PVBouclier)
:m_Nom(Nom), m_PVMax(PVMax), m_AttaqueBasique(AttaqueBasique), m_PVBouclier(PVBouclier) //la capacité sera déclarée après car elle doit trouver son parent
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

std::vector<CompteurEffet*>* Personnage::getListeBonus()
{
    return &m_ListeBonus;
}

std::vector<CompteurEffet*>* Personnage::getListeMalus()
{
    return &m_ListeMalus;
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
    if(!getStun)
    {
        std::cout<<getNom()<<" attaque "<<Défenseur->getNom()<<" !"<<std::endl;
        Défenseur->calculDéfense(this);
    }
    else
    {
        std::cout<<getNom()<<" est paralysé: il ne peut pas attaquer !"<<std::endl;
    }
}

void Personnage::calculDéfense(Personnage* Attaquant)
{
    setPV(setPVBouclier(Attaquant->attaqueTotale()));
    std::cout<<Attaquant->getNom()<<"inflige "<<Attaquant->attaqueTotale()<<" dégâts à"<<getNom()<<" !"<<std::endl;
}

void Personnage::utiliserCapacité(Personnage* Attaquant)
{
    if(!getStun())
    {
        if(getCapacité()->getCooldown()<=0)
        {
            std::cout<<getNom()<<" utilise sa capacité "<<getCapacité()->getNom()<<" !"<<std::endl;
            getCapacité()->effetImmédiat(Attaquant);
        }
        else
        {
            std::cout<<"La capacité de "<<getNom()<<" n'a pas fini de se recharger !"<<std::endl;
        }
    }
    else
    {
        std::cout<<getNom()<<"est paralysé: il ne peut pas utiliser sa capacité !"<<std::endl;
    }
}

void Personnage::problemeStatut()
{

}

int Personnage::attaqueTotale()
{
    return getAttaqueBasique()*getCoeffAttaque();
}