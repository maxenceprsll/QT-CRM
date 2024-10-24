#ifndef TODOWINDOW_CPP
#define TODOWINDOW_CPP

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
 * @brief La classe TodosWindow représente la fenêtre des Todos dans l'application.
 * Elle gère l'affichage, la recherche, la modification et l'ajout de tâches.
 */
class TodosWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe TodosWindow.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    TodosWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe TodosWindow.
     */
    ~TodosWindow();

private slots:
    /**
     * @brief Recherche un contact en fonction des critères spécifiés.
     */
    void rechercherContact();

    /**
     * @brief Affiche les interactions associées au contact sélectionné.
     * @param index Index de l'élément sélectionné dans la liste des tâches.
     */
    void afficherInteractionsContact(const QModelIndex &index);

    /**
     * @brief Modifie la tâche sélectionnée.
     */
    void modifierTodo();

    /**
     * @brief Ajoute une nouvelle tâche pour le contact sélectionné.
     */
    void ajouterTodo();

private:
    QVBoxLayout *tLayout;
    QVBoxLayout *vl_todo;
    QHBoxLayout *hl_search;
    QFormLayout *form_rech;
    QLineEdit *nom;
    QLineEdit *prenom;
    QPushButton *researchBut;
    QLabel *contactLabel;
    QListView *todosList;
    QHBoxLayout *hl_crud;
    QPushButton *edit;
    QPushButton *add;

    QSqlQueryModel *todosModel;
    QStyledItemDelegate *itemDelegate;

    QModelIndex index;
};

#endif // TODOWINDOW_CPP
