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
 return &m_PoolPersonnageJoueur1;
}

std::vector<Personnage*>* Combat::getPoolPersonnageJoueur2()
{
 return &m_PoolPersonnageJoueur2;
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

bool Combat::getVictoireJoueur1()
{
    return m_VictoireJoueur1;
}

bool Combat::getVictoireJoueur2()
{
    return m_VictoireJoueur2;
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

void Combat::setVictoireJoueur1(bool DeltaVictoireJoueur1)
{
    m_VictoireJoueur1=DeltaVictoireJoueur1;
}

void Combat::setVictoireJoueur2(bool DeltaVictoireJoueur2)
{
    m_VictoireJoueur2=DeltaVictoireJoueur2;
}

//================================= AUTRES ===============================================================

void Combat::afficherCombat(Personnage* Attaquant, Personnage* Défenseur)
{
    std::cout<<"Attaquant:"<<std::endl;
    Attaquant->afficherStatut();

    std::cout<<std::endl;

    std::cout<<"Défenseur:"<<std::endl;
    Défenseur->afficherStatut();
}

void Combat::selectionPersonnages()
{
    int ChoixPersonnage=0;

    std::cout<<"Joueur 1, choisissez votre personnage"<<std::endl;
    std::cout<<std::endl;
    for(int i=0;i<m_PoolPersonnageJoueur1.size();i++)
    {
        std::cout<<i+1<<". "<<m_PoolPersonnageJoueur1[i]->getNom()<<std::endl;
    }

    do
    {
        std::cin>>ChoixPersonnage;
    } 
    while (ChoixPersonnage<1 || ChoixPersonnage>m_PoolPersonnageJoueur1.size());

    setJoueur1(m_PoolPersonnageJoueur1[ChoixPersonnage-1]);

    std::cout<<"Joueur 2, choisissez votre personnage"<<std::endl;
    std::cout<<std::endl;
    for(int i=0;i<m_PoolPersonnageJoueur2.size();i++)
    {
        std::cout<<i+1<<". "<<m_PoolPersonnageJoueur2[i]->getNom()<<std::endl;
    }

    do
    {
        std::cin>>ChoixPersonnage;
    } 
    while (ChoixPersonnage<1 || ChoixPersonnage>m_PoolPersonnageJoueur2.size());

    setJoueur2(m_PoolPersonnageJoueur2[ChoixPersonnage-1]);

    std::cout<<std::endl;
    std::cout<<"Les jeux sont faits ! Préparez-vous au combat"<<std::endl;
    std::cout<<std::endl;
}

void Combat::utiliserCapacité(Personnage* Attaquant, Personnage* Défenseur) //implémentation future de plusieurs skills par perso
{
    Attaquant->utiliserCapacité(Défenseur);
}


bool Combat::mortDePersonnage()
{
    if(m_Joueur1->getPV()<=0)
    {
        std::cout<<"Le joueur 1 ne peut plus se battre !"<<std::endl;
        std::cout<<"La victoire revient au joueur 2 !"<<std::endl;
        setVictoireJoueur2(true);
    }
    if(m_Joueur2->getPV()<=0)
    {
        std::cout<<"Le joueur 2 ne peut plus se battre !"<<std::endl;
        std::cout<<"La victoire revient au joueur 1 !"<<std::endl;
        setVictoireJoueur1(true);
    }
    if(m_VictoireJoueur1||m_VictoireJoueur2) //implémentation d'un futur cas d'égalité
    {
        return true;
    }
    return false;
}


bool Combat::finDuCombat()
{
    if(mortDePersonnage()) //fonction redondante pour le moment mais possible implémentation de conditions supplémentaires de victoire
    {
        std::cout<<"C'est la fin du combat !"<<std::endl;
        return true;
    }
    return false;
}

void Combat::Attaque(Personnage* Attaquant, Personnage* Défenseur) //implémentation future d'un ulti d'où la redondance pour le moment
{
    Attaquant->attaquer(Défenseur);
}

void Combat::Combattre()
{
    srand(time(NULL));
    int QuiCommence=rand()%2+1;

    Personnage* Attaquant;
    Personnage* Défenseur;

    selectionPersonnages();
    std::cout<<std::endl;

    if(QuiCommence==1) //On choisit au hasard qui commence
    {
        setJoueur1Encours(true);
        std::cout<<"Le joueur 1 commence."<<std::endl;
    }
    else
    {
        setJoueur1Encours(false);
        std::cout<<"Le joueur 2 commence."<<std::endl;
    }

    do
    {
        do
        {
            if(getJoueur1Encours()) //initiation des rôles d'attaquant et de défenseur ainsi que de l'état des tours
            {
                Attaquant=m_Joueur1;
                Défenseur=m_Joueur2;
                setTourJoueur1Fini(false);
            }
            else
            {
                Attaquant=m_Joueur2;
                Défenseur=m_Joueur1;
                setTourJoueur2Fini(false);
            }

            MenuActions(Attaquant, Défenseur);
            //while (MenuActions(Attaquant, Défenseur)!=1 && MenuActions(Attaquant, Défenseur)!=3); //activation du menu jusqu'au cas d'attaque (1) ou d'abandon (3)

            if(m_Joueur1Encours) //changement de joueur est mise à jour de l'état de chacun
            {
                setJoueur1Encours(false);
                setTourJoueur1Fini(true);
                //std::cout<<"wsh1"<<std::endl;
            }
            else
            {
                setJoueur1Encours(true);
                setTourJoueur2Fini(true);
                //std::cout<<"wsh2"<<std::endl;
            }
        } 
        while ((!m_TourJoueur1Fini||!m_TourJoueur2Fini) && !mortDePersonnage()); //1
        PassageTourSuivant();
    } 
    while (!finDuCombat());
}

void Combat::MenuActions(Personnage* Attaquant, Personnage* Défenseur)
{
    int ChoixAction=0;

    //afficherCombat(Attaquant,Défenseur); //à remettre
    std::cout<<std::endl;
    std::cout<<"Choisissez l'action à effectuer: "<<std::endl;
    std::cout<<"1. Attaquer"<<std::endl;
    std::cout<<"2. Utiliser sa capacité"<<std::endl;
    std::cout<<"3. Abandonner le combat"<<std::endl;
    std::cout<<std::endl;

    do
    {
        std::cin>>ChoixAction;
        if(ChoixAction==1)
        {
            Attaque(Attaquant,Défenseur);
            std::cout<<std::endl;
        }
        if(ChoixAction==2)
        {
            utiliserCapacité(Attaquant,Défenseur);
            std::cout<<std::endl;
        }
        if(ChoixAction==3)
        {
            AbandonCombat(Attaquant);
            std::cout<<std::endl;
        }
    }
    while(ChoixAction==2);
}

void Combat::AbandonCombat(Personnage* Attaquant)
{
    Attaquant->setPV(-Attaquant->getPV());
    std::cout<<Attaquant->getNom()<<" déclare forfait !"<<std::endl;
}

void Combat::PassageTourSuivant()
{
    //std::cout<<"Tour joueur 1: "<<m_TourJoueur1Fini<<std::endl; //test
    //std::cout<<"Tour joueur 2: "<<m_TourJoueur2Fini<<std::endl; //test
    //std::cout<<std::endl; //test

    m_Joueur1->getCapacité()->setCooldown(-1);
    m_Joueur2->getCapacité()->setCooldown(-1);

    for(int i=0; i<m_Joueur1->getListeBonus()->size();i++)
    {
        m_Joueur1->getListeBonus()->at(i)->crémentationNombreTour(-1);
    }
    for(int i=0; i<m_Joueur1->getListeMalus()->size();i++)
    {
        m_Joueur1->getListeMalus()->at(i)->crémentationNombreTour(-1);
    }

    for(int i=0; i<m_Joueur2->getListeBonus()->size();i++)
    {
        m_Joueur2->getListeBonus()->at(i)->crémentationNombreTour(-1);
    }
    for(int i=0; i<m_Joueur2->getListeMalus()->size();i++)
    {
        m_Joueur2->getListeMalus()->at(i)->crémentationNombreTour(-1);
    }

    m_Joueur1->getCapacité()->réinitialisationEffet(m_Joueur2);
    m_Joueur2->getCapacité()->réinitialisationEffet(m_Joueur1);
}