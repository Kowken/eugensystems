#ifndef CHEVALIER_H_INCLUDED
#define CHEVALIER_H_INCLUDED

#include "../../head.h"

class Charge: public Capacité
{

    public:

    //================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

    Charge(Personnage* Utilisateur);
    ~Charge();

    //================================= AUTRES ===============================================================

    void description();
    void effetImmédiat(Personnage* Attaquant);
    void réinitialisationEffet(Personnage* Attaquant);
    void effetParTour(Personnage* Attaquant);
    void processusRéinitialsationEffet(Personnage* Attaquant);

};

Personnage* créerChevalier(std::string Nom);

#endif // CHEVALIER_H_INCLUDED