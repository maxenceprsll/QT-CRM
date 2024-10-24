#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <contactswindow.h>
#include <todoswindow.h>
#include <interactionswindow.h>

#include<QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include <QWidget>
#include <QTextEdit>
#include <QtSql>

/**
 * @brief La classe MainWindow représente la fenêtre principale de l'application.
 */
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe MainWindow.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    MainWindow(QWidget *parent = 0);

    /**
     * @brief Destructeur de la classe MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Affiche l'onglet des contacts.
     */
    void showContacts();

    /**
     * @brief Affiche l'onglet des todos.
     */
    void showTodos();

    /**
     * @brief Affiche l'onglet des interactions.
     */
    void showInteractions();

    /**
     * @brief Établit la connexion à la base de données.
     */
    void connexionBDD();

private:
    QTabWidget *tabWidget;
    QPushButton *contacts;
    QPushButton *todos;
    QPushButton *interact;

    ContactsWindow *contactsWindow;
    TodosWindow *todosWindow;
    InteractionsWindow *interactionsWindow;

    QSqlDatabase db;
};

#endif // MAINWINDOW_H
