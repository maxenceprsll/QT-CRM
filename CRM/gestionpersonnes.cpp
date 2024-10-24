#include "gestionpersonnes.h"

/**
 * Constructeur de base
 * @brief GestionPersonnes::GestionPersonnes
 */
GestionPersonnes::GestionPersonnes()
{
}

/**
 * Destructeur de base
 * @brief GestionPersonnes::~GestionPersonnes
 */
GestionPersonnes::~GestionPersonnes()
{
    listePersonnes.clear();
}

/**
 * Ajoute la personne p à la liste de personnes
 * @brief GestionPersonnes::addPersonne
 * @param p
 */
void GestionPersonnes::addPersonne(const Personne & p)
{
    listePersonnes.push_back(p);
}

/**
 * change de prenom et le nom de la premiere personne au nom n de la liste de personnes
 * @brief GestionPersonnes::editFirstByName
 * @param n
 * @param newP
 * @param newN
 */
void GestionPersonnes::editFirstByName(const std::string & n, const std::string newP, const std::string newN)
{
    auto it = listePersonnes.begin();
    bool found=false;
    while ((it != listePersonnes.end()) && (found == false)) {
        if ( it->getNom() == n )
        {
            found=true;
            it->setPrenom(newP);
            it->setNom(newN);
        }
        else
            ++it;
    }
}

/**
 * Getter de la liste de personnes
 * @brief GestionPersonnes::getListe
 * @return listePersonnes
 */
std::list<Personne> GestionPersonnes::getListe() const
{
    return listePersonnes;
}

/**
 * Retire la premiere personne de nom n de la liste de personnes
 * @brief GestionPersonnes::removeFirstByName
 * @param n
 */
void GestionPersonnes::removeFirstByName(const std::string & n)
{
    auto it = listePersonnes.begin();
    bool found=false;
    while ((it != listePersonnes.end()) && (found == false)) {
        if ( it->getNom() == n )
        {
            found=true;
            it = listePersonnes.erase(it);
        }
        else
            ++it;
    }
}

/**
 * Retire toutes les peronnes de nom n de la liste de personnes
 * @brief GestionPersonnes::removeByName
 * @param n
 */
void GestionPersonnes::removeByName(const std::string & n)
{
    for (auto it = listePersonnes.begin(); it != listePersonnes.end(); )
        if ( it->getNom() == n )
        {
            it = listePersonnes.erase(it);
        }
        else
            ++it;
}
