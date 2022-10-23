#include "chevalier.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

Charge::Charge(Personnage* Utilisateur, std::string Nom)
:Capacité(Utilisateur)
{
    setNom(Nom);
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
    for(int i; i<Attaquant->getListeMalus()->size();i++)
    {
        if(!Attaquant->getListeMalus()->at(i)->getNombreTours().empty() && Attaquant->getListeMalus()->at(i)->getNomEffet()==getNom() && Attaquant->getListeMalus()->at(i)->getNombreTours()[0]<=0) //on vérifie que la liste n'est pas vide en premier pour éviter les erreurs car la vérification est séquentielle
        {
            Attaquant->setStun(false);
             //on efface le marqueur indiquant que l'attaquant est actuellement sous paralysie
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

}