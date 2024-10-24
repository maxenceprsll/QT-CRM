#ifndef GESTIONCONTACTS_H
#define GESTIONCONTACTS_H

#include <list>
#include "contact.h"

/**
 * @brief The GestionContacts class
 */
class GestionContacts
{
private:
    std::list<Contact> listeContacts;
public:
    GestionContacts();
    ~GestionContacts();

    inline unsigned getSize() { return listeContacts.size(); }
    std::list<Contact> getListe() const;

    Contact getContactByTelephone(const std::string & t);

    void addContact(const Contact & c);

    void removeFirstByName(const std::string & n);
    void removeByName(const std::string & n);
};

#endif // GESTIONCONTACTS_H
