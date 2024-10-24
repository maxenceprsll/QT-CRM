#include <iostream>
#include <ctime>

#include "date.h"

/**
 * Constructeur de base de date
 * @brief Date::Date
 */
Date::Date() {
    Date d = Date::dateActuelle();
    jour = d.getJour();
    mois = d.getMois();
    annee = d.getAnnee();
}

/**
 * Constructeur avec date précise
 * @brief Date::Date
 * @param j
 * @param m
 * @param a
 */
Date::Date(unsigned int j, unsigned int m, unsigned int a) : jour(j), mois(m), annee(a) {}

/**
 * Getter du jour
 * @brief Date::getJour
 * @return jour
 */
unsigned int Date::getJour() const { return jour; }

/**
 * Getter du mois
 * @brief Date::getMois
 * @return mois
 */
unsigned int Date::getMois() const { return mois; }

/**
 * Getter de l'année
 * @brief Date::getAnnee
 * @return annee
 */
unsigned int Date::getAnnee() const { return annee; }

/**
 * Setter du jour
 * @brief Date::setJour
 * @param j
 */
void Date::setJour(unsigned int j) { jour = j; }

/**
 * Setter du mois
 * @brief Date::setMois
 * @param m
 */
void Date::setMois(unsigned int m) { mois = m; }

/**
 * Setter de l'annee
 * @brief Date::setAnnee
 * @param a
 */
void Date::setAnnee(unsigned int a) { annee = a; }

/**
 * Renvoi un objet date avec la date du jour
 * @brief Date::dateActuelle
 * @return Date du jour
 */
Date Date::dateActuelle() {
    std::time_t now = std::time(nullptr);
    std::tm *dateNow = std::localtime(&now);

    unsigned int jour = dateNow->tm_mday;
    unsigned int mois = dateNow->tm_mon + 1;
    unsigned int annee = dateNow->tm_year + 1900;

    return Date(jour,mois,annee);
}

/**
 * Operateur d'affichage os
 * @brief operator <<
 * @param os
 * @param d
 * @return os
 */
std::ostream & operator<<(std::ostream & os, const Date & d) {
    os << d.getJour() << "/" << d.getMois() << "/" << d.getAnnee();
    return os;
}
