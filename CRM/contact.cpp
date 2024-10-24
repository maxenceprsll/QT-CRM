#include <iostream>

#include "contact.h"


/**
 * Constructeur complet
 * @brief Contact::Contact
 * @param prenom
 * @param nom
 * @param entreprise
 * @param mail
 * @param telephone
 * @param photo
 */
Contact::Contact(const std::string & prenom, const std::string & nom, const std::string & entreprise, const std::string & mail, const std::string & telephone, const std::string & photo) :
    nom(nom), prenom(prenom), entreprise(entreprise), mail(mail), telephone(telephone), photo(photo), creation(Date())
{
}

Contact::Contact()
{

}

/**
 * Setter de la date de création de la fiche
 * @brief Contact::setCreation
 * @param la date de creation
 */
void Contact::setCreation(const Date & creation)
{
    this->creation = creation;
}

/**
 * Getter de la date de création de la fiche
 * @brief Contact::getCreation
 * @return la date de creation
 */
Date Contact::getCreation() const
{
    return creation;
}

/**
 * Setter du prenom du contact
 * @brief Contact::setPrenom
 * @param le prenom
 */
void Contact::setPrenom(const std::string & prenom)
{
    this->prenom = prenom;
}

/**
 * Getterd du prenom du contact
 * @brief Contact::getPrenom
 * @return le prenom
 */
std::string Contact::getPrenom() const
{
    return prenom;
}

/**
 * Setter du nom du contact
 * @brief Contact::setNom
 * @param le nom
 */
void Contact::setNom(const std::string & nom)
{
    this->nom = nom;
}

/**
 * Getterd du nom du contact
 * @brief Contact::getNom
 * @return le nom
 */
std::string Contact::getNom() const
{
    return nom;
}

/**
 * Setter de l'entreprise du contact
 * @brief Contact::setEntreprise
 * @param l'entreprise
 */
void Contact::setEntreprise(const std::string & entreprise)
{
    this->entreprise = entreprise;
}

/**
 * Getterd de l'entreprise du contact
 * @brief Contact::getEntreprise
 * @return l'entreprise
 */
std::string Contact::getEntreprise() const
{
    return entreprise;
}

/**
 * Setter du mail du contact
 * @brief Contact::setMail
 * @param le mail
 */
void Contact::setMail(const std::string & mail)
{
    this->mail = mail;
}

/**
 * Getter du mail du contact
 * @brief Contact::getMail
 * @return le mail
 */
std::string Contact::getMail() const
{
    return mail;
}

/**
 * Setter du téléphone du contact
 * @brief Contact::setTelephone
 * @param le string du numero de telephone
 */
void Contact::setTelephone(const std::string & telephone)
{
    this->telephone = telephone;
}

/**
 * Getter du telephone du contact
 * @brief Contact::getTelephone
 * @return le string du numero de telephone
 */
std::string Contact::getTelephone() const
{
    return telephone;
}

/**
 * Setter de la photo du contact
 * @brief Contact::setPhoto
 * @param l'uri de la photo
 */
void Contact::setPhoto(const std::string & photo)
{
    this->photo = photo;
}

/**
 * Getter du l'uri de la photo du contact
 * @brief Contact::getPhoto
 * @return
 */
std::string Contact::getPhoto() const
{
    return photo;
}

/**
 * Permet d'ajouter une interaction à un contact
 * @brief Contact::addInteraction
 * @param une interaction
 */
void Contact::addInteraction(const Interaction & i)
{
    gi.addInteraction(i);
}

/**
 * Getter de la liste d'interaction du contact
 * @brief Contact::getListe
 * @return la liste des interactions
 */
std::list<Interaction> Contact::getListInteraction()
{
    return gi.getListe();
}

/**
 * Opérateur d'affichage os
 * @brief operator <<
 * @param os
 * @param c
 * @return os
 */
std::ostream & operator<<(std::ostream & os, const Contact & c)
{
    os << "[" << c.getPrenom() << "," << c.getNom() << "," << c.getEntreprise() << "," << c.getMail() << "," << c.getTelephone() << "," << c.getCreation() << "]";
        return os;
}
