#ifndef ORC_H_INCLUDED
#define ORC_H_INCLUDED

#include "../../head.h"

class Stun: public Capacité
{

    public:

    //================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

    Stun(Personnage* Utilisateur, std::string Nom);
    ~Stun();

    //================================= AUTRES ===============================================================

    void description();
    void effetImmédiat(Personnage* Attaquant);
    void réinitialisationEffet(Personnage* Attaquant);
    void effetParTour(Personnage* Attaquant);
    void processusRéinitialsationEffet(Personnage* Attaquant);

};

Personnage* créerOrc(std::string Nom);

#endif // ORC_H_INCLUDED