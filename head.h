#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include<iostream>
#include <string>
#include <map>
#include <vector>
#include <time.h>
#include <queue>
#include <algorithm>

//================================= DECLARATION ==========================================================

class Personnage;
class CompteurEffet;
class Capacité;
class Combat;

//================================= PERSONNAGE ==============================================================

/*Caractéristiques du chevalier :
- Il dispose de 20 points de vie et d'un bouclier de 50 points.
- Il dispose d'une épée lui permettant de faire 5 points de dégâts par tour.
- Il dispose d'une capacité "charge" lui permettant de faire le double de dégâts ce tour-ci. Cette capacité ne peut être utilisée que tous les 3 tours de jeu.
Elle a 60% de chance de réussir. Si elle ne réussit pas, il faudra attendre les 3 tours mentionnés ci-dessus pour la tenter de nouveau.
- Les dégâts pris par le chevalier sont d'abord infligés au bouclier et lorsque le bouclier n'a plus de points, l'unité perd des points de vie.
*/

/*Caractéristiques de l'orc
- L'orc dispose de 60 points de vie mais n'a pas de bouclier.
- Il dispose d'une hache lui permettant de faire 8 points de dégâts par tour.
- Il dispose d'une capacité "stun" lui permettant d'étourdir l'ennemi pendant un tour. Un ennemi étourdi ne pourra pas faire de dégât ce tour-ci.
Cette capacité ne peut être utilisée que tous les 5 tours de jeu. Elle a 20% de chance de réussir.
Si elle ne réussit pas, il faudra attendre les 5 tours mentionnés ci-dessus pour la tenter de nouveau.*/

class Personnage
{
    private:
        std::string m_Nom;
        int m_PV;
        int m_PVMax;
        int m_AttaqueBasique;
        int m_CoeffAttaque=1;
        int m_PVBouclier;
        Capacité* m_Capacité;
        bool m_Vivant=true;
        bool m_Stun=false;
        std::vector<CompteurEffet*> m_ListeBonus;
        std::vector<CompteurEffet*> m_ListeMalus;

    public:

        //================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================
        Personnage(std::string Nom, int PVMax, int AttaqueBasique, int PVBouclier);
        ~Personnage();

        //================================= GETTERS ==============================================================
        std::string getNom();
        int getPV();
        int getPVMax();
        int getAttaqueBasique();
        int getCoeffAttaque();
        int getPVBouclier();
        Capacité* getCapacité();
        bool getVivant();
        bool getStun();
        std::vector<CompteurEffet*>* getListeBonus();
        std::vector<CompteurEffet*>* getListeMalus();

        //================================= SETTERS ===============================================================
        void setNom(std::string deltaNom);
        void setPV(int deltaPV);
        void setPVMax(int deltaPVMax);
        void setAttaqueBasique(double deltaAttaqueBasique);
        void setCoeffAttaque(double deltaCoeffAttaque);
        int setPVBouclier(int detlaPVBouclier);
        void setCapacité(Capacité* deltaCapacité);
        void setVivant(bool deltaVivant);
        void setStun(bool deltaStun);
        void setListeBonus();
        void setListeMalus();

        //================================= AUTRES ==============================================================
        void afficherStatut();
        void attaquer(Personnage* Défenseur);
        void calculDéfense(Personnage* Attaquant);
        void utiliserCapacité(Personnage* Attaquant);
        void problemeStatut();
        int attaqueTotale();
};

//================================= COMPTEUR EFFET ==============================================================

class CompteurEffet
{
    private:

    std::string m_NomEffet;
    std::vector<int> m_NombreTours;
    std::vector<int> m_NombreFois;

    public:

    //================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

    CompteurEffet(std::string Nom);
    ~CompteurEffet();

    //================================= GETTERS ==============================================================

    std::string getNomEffet();
    std::vector<int>* getNombreTours();
    std::vector<int>* getNombreFois();

    //================================= SETTERS ===============================================================

    void setNomEffet(std::string DeltaNomEffet);
    void crémentationNombreTour(int DeltaNombreTours);
    void crémentationNombreFois(int DeltaNombreFois);

    //================================= AUTRES ===============================================================


};

//================================= CAPACITÉ ==============================================================

class Capacité
{
    protected:

    std::string m_Nom;
    int m_Cooldown=0;
    Personnage* m_Utilisateur;

    public:

    //================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

    Capacité(Personnage* Utilisateur);
    virtual ~Capacité();

    //================================= GETTERS ==============================================================

    std::string getNom();
    int getCooldown();
    Personnage* getUtilisateur();

    //================================= SETTERS ===============================================================

    void setNom(std::string deltaNom);
    void setCooldown(int deltaCooldown);
    void setUtilisateur(Personnage* deltaUtilisateur);

    //================================= AUTRES ===============================================================

    virtual void description();
    virtual void effetImmédiat(Personnage* Attaquant);
    virtual void réinitialisationEffet(Personnage* Attaquant);
    virtual void effetParTour(Personnage* Attaquant);
    virtual void processusRéinitialsationEffet(Personnage* Attaquant);

};

class Combat
{
    private:

    int m_NombreDeTours=0;
    std::vector<Personnage*> m_PoolPersonnageJoueur1;
    std::vector<Personnage*> m_PoolPersonnageJoueur2;
    Personnage* m_Joueur1;
    Personnage* m_Joueur2;
    bool m_TourJoueur1Fini=false;
    bool m_TourJoueur2Fini=false;
    bool m_Joueur1Encours = true; //sert à savoir qui joue en ce moment
    bool m_VictoireJoueur1=false;
    bool m_VictoireJoueur2=false;

    public:

    //================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

    Combat();
    ~Combat();

    //================================= GETTERS ==============================================================

    int getNombreDeTours();
    std::vector<Personnage*>* getPoolPersonnageJoueur1();
    std::vector<Personnage*>* getPoolPersonnageJoueur2();
    Personnage* getJoueur1();
    Personnage* getJoueur2();
    bool getTourJoueur1Fini();
    bool getTourJoueur2Fini();
    bool getJoueur1Encours();
    bool getVictoireJoueur1();
    bool getVictoireJoueur2();

    //================================= SETTERS ===============================================================

    void setNombreDeTours(int DeltaNombreDeTours);
    void setPoolPersonnageJoueur1();
    void setPoolPersonnageJoueur2();
    void setJoueur1(Personnage* DeltaJoueur1);
    void setJoueur2(Personnage* DeltaJoueur2);
    void setTourJoueur1Fini(bool DeltaTourJoueur1Fini);
    void setTourJoueur2Fini(bool DeltaTourJoueur2Fini);
    void setJoueur1Encours(bool DeltaJoueur1Encours);
    void setVictoireJoueur1(bool DeltaVictoireJoueur1);
    void setVictoireJoueur2(bool DeltaVictoireJoueur2);

    //================================= AUTRES ===============================================================

    void afficherCombat(Personnage* Attaquant, Personnage* Défenseur);
    void selectionPersonnages();
    void utiliserCapacité(Personnage* Attaquant, Personnage* Défenseur);
    bool mortDePersonnage();
    bool finDuCombat();
    void Attaque(Personnage* Attaquant, Personnage* Défenseur);
    void Combattre();
    void MenuActions(Personnage* Attaquant, Personnage* Défenseur);
    void AbandonCombat(Personnage* Attaquant);
    void PassageTourSuivant2();
    void PassageTourSuivant(Personnage* Attaquant, Personnage* Défenseur);
};

#endif // HEAD_H_INCLUDED