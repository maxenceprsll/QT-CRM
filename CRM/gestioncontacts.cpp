#include "gestioncontacts.h"

/**
 * Constructeur de base
 * @brief GestionContacts::GestionContacts
 */
GestionContacts::GestionContacts()
{
}

/**
 * Destructeur de base
 * @brief GestionContacts::~GestionContacts
 */
GestionContacts::~GestionContacts()
{
    listeContacts.clear();
}

/**
 * Ajoute un contact à la liste des contacts
 * @brief GestionContacts::addContact
 * @param c
 */
void GestionContacts::addContact(const Contact & c)
{
    listeContacts.push_back(c);
}

/**
 * Getter de la liste des contacts
 * @brief GestionContacts::getListe
 * @return
 */
std::list<Contact> GestionContacts::getListe() const
{
    return listeContacts;
}

/**
 * Getter d'un contact par son numéro de téléphone
 * @brief GestionContacts::getContactByTelephone
 * @param t
 * @return Contact si trouvé
 */
Contact GestionContacts::getContactByTelephone(const std::string & t)
{
    //Todo
    return Contact();
}

/**
 * Retire le premier contact de nom n de la liste des contacts
 * @brief GestionContacts::removeFirstByName
 * @param n
 */
void GestionContacts::removeFirstByName(const std::string & n)
{
    auto it = listeContacts.begin();
    bool found=false;
    while ((it != listeContacts.end()) && (found == false)) {
        if ( it->getNom() == n )
        {
            found=true;
            it = listeContacts.erase(it);
        }
        else
            ++it;
    }
}

/**
 * Retire tous les contacts de nom n de la liste des contacts
 * @brief GestionContacts::removeByName
 * @param n
 */
void GestionContacts::removeByName(const std::string & n)
{
    for (auto it = listeContacts.begin(); it != listeContacts.end(); )
        if ( it->getNom() == n )
        {
            it = listeContacts.erase(it);
        }
        else
            ++it;
}
