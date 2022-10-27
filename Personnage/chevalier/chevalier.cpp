#include "chevalier.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

Charge::Charge(Personnage* Utilisateur)
:Capacité(Utilisateur)
{
    setNom("Charge");
}

Charge::~Charge()
{

}

//================================= AUTRES ===============================================================

void Charge::description()
{
    std::cout<<"Permet de faire le double de dégâts ce tour-ci. Cette capacité ne peut être utilisée que tous les 3 tours de jeu."<<std::endl;
    std::cout<<"Elle a 60 pourcents de chance de réussir. Si elle ne réussit pas, il faudra attendre les 3 tours mentionnés ci-dessus pour la tenter de nouveau."<<std::endl;
}

void Charge::effetImmédiat(Personnage* Attaquant)
{
    srand(time(NULL));
    int ChanceRéussite=rand()%10+1;

    if(ChanceRéussite<=6)
    {
        m_Utilisateur->setCoeffAttaque(2);
        
        for(int i=0; i<m_Utilisateur->getListeBonus()->size();i++)
        {
            //std::cout<<"wsh"<<std::endl; //test
            if(m_Utilisateur->getListeBonus()->at(i)->getNomEffet()==m_Nom)
            {
                //std::cout<<"wsh2"<<std::endl; //test
                m_Utilisateur->getListeBonus()->at(i)->getNombreTours()->push_back(1);
                //std::cout<<m_Utilisateur->getListeBonus()->at(i)->getNombreTours()->at(0)<<std::endl; // test
            }
        }
    }
    else
    {
        std::cout<<"Mais la capacité échoue !"<<std::endl;
    }

    setCooldown(3);

    std::cout<<m_Utilisateur->getNom()<<" doit désormais attendre "<<m_Cooldown<<" tour(s) avant de pouvoir réutiliser cette capacité."<<std::endl;
}

void Charge::réinitialisationEffet(Personnage* Attaquant)
{
    //std::cout<<"Nom: "<<m_Utilisateur->getNom()<<std::endl; //test
    //std::cout<<"Taille effet: "<<m_Utilisateur->getListeBonus()->size()<<std::endl; //test
    for(int i=0; i<m_Utilisateur->getListeBonus()->size();i++)
    {
        //std::cout<<"Taille int: "<<m_Utilisateur->getListeBonus()->at(i)->getNombreTours()->size()<<std::endl; //test
        //std::cout<<"Nom effet: "<<m_Utilisateur->getListeBonus()->at(i)->getNomEffet()<<std::endl; //test
        //std::cout<<"Nom capacité: "<<m_Nom<<std::endl; //test
//        if(!m_Utilisateur->getListeBonus()->at(i)->getNombreTours()->empty()) //test
//        {
//            std::cout<<"Comptage effet: "<<m_Utilisateur->getListeBonus()->at(i)->getNombreTours()->at(0)<<std::endl; //test
//        }
//        else //test
//        {
//            std::cout<<"vide !"<<std::endl; //test
//        }
//        std::cout<<std::endl; //test

        if(!m_Utilisateur->getListeBonus()->at(i)->getNombreTours()->empty() && m_Utilisateur->getListeBonus()->at(i)->getNomEffet()==m_Nom && m_Utilisateur->getListeBonus()->at(i)->getNombreTours()->at(0)<=0)
        {
            //std::cout<<"1dfghjklmkojhifghviseuhrgoiusehrgoirzegioyzehrgioehzgoizergouerzbouehrzzer1"<<std::endl; //test
            m_Utilisateur->setCoeffAttaque(0.5);
            m_Utilisateur->getListeBonus()->at(i)->getNombreTours()->erase(m_Utilisateur->getListeBonus()->at(i)->getNombreTours()->begin());
            std::cout<<m_Utilisateur->getNom()<<" retrouve sa force initiale !"<<std::endl;
        }
    }
}

void Charge::effetParTour(Personnage* Attaquant)
{

}

void Charge::processusRéinitialsationEffet(Personnage* Attaquant)
{

}

//================================= INITIALISATEUR ===============================================================

Personnage* créerChevalier(std::string Nom)
{
    Personnage* o_Chevalier= new Personnage(Nom, 20, 5, 50);
    Charge* o_Charge= new Charge(o_Chevalier);
    o_Chevalier->setCapacité(o_Charge);
    return o_Chevalier;
}