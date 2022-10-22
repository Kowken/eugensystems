#include "head.h"

//================================= CONSTRUCTEURS ET DESTRUCTEURS ==============================================================

CompteurEffet::CompteurEffet()
{

}

CompteurEffet::~CompteurEffet()
{

}

//================================= GETTERS ==============================================================

std::string CompteurEffet::getNomEffet()
{
    return m_NomEffet;
}

std::vector<int> CompteurEffet::getNombreTours()
{
    return m_NombreTours;
}

std::vector<int> CompteurEffet::getNombreFois()
{
 return m_NombreFois;
}

//================================= SETTERS ===============================================================

void CompteurEffet::setNomEffet(std::string DeltaNomEffet)
{
    m_NomEffet=DeltaNomEffet;
}

//================================= AUTRES ===============================================================

void CompteurEffet::crémentationNombreTour(int DeltaNombreTours)
{
    for(unsigned int i=0;i<m_NombreTours.size();i++)
    {
        m_NombreTours[i]+=DeltaNombreTours;
        m_NombreTours[i]=std::max(0,m_NombreTours[i]);
    }
}

void CompteurEffet::crémentationNombreFois(int DeltaNombreFois)
{
    for(unsigned int i=0;i<m_NombreTours.size();i++)
    {
        m_NombreFois[i]+=DeltaNombreFois;
        m_NombreFois[i]=std::max(0,m_NombreFois[i]);
    }
}