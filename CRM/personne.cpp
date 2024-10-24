#include <ostream>

#include "personne.h"

/**
 * Classe Abandonnée, non utile après réflexion
 */

/**
 * Constructeur de base
 * @brief Personne::Personne
 */
Personne::Personne()
{
}

/**
 * Constructeur avec prenom et nom
 * @brief Personne::Personne
 * @param p
 * @param n
 */
Personne::Personne(const std::string & p, const std::string & n)
{
    this->setPrenom(p);
    this->setNom(n);
}

/**
 * Getter du nom
 * @brief Personne::getNom
 * @return nom
 */
std::string Personne::getNom() const
{
    return nom;
}

/**
 * Getter du prenom
 * @brief Personne::getPrenom
 * @return prenom
 */
std::string Personne::getPrenom() const
{
    return prenom;
}

/**
 * Setter du nom
 * @brief Personne::setNom
 * @param s
 */
void Personne::setNom(const std::string & s)
{
    nom = s;
}

/**
 * Setter du prenom
 * @brief Personne::setPrenom
 * @param s
 */
void Personne::setPrenom(const std::string & s)
{
    prenom = s;
}

/**
 * Operateur d'affichage os
 * @brief operator <<
 * @param os
 * @param p
 * @return os
 */
std::ostream & operator<<(std::ostream & os, const Personne & p)
{
    os << "[" << p.getPrenom() << "," << p.getNom() << "]";
    return os;
}
