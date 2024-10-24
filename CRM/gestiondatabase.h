#ifndef GESTIONDATABASE_H
#define GESTIONDATABASE_H

#include <QtSql>

class GestionDatabase
{
private:
    QSqlDatabase db;
public:
    GestionDatabase();
    ~GestionDatabase();
    void connexionBDD();
    void select();
};

#endif // GESTIONDATABASE_H
