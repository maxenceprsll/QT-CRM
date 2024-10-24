#include "mainwindow.h"

/**
 * @brief Constructeur de la classe MainWindow.
 * @param parent Pointeur vers le widget parent (par défaut nullptr).
 */
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    // Création des fenêtres pour chaque onglet
    contactsWindow = new ContactsWindow;
    todosWindow = new TodosWindow;
    interactionsWindow = new InteractionsWindow;

    // Création du layout principal
    QVBoxLayout *layout = new QVBoxLayout;

    // Création de l'onglet principal et ajout des onglets spécifiques
    tabWidget = new QTabWidget;
    tabWidget->addTab(nullptr, "Main"); // Onglet principal
    tabWidget->addTab(contactsWindow, "Contacts");
    tabWidget->addTab(todosWindow, "Todos");
    tabWidget->addTab(interactionsWindow, "Interactions");

    setMinimumSize(400, 300);

    // Ajout du QTabWidget au layout
    layout->addWidget(tabWidget);

    // Définition du layout principal de la fenêtre
    this->setLayout(layout);

    // Connexion à la base de données
    connexionBDD();
}

/**
 * @brief Destructeur de la classe MainWindow.
 * Ferme la connexion à la base de données lors de la destruction de la fenêtre.
 */
MainWindow::~MainWindow()
{
    db.close();
}

/**
 * @brief Affiche l'onglet des contacts.
 */
void MainWindow::showContacts()
{
    tabWidget->setCurrentWidget(contactsWindow);
}

/**
 * @brief Affiche l'onglet des todos.
 */
void MainWindow::showTodos()
{
    tabWidget->setCurrentWidget(todosWindow);
}

/**
 * @brief Affiche l'onglet des interactions.
 */
void MainWindow::showInteractions()
{
    tabWidget->setCurrentWidget(interactionsWindow);
}

/**
 * @brief Établit la connexion à la base de données SQLite.
 * Configurations de la connexion et tentative d'ouverture de la base de données.
 */
void MainWindow::connexionBDD()
{
    // Configuration de la connexion à la base de données SQLite
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/maxence/Documents/Scolarité/L3/S5/CDAA/Projet/Sources/CRM/CRM.sqlite");

        // Tentative d'ouverture de la base de données
        if (!db.open())
    {
        qDebug() << "Pas de connexion à la BDD !";
    }
    else
    {
        qDebug() << "Connexion réussie à la BDD !";
    }
}
