#ifndef LIENCONTACTINTERACTION_H
#define LIENCONTACTINTERACTION_H

#include "interaction.h"
#include "todo.h"

/**
 * @brief The LienInteractionTodo class
 */
class LienInteractionTodo
{
public:
    LienInteractionTodo();
    LienInteractionTodo(Interaction * i,Todo * t);
    Interaction * interaction;
    Todo * todo;
};

#endif // LIENCONTACTINTERACTION_H
