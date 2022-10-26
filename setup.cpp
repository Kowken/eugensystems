#include "setup.h"

void menu()
{
    Personnage* ChevalierJoueur1 = créerChevalier("ChevalierJoueur1"); //création personnages
    Personnage* ChevalierJoueur2 = créerChevalier("ChevalierJoueur2");
    Personnage* OrcJoueur1 = créerOrc("OrcJoueur1");
    Personnage* OrcJoueur2 = créerOrc("OrcJoueur2");

    Combat o_Combat;

    o_Combat.getPoolPersonnageJoueur1()->push_back(ChevalierJoueur1); //remplissage des équipes
    o_Combat.getPoolPersonnageJoueur2()->push_back(ChevalierJoueur2);
    o_Combat.getPoolPersonnageJoueur1()->push_back(OrcJoueur1);
    o_Combat.getPoolPersonnageJoueur2()->push_back(OrcJoueur2);

    o_Combat.Combattre(); //opératon du combat
}