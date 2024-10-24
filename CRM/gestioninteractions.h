#ifndef GESTIONINTERACTIONS_H
#define GESTIONINTERACTIONS_H

#include <list>
#include "interaction.h"

/**
 * @brief The GestionInteractions class
 */
class GestionInteractions
{
private:
    std::list<Interaction> listeInteractions;
public:
    GestionInteractions();
    ~GestionInteractions();

    inline unsigned getSize() { return listeInteractions.size(); }
    std::list<Interaction> getListe() const;

    void addInteraction(const Interaction & i);

    void updateInteraction(Interaction & i);
    void deleteInteraction(Interaction & i);

};

#endif // GESTIONINTERACTIONS_H
