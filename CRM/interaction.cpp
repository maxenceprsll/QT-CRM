#include <ctime>

#include "interaction.h"

/**
 * Constructeur de base
 * @brief Interaction::Interaction
 */
Interaction::Interaction()
{
    setDate(Date());
}

/**
 * Constructeur avec un contenu donné
 * @brief Interaction::Interaction
 * @param c
 */
Interaction::Interaction(const std::string & c)
{
    this->setDate(Date());
    this->setContenu(c);
}

/**
 * Constructeur avec une date et un contenu donnés
 * @brief Interaction::Interaction
 * @param d
 * @param c
 */
Interaction::Interaction(const Date & d, const std::string & c)
{
    this->setDate(d);
    this->setContenu(c);
}

/**
 * Destructeur de base
 * @brief Interaction::~Interaction
 */
Interaction::~Interaction()
{
}

/**
 * Getter de la date de l'interaction
 * @brief Interaction::getDate
 * @return date
 */
Date Interaction::getDate() const
{
    return date;
}

/**
 * Getter du contenu de l'interaction
 * @brief Interaction::getContenu
 * @return contenu
 */
std::string Interaction::getContenu() const
{
    return contenu;
}

/**
 * Setter de la date de l'interaction
 * @brief Interaction::setDate
 * @param d
 */
void Interaction::setDate(const Date & d)
{
    date = d;
}

/**
 * Setter du contenu de l'interaction
 * @brief Interaction::setContenu
 * @param c
 */
void Interaction::setContenu(const std::string & c)
{
    contenu = c;
}

/**
 * Operateur d'affichage os
 * @brief operator <<
 * @param os
 * @param i
 * @return os
 */
std::ostream & operator<<(std::ostream & os, const Interaction & i)
{
    Date d = i.getDate();
    os << d.getJour() << "/" << d.getMois() << "/" << d.getAnnee() << "//" << i.getContenu();
    return os;
}
