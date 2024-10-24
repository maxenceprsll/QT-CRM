#ifndef GESTIONTODO_H
#define GESTIONTODO_H

#include <list>
#include "todo.h"

/**
 * @brief The GestionInteractions class
 */
class GestionTodo
{
private:
    std::list<Todo> listeTodo;
public:
    GestionTodo();
    ~GestionTodo();

    inline unsigned getSize() { return listeTodo.size(); }
    std::list<Todo> getListe() const;

    void addTodo(const Todo & i);

    void updateTodo(Todo & i);
    void deleteTodo(Todo & i);

};

#endif // GESTIONTODO_H
