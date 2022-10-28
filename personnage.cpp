#include "head.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================
Personnage::Personnage(std::string Nom, int PVMax, int AttaqueBasique, int PVBouclier)
:m_Nom(Nom), m_PVMax(PVMax), m_PV(PVMax), m_AttaqueBasique(AttaqueBasique), m_PVBouclier(PVBouclier) //la capacité sera déclarée après car elle doit trouver son parent
{
    CompteurEffet* Stun = new CompteurEffet("Stun");
    CompteurEffet* Charge = new CompteurEffet("Charge");
    m_ListeBonus.push_back(Charge);
    m_ListeMalus.push_back(Stun);
}

Personnage::~Personnage()
{
    delete m_Capacité;
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

void Personnage::setAttaqueBasique(double deltaAttaqueBasique)
{
    m_AttaqueBasique+=deltaAttaqueBasique;
}

void Personnage::setCoeffAttaque(double deltaCoeffAttaque)
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
    std::cout<<"Nom: "<<m_Nom<<std::endl;
    std::cout<<"Points de vie: "<<m_PV<<"/"<<getPVMax()<<" | Points de défense: "<<m_PVBouclier<<std::endl;
    std::cout<<"Capacité: "<<m_Capacité->getNom()<<" | Temps de recharge restant: "<<m_Capacité->getCooldown()<<" tour(s)"<<std::endl;
    std::cout<<"Description:"<<std::endl;
    m_Capacité->description();
    std::cout<<std::endl;
    std::cout<<"Statut:"<<std::endl;
    std::cout<<"Paralysie: "<<getStun()<<std::endl;

}

void Personnage::attaquer(Personnage* Défenseur)
{
    if(!m_Stun)
    {
        std::cout<<m_Nom<<" attaque "<<Défenseur->getNom()<<" !"<<std::endl;
        Défenseur->calculDéfense(this);
    }
    else
    {
        std::cout<<m_Nom<<" est paralysé: il ne peut pas attaquer !"<<std::endl;
    }
}

void Personnage::calculDéfense(Personnage* Attaquant)
{
    setPV(-setPVBouclier(-Attaquant->attaqueTotale()));
    std::cout<<Attaquant->getNom()<<" inflige "<<Attaquant->attaqueTotale()<<" dégâts à "<<m_Nom<<" !"<<std::endl;
}

void Personnage::utiliserCapacité(Personnage* Attaquant)
{
    if(!m_Stun)
    {
        if(m_Capacité->getCooldown()<=0)
        {
            std::cout<<m_Nom<<" utilise sa capacité "<<m_Capacité->getNom()<<" !"<<std::endl;
            m_Capacité->effetImmédiat(Attaquant);
        }
        else
        {
            std::cout<<"La capacité de "<<m_Nom<<" n'a pas fini de se recharger !"<<std::endl;
        }
    }
    else
    {
        std::cout<<m_Nom<<"est paralysé: il ne peut pas utiliser sa capacité !"<<std::endl;
    }
}

void Personnage::problemeStatut()
{

}

int Personnage::attaqueTotale()
{
    return m_AttaqueBasique*m_CoeffAttaque;
}