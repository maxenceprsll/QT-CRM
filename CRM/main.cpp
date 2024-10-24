#include <QApplication>
#include <iostream>
#include <QDebug>

#include "mainwindow.h"

#include "gestioncontacts.h"

/**
 * Fonction principale du programme.
 * @brief main
 * @param argc Le nombre d'arguments de la ligne de commande.
 * @param argv Un tableau d'arguments de la ligne de commande.
 * @return Le code de sortie de l'application.
 */
int main(int argc, char *argv[])
{
    /* OBSOLETE */
    // Test création de contact
    Contact c("Max","Persello","MP EI","maxence_persello@etu.u-bourgogne.fr","0606060606","max.jpg");

    // Test ajout contact au gestionnaire de contacts
    GestionContacts gc;
    gc.addContact(Contact("Paul","Paillard","PP","paul.paillard@edu.univ-fcomte.fr","0808080808","paul.jpg"));
    gc.addContact(Contact("Rayan","Lax","RL","rayan.Lax@edu.univ-fcomte.fr","0808070807","rayan.jpg"));
    /* OBSOLETE */

    // Test affichage de l'application
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("/Users/maxence/Documents/Scolarité/L3/S5/CDAA/Projet/Sources/CRM/icon.ico"));

        MainWindow w;

    w.setWindowTitle("C R M");
    w.show();

    return a.exec();
}
