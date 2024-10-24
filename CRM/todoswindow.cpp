#include "todoswindow.h"
#include "tododialog.h"

/**
 * @brief Constructeur de la classe TodosWindow.
 * @param parent Pointeur vers le widget parent (par défaut nullptr).
 */
TodosWindow::TodosWindow(QWidget *parent) : QWidget(parent)
{
    // Configuration des éléments de l'interface utilisateur
    tLayout = new QVBoxLayout();
    vl_todo = new QVBoxLayout();
    hl_search = new QHBoxLayout();

    form_rech = new QFormLayout;
    nom = new QLineEdit();
    prenom = new QLineEdit();
    form_rech->addRow(new QLabel("Rechercher un contact :"));
    form_rech->addRow(new QLabel("Nom"), nom);
    form_rech->addRow(new QLabel("Prénom"), prenom);

        researchBut = new QPushButton("Rechercher");

    hl_search->addLayout(form_rech);
    hl_search->addWidget(researchBut);

    contactLabel = new QLabel();
    todosList = new QListView();

    hl_crud = new QHBoxLayout();

    edit = new QPushButton("Modifier");
    add = new QPushButton("+");

    hl_crud->addWidget(edit);
    hl_crud->addWidget(add);

    vl_todo->addLayout(hl_search);
    vl_todo->addWidget(contactLabel);
    vl_todo->addWidget(todosList);
    vl_todo->addLayout(hl_crud);

    tLayout->addLayout(vl_todo);

    // Définition du layout de la fenêtre
    setLayout(tLayout);

    // Configuration du modèle pour la liste des tâches
    todosModel = new QSqlQueryModel(this);
    todosList->setModel(todosModel);

    // Configuration du delegate pour la liste des tâches
    itemDelegate = new QStyledItemDelegate(this);
    todosList->setItemDelegate(itemDelegate);

    // Activation des boutons Modifier et Ajouter
    edit->setDisabled(false);
    add->setDisabled(false);

    // Connexion des signaux aux slots
    connect(researchBut, &QPushButton::clicked, this, &TodosWindow::rechercherContact);
    connect(todosList, &QListView::doubleClicked, this, &TodosWindow::afficherInteractionsContact);
    connect(edit, &QPushButton::clicked, this, &TodosWindow::modifierTodo);
    connect(add, &QPushButton::clicked, this, &TodosWindow::ajouterTodo);
}

/**
 * @brief Slot appelé lors de la recherche de contacts.
 */
void TodosWindow::rechercherContact()
{
    // Désactivation des boutons Modifier et Ajouter
    edit->setDisabled(true);
    add->setDisabled(true);

    // Récupération des valeurs de recherche
    QString rechercheNom = nom->text();
    QString recherchePrenom = prenom->text();

    // Exécution de la requête pour rechercher le contact
    QSqlQuery query;
    query.prepare("SELECT * FROM Contact WHERE Nom LIKE :nom AND Prenom LIKE :prenom");
    query.bindValue(":nom", "%" + rechercheNom + "%");
    query.bindValue(":prenom", "%" + recherchePrenom + "%");

    if (query.exec())
    {
        qDebug() << "Requête exécutée";
        todosModel->setQuery(query);
        todosList->setModelColumn(1);
        contactLabel->setText("");
    }
    else
    {
        qDebug() << "Impossible d'exécuter la requête !";
        qDebug() << "Erreur SQL : " << query.lastError().text();
    }
}

/**
 * @brief Slot appelé lors de l'affichage des tâches associées à un contact.
 * @param index Index de l'élément sélectionné dans la liste des contacts.
 */
void TodosWindow::afficherInteractionsContact(const QModelIndex &index)
{
    if (index.isValid() && !add->isEnabled())
    {
        // Activation du bouton Modifier et désactivation du bouton Ajouter
        edit->setDisabled(false);
        add->setDisabled(true);

        // Récupération des informations du contact sélectionné
        QSqlRecord contactRecord = todosModel->record(index.row());
        QString nomContact = contactRecord.value("Nom").toString();
        QString prenomContact = contactRecord.value("Prenom").toString();

        // Exécution de la requête pour récupérer les tâches associées au contact
        QSqlQuery query;
        query.prepare("SELECT ID, Contenu, Date FROM Todo WHERE Contact = (SELECT ID FROM Contact WHERE Nom = :nom AND Prenom = :prenom) ORDER BY Date DESC");
        query.bindValue(":nom", nomContact);
        query.bindValue(":prenom", prenomContact);

        // Affichage du nom et prénom du contact
        contactLabel->setText(nomContact + " " + prenomContact);

        if (query.exec())
        {
            qDebug() << "Requête exécutée";
            todosModel->setQuery(query);
            todosList->setModelColumn(1);
        }
        else
        {
            qDebug() << "Impossible d'exécuter la requête !";
            qDebug() << "Erreur SQL : " << query.lastError().text();
        }
    }
}

/**
 * @brief Slot appelé lors de la modification d'une tâche.
 */
void TodosWindow::modifierTodo()
{
    // Récupération de l'index de l'élément sélectionné dans la liste des tâches
    index = todosList->currentIndex();

    if (index.isValid())
    {
        // Récupération de l'enregistrement de la tâche
        QSqlRecord todosRecord = todosModel->record(index.row());
        QString contenu = todosRecord.value("Contenu").toString();
        QString date = todosRecord.value("Date").toString();

        // Récupération de la liste des cases à cocher associées à la tâche
        QStringList todoList;

        QSqlQuery query;
        query.prepare("SELECT Contenu FROM Todo WHERE ID = :id");
        query.bindValue(":id", todosRecord.value("ID"));

        if (query.exec())
        {
            while (query.next())
            {
                todoList << query.value(0).toString();
            }
        }

        // Création de la fenêtre de dialogue pour la modification de la tâche
        todoDialog editDialog(contenu, date, todoList, this);

        if (editDialog.exec() == QDialog::Accepted)
        {
            // Mise à jour de la tâche dans la base de données
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE Todo SET Contenu = :contenu WHERE ID = :id");
            updateQuery.bindValue(":contenu", editDialog.getTodoText());
            updateQuery.bindValue(":id", todosRecord.value("ID"));

            qDebug() << todosRecord.value("ID");

            if (updateQuery.exec())
            {
                qDebug() << "Tâche mise à jour avec succès" << updateQuery.executedQuery();
                                                                  rechercherContact();
            }
            else
            {
                qDebug() << "Échec de la mise à jour de la tâche";
                qDebug() << "Erreur SQL : " << updateQuery.lastError().text();
            }
        }
        else
        {
            qDebug() << "Modification de la tâche annulée";
        }
    }
}

/**
 * @brief Slot appelé lors de l'ajout d'une nouvelle tâche.
 */
void TodosWindow::ajouterTodo()
{
    // Récupération de l'index de l'élément sélectionné dans la liste des contacts
    QModelIndex index = todosList->currentIndex();

    if (index.isValid())
    {
        // Récupération de l'enregistrement du contact associé à la tâche
        QSqlRecord contactRecord = todosModel->record(index.row());
        QString contactID = contactRecord.value("ID").toString();

        // Création de la fenêtre de dialogue pour l'ajout d'une nouvelle tâche
        todoDialog addDialog(this);

        if (addDialog.exec() == QDialog::Accepted)
        {
            // Ajout de la nouvelle tâche dans la base de données
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO Todo (Contact, Contenu, Date) VALUES (:contact, :contenu, DATE())");
            insertQuery.bindValue(":contact", contactID);
            insertQuery.bindValue(":contenu", addDialog.getTodoText());

            if (insertQuery.exec())
            {
                qDebug() << "Tâche ajoutée avec succès";
                rechercherContact();
            }
            else
            {
                qDebug() << "Échec de l'ajout de la tâche";
                qDebug() << "Erreur SQL : " << insertQuery.lastError().text();
            }
        }
        else
        {
            qDebug() << "Ajout annulé";
        }
    }
    else
    {
        qDebug() << "Aucune interaction sélectionnée pour ajouter une tâche";
    }
}

/**
 * @brief Destructeur de la classe TodosWindow.
 */
TodosWindow::~TodosWindow()
{
}
