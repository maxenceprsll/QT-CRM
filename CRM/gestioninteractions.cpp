#include "gestioninteractions.h"

/**
 * Constructeur de base
 * @brief GestionInteractions::GestionInteractions
 */
GestionInteractions::GestionInteractions()
{
}

/**
 * Destructeur de base
 * @brief GestionInteractions::~GestionInteractions
 */
GestionInteractions::~GestionInteractions()
{
}

/**
 * Ordonne l'ajout de l'interaction i au contact c
 * @brief GestionInteractions::addInteraction
 * @param i
 * @param c
 */
void GestionInteractions::addInteraction(const Interaction & i)
{
    listeInteractions.push_back(i);
}

/**
 * Get de la liste d'interaction du contact c
 * @brief GestionInteractions::getListe
 * @param c
 * @return la liste d'interactions
 */
std::list<Interaction> GestionInteractions::getListe() const
{
    return listeInteractions;
}

/**
 * @brief updateInteraction
 * @param i
 */
void updateInteraction(Interaction & i)
{
    //todo
}

/**
 * @brief deleteInteraction
 * @param i
 */
void deleteInteraction(Interaction & i)
{
    //todo
}

