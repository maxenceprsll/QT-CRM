#ifndef CONTACT_H
#define CONTACT_H

#include <list>

#include "date.h"
#include "gestioninteractions.h"

/**
 * @brief The Contact class
 */
class Contact {
private:
    std::string nom;
    std::string prenom;
    std::string entreprise;
    std::string mail;
    std::string telephone;
    std::string photo;
    Date creation;
    GestionInteractions gi;
public:
    Contact();
    Contact(const std::string & prenom, const std::string & nom, const std::string & entreprise, const std::string & mail, const std::string & telephone, const std::string & photo);

    //inline ~Contact(){listeInteractions.clear();}; //Gestionnaire interaction plutôt

    void setPrenom(const std::string & prenom);
    void setNom(const std::string & nom);
    void setEntreprise(const std::string & entreprise);
    void setMail(const std::string & mail);
    void setTelephone(const std::string & telephone);
    void setPhoto(const std::string & photo);
    void setCreation(const Date & creation);

    std::string getPrenom() const;
    std::string getNom() const;
    std::string getEntreprise() const;
    std::string getMail() const;
    std::string getTelephone() const;
    std::string getPhoto() const;
    Date getCreation() const;


    void addInteraction(const Interaction & i);
    std::list<Interaction> getListInteraction();

    friend std::ostream & operator<<(std::ostream & os, const Contact & c);
};

#endif // CONTACT_H
