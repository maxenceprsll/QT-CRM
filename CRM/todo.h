#include <ostream>
#include <string>

#include "date.h"

/**
 * @brief The Todo class
 */
class Todo
{
private:
    Date date;
    std::string contenu;
public:
    Todo();
    Todo(const std::string & c);
    Todo(const Date & d, const std::string & c);
    ~Todo();

    Date getDate() const;
    std::string getContenu() const;

    void setDate(const Date & d);
    void setContenu(const std::string &);

    friend std::ostream& operator<<(std::ostream &, const Todo &);
};
