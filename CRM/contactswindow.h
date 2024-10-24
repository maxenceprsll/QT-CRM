#ifndef CONTACTSWINDOW_H
#define CONTACTSWINDOW_H

#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QListView>
#include <QStyledItemDelegate>
#include <QtSql>
#include <QMessageBox>

#include "contactdialog.h"

/**
 * @brief La classe ContactsWindow représente la fenêtre principale pour la gestion des contacts.
 */
class ContactsWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe ContactsWindow.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    ContactsWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe ContactsWindow.
     */
    ~ContactsWindow();

private slots:
    /**
     * @brief Slot pour rechercher des contacts en fonction des critères saisis.
     */
    void rechercherContacts();

    /**
     * @brief Slot pour éditer le contact sélectionné.
     */
    void editerContact();

    /**
     * @brief Slot pour supprimer le contact sélectionné.
     */
    void supprimerContact();

    /**
     * @brief Slot pour ajouter un nouveau contact.
     */
    void ajouterContact();

private:
    QVBoxLayout *cLayout;
    QVBoxLayout *vl_contact;
    QHBoxLayout *hl_search;
    QFormLayout *form_rech;
    QLineEdit *nom;
    QLineEdit *prenom;
    QPushButton *researchBut;
    QListView *contactList;
    QHBoxLayout *hl_crud;
    QPushButton *remove;
    QPushButton *edit;
    QPushButton *add;

    QSqlQueryModel *contactsModel;
    QStyledItemDelegate *itemDelegate;
};

#endif // CONTACTSWINDOW_H
