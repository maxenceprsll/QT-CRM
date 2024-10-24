#ifndef INTERACTIONSWINDOW_H
#define INTERACTIONSWINDOW_H

#include <QWidget>
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QListView>
#include <QtSql>
#include <QStyledItemDelegate>
#include <QDebug>

/**
 * @brief La classe InteractionsWindow représente la fenêtre des interactions.
 */
class InteractionsWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe InteractionsWindow.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    InteractionsWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe InteractionsWindow.
     */
    ~InteractionsWindow();

private slots:
    /**
     * @brief Recherche un contact en fonction des critères spécifiés.
     */
    void rechercherContact();

    /**
     * @brief Affiche les interactions pour le contact sélectionné.
     * @param index Index de l'élément sélectionné dans la liste des contacts.
     */
    void afficherInteractionsContact(const QModelIndex &index);

    /**
     * @brief Modifie l'interaction sélectionnée.
     */
    void modifierInteraction();

    /**
     * @brief Ajoute une nouvelle interaction pour le contact sélectionné.
     */
    void ajouterInteraction();

private:
    QVBoxLayout *iLayout;
    QVBoxLayout *vl_interactions;
    QHBoxLayout *hl_search;
    QFormLayout *form_rech;

    QLineEdit *nom;
    QLineEdit *prenom;
    QPushButton *researchBut;

    QLabel *contactLabel;
    QListView *interactionsList;

    QHBoxLayout *hl_crud;
    QPushButton *edit;
    QPushButton *add;

    QSqlQueryModel *interactionsModel;
    QStyledItemDelegate *itemDelegate;

    QModelIndex index;
};

#endif // INTERACTIONSWINDOW_H
