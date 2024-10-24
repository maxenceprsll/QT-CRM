#include "lieninteractiontodo.h"

/**
 * Constructeur de base
 * @brief LienInteractionTodo::LienInteractionTodo
 */
LienInteractionTodo::LienInteractionTodo()
{
}

/**
 * Constructeur avec interaction et todo
 * @brief LienInteractionTodo::LienInteractionTodo
 * @param i
 * @param t
 */
LienInteractionTodo::LienInteractionTodo(Interaction *i, Todo *t) : interaction(i), todo(t)
{
}
