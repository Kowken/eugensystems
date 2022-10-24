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
    std::cout<<getUtilisateur()->getNom()<<" utilise sa capacité "<<getNom()<<" !"<<std::endl;

    srand(time(NULL));
    int ChanceRéussite=rand()%10+1;

    if(ChanceRéussite<=6)
    {
        getUtilisateur()->setCoeffAttaque(2);
        
        for(int i; i<getUtilisateur()->getListeBonus()->size();i++)
        {
            if(getUtilisateur()->getListeBonus()->at(i)->getNomEffet()==getNom())
            {
                getUtilisateur()->getListeBonus()->at(i)->getNombreTours().push_back(1);
            }
        }
    }
    else
    {
        std::cout<<"Mais la capacité échoue !"<<std::endl;
    }

    setCooldown(3);

    std::cout<<getUtilisateur()->getNom()<<" doit désormais attendre "<<getCooldown()<<" tour(s) avant de pouvoir réutiliser cette capacité."<<std::endl;
}

void Charge::réinitialisationEffet(Personnage* Attaquant)
{
    for(int i; i<getUtilisateur()->getListeBonus()->size();i++)
    {
        if(!getUtilisateur()->getListeBonus()->at(i)->getNombreTours().empty() && getUtilisateur()->getListeBonus()->at(i)->getNomEffet()==getNom() && getUtilisateur()->getListeBonus()->at(i)->getNombreTours()[0]<=0)
        {
            getUtilisateur()->setCoeffAttaque(0.5);
            getUtilisateur()->getListeBonus()->at(i)->getNombreTours().erase(getUtilisateur()->getListeBonus()->at(i)->getNombreTours().begin());
            std::cout<<getUtilisateur()->getNom()<<" retrouve sa force initiale !"<<std::endl;
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