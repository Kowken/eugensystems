#include "orc.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

Stun::Stun(Personnage* Utilisateur)
:Capacité(Utilisateur)
{
    setNom("Stun");
}

Stun::~Stun()
{

}

//================================= AUTRES ===============================================================

void Stun::description()
{
    std::cout<<"Permet d'étourdir l'ennemi pendant un tour. Un ennemi étourdi ne pourra pas faire de dégât ce tour-ci."<<std::endl;
    std::cout<<"Cette capacité ne peut être utilisée que tous les 5 tours de jeu. Elle a 20 pourcents de chance de réussir."<<std::endl;
    std::cout<<"Si elle ne réussit pas, il faudra attendre les 5 tours mentionnés ci-dessus pour la tenter de nouveau."<<std::endl;
}

void Stun::effetImmédiat(Personnage* Attaquant)
{
    std::cout<<getUtilisateur()->getNom()<<" utilise sa capacité "<<getNom()<<" !"<<std::endl;
    srand(time(NULL));
    int ChanceRéussite=rand()%10+1;
    if(ChanceRéussite<=6 && !Attaquant->getStun()) //on donne 60 pourcents de chance à la capacité de réussir et on impose comme condition que l'attaquant ne soit pas déjà paralysé
    {
        Attaquant->setStun(true);
        std::cout<<Attaquant->getNom()<<" est désormais paralysé !"<<std::endl;
        for(int i; i<Attaquant->getListeMalus()->size();i++)
        {
            if(Attaquant->getListeMalus()->at(i)->getNomEffet()==getNom())
            {
                Attaquant->getListeMalus()->at(i)->getNombreTours().push_back(1);
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

void Stun::réinitialisationEffet(Personnage* Attaquant)
{
    for(int i; i<Attaquant->getListeMalus()->size();i++)
    {
        if(!Attaquant->getListeMalus()->at(i)->getNombreTours().empty() && Attaquant->getListeMalus()->at(i)->getNomEffet()==getNom() && Attaquant->getListeMalus()->at(i)->getNombreTours()[0]<=0) //on vérifie que la liste n'est pas vide en premier pour éviter les erreurs car la vérification est séquentielle
        {
            Attaquant->setStun(false);
            Attaquant->getListeMalus()->at(i)->getNombreTours().erase(Attaquant->getListeMalus()->at(i)->getNombreTours().begin()); //on efface le marqueur indiquant que l'attaquant est actuellement sous paralysie
            std::cout<<Attaquant->getNom()<<" n'est plus paralysé !"<<std::endl;
        }
    }
}

void Stun::effetParTour(Personnage* Attaquant)
{

}

void Stun::processusRéinitialsationEffet(Personnage* Attaquant)
{

}

//================================= INITIALISATEUR ===============================================================

Personnage* créerOrc(std::string Nom)
{
    Personnage* o_Orc= new Personnage(Nom, 20, 5, 50);
    Stun* o_Stun= new Stun(o_Orc);
    o_Orc->setCapacité(o_Stun);
    return o_Orc;
}