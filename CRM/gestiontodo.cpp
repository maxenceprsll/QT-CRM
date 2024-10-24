#include "gestiontodo.h"

/**
 * Constructeur de base
 * @brief GestionTodo::GestionTodo
 */
GestionTodo::GestionTodo()
{
}

/**
 * Destructeur de base
 * @brief GestionInteractions::~GestionInteractions
 */
GestionTodo::~GestionTodo()
{
}

/**
 * Ordonne l'ajout du todo t
 * @brief GestionTodo::addtodo
 * @param t
 */
void GestionTodo::addTodo(const Todo & t)
{
    listeTodo.push_back(t);
}

/**
 * Get de la liste des todo
 * @brief GestionTodo::getListe
 * @return la liste des todo
 */
std::list<Todo> GestionTodo::getListe() const
{
    return listeTodo;
}

/**
 * @brief updateTodo
 * @param t
 */
void updateTodo(Todo & t)
{
    //todo
}

/**
 * @brief deleteTodo
 * @param t
 */
void deleteTodo(Todo & t)
{
    //todo
}

