#ifndef PERSONNE_H
#define PERSONNE_H

#include <ostream>
#include <string>

/**
 * @brief The Personne class
 */
class Personne
{
private:
    std::string nom;
    std::string prenom;
public:
    Personne();
    Personne(const std::string & p,const std::string & n);
    std::string getNom() const;
    std::string getPrenom() const;
    void setNom(const std::string & n);
    void setPrenom(const std::string & p);
    friend std::ostream & operator<<(std::ostream & os, const Personne & p);
};

#endif // PERSONNE_H
