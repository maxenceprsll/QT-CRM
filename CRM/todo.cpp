#include <ctime>

#include "todo.h"

/**
 * Constructeur de base
 * @brief Todo::Todo
 */
Todo::Todo()
{
    setDate(Date());
}

/**
 * Constructeur avec contenu
 * @brief Todo::Todo
 * @param c
 */
Todo::Todo(const std::string & c)
{
    this->setDate(Date());
    this->setContenu(c);
}

/**
 * Constructeur avec date et contenu
 * @brief Todo::Todo
 * @param d
 * @param c
 */
Todo::Todo(const Date & d, const std::string & c)
{
    this->setDate(d);
    this->setContenu(c);
}

/**
 * Destructeur de base
 * @brief Todo::~Todo
 */
Todo::~Todo()
{
}

/**
 * Getter de la date
 * @brief Todo::getDate
 * @return date
 */
Date Todo::getDate() const
{
    return date;
}

/**
 * Getter du contenu
 * @brief Todo::getContenu
 * @return contenu
 */
std::string Todo::getContenu() const
{
    return contenu;
}

/**
 * Setter de la date
 * @brief Todo::setDate
 * @param d
 */
void Todo::setDate(const Date & d)
{
    date = d;
}

/**
 * Setter du contenu
 * @brief Todo::setContenu
 * @param c
 */
void Todo::setContenu(const std::string & c)
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
std::ostream & operator<<(std::ostream & os, const Todo & i)
{
    Date d = i.getDate();
    os << d.getJour() << "/" << d.getMois() << "/" << d.getAnnee() << "//" << i.getContenu();
    return os;
}
