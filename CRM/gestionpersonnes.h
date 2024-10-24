#ifndef GESTIONPERSONNES_H
#define GESTIONPERSONNES_H

#include <list>
#include "personne.h"

/**
 * @brief The GestionPersonnes class
 */
class GestionPersonnes
{
private:
    std::list<Personne> listePersonnes;
public:
    GestionPersonnes();
    ~GestionPersonnes();

    inline unsigned getSize() { return listePersonnes.size(); }
    std::list<Personne> getListe() const;

    void addPersonne(const Personne & p);
    void editFirstByName(const std::string & n, const std::string newP, const std::string newN);

    void removeFirstByName(const std::string & n);
    void removeByName(const std::string & n);
};

#endif // GESTIONPERSONNES_H
