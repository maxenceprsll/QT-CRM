#include <ostream>
#include <string>

#include "date.h"

/**
 * @brief The Interaction class
 */
class Interaction
{
private:
    Date date;
    std::string contenu;
public:
    Interaction();
    Interaction(const std::string & content);
    Interaction(const Date & d, const std::string & content);
    ~Interaction();

    Date getDate() const;
    std::string getContenu() const;

    void setDate(const Date & d);
    void setContenu(const std::string &);

    friend std::ostream& operator<<(std::ostream &, const Interaction &);
};
