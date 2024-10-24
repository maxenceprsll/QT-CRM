#ifndef DATE_H
#define DATE_H

#include <ostream>

/**
 * @brief The Date class
 */
class Date
{
private:
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
public:
    Date();
    Date(unsigned int j, unsigned int m, unsigned int a);

    unsigned int getJour() const;
    unsigned int getMois() const;
    unsigned int getAnnee() const;

    void setJour(unsigned int);
    void setMois(unsigned int);
    void setAnnee(unsigned int);

    Date dateActuelle();

    friend std::ostream & operator<<(std::ostream & os, const Date & d);
};

#endif  // DATE_H
