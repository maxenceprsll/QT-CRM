#include "interactionswindow.h"
#include "interactiondialog.h"

/**
 * Constructeur de la classe InteractionsWindow.
 * @brief InteractionsWindow::InteractionsWindow
 * @param parent Le widget parent.
 */
InteractionsWindow::InteractionsWindow(QWidget *parent) : QWidget(parent)
{
    iLayout = new QVBoxLayout();
    vl_interactions = new QVBoxLayout();
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

    interactionsList = new QListView();

    hl_crud = new QHBoxLayout();

    edit = new QPushButton("Modifier");
    add = new QPushButton("+");

    hl_crud->addWidget(edit);
    hl_crud->addWidget(add);

    vl_interactions->addLayout(hl_search);
    vl_interactions->addWidget(contactLabel);
    vl_interactions->addWidget(interactionsList);
    vl_interactions->addLayout(hl_crud);

    iLayout->addLayout(vl_interactions);

    setLayout(iLayout);

    //*****//

    interactionsModel = new QSqlQueryModel(this);
    interactionsList->setModel(interactionsModel);

    itemDelegate = new QStyledItemDelegate(this);
    interactionsList->setItemDelegate(itemDelegate);

    //*****//

    edit->setDisabled(false);
    add->setDisabled(false);

    //*****//

    connect(researchBut, &QPushButton::clicked, this, &InteractionsWindow::rechercherContact);
    connect(interactionsList, &QListView::doubleClicked, this, &InteractionsWindow::afficherInteractionsContact);
    connect(edit, &QPushButton::clicked, this, &InteractionsWindow::modifierInteraction);
    connect(add, &QPushButton::clicked, this, &InteractionsWindow::ajouterInteraction);
}

/**
 * Slot pour rechercher les contacts en fonction des critères de recherche.
 * @brief InteractionsWindow::rechercherContact
 */
void InteractionsWindow::rechercherContact()
{
    edit->setDisabled(true);
    add->setDisabled(false);
    QString rechercheNom = nom->text();
    QString recherchePrenom = prenom->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM Contact WHERE Nom LIKE :nom AND Prenom LIKE :prenom");
    query.bindValue(":nom", "%" + rechercheNom + "%");
    query.bindValue(":prenom", "%" + recherchePrenom + "%");

    if (query.exec())
    {
        qDebug() << "Requête exécutée";
        interactionsModel->setQuery(query);
        interactionsList->setModelColumn(1);
        contactLabel->setText("");
    }
    else
    {
        qDebug() << "Impossible d'exécuter la requête !";
        qDebug() << "Erreur SQL : " << query.lastError().text();
    }
}

/**
 * Slot pour afficher les interactions du contact sélectionné.
 * @brief InteractionsWindow::afficherInteractionsContact
 * @param index L'index de l'élément sélectionné dans la liste.
 */
void InteractionsWindow::afficherInteractionsContact(const QModelIndex &index)
{
    if (index.isValid() && add->isEnabled())
    {
        edit->setDisabled(false);
        add->setDisabled(true);
        QSqlRecord contactRecord = interactionsModel->record(index.row());
        QString nomContact = contactRecord.value("Nom").toString();
        QString prenomContact = contactRecord.value("Prenom").toString();

        QSqlQuery query;
        query.prepare("SELECT ID, Contenu, Date FROM Interaction WHERE Contact = (SELECT ID FROM Contact WHERE Nom = :nom AND Prenom = :prenom) ORDER BY Date DESC");
        query.bindValue(":nom", nomContact);
        query.bindValue(":prenom", prenomContact);

        contactLabel->setText(nomContact + " " + prenomContact);

        if (query.exec())
        {
            qDebug() << "Requête exécutée";
            interactionsModel->setQuery(query);
            interactionsList->setModelColumn(1);
        }
        else
        {
            qDebug() << "Impossible d'exécuter la requête !";
            qDebug() << "Erreur SQL : " << query.lastError().text();
        }
    }
}

/**
 * Slot pour modifier l'interaction sélectionnée.
 * @brief InteractionsWindow::modifierInteraction
 */
void InteractionsWindow::modifierInteraction()
{
    index = interactionsList->currentIndex();

    if (index.isValid())
    {
        QSqlRecord interactionRecord = interactionsModel->record(index.row());
        QString contenu = interactionRecord.value("Contenu").toString();
        QString date = interactionRecord.value("Date").toString();

        interactionDialog editDialog(contenu, date, this);

        if (editDialog.exec() == QDialog::Accepted)
        {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE Interaction SET Contenu = :contenu WHERE ID = :id");
            updateQuery.bindValue(":contenu", editDialog.getInteractionText());
            updateQuery.bindValue(":id", interactionRecord.value("ID"));

            qDebug() << interactionRecord.value("ID");

            if (updateQuery.exec())
            {
                qDebug() << "Interaction mis à jour avec succès" << updateQuery.executedQuery();
                rechercherContact();
            }
            else
            {
                qDebug() << "Échec de la mise à jour du contact";
                qDebug() << "Erreur SQL : " << updateQuery.lastError().text();
            }
        }
        else
        {
            qDebug() << "Modification de l'interaction annulée";
        }
    }
}

/**
 * Slot pour ajouter une nouvelle interaction.
 * @brief InteractionsWindow::ajouterInteraction
 */
void InteractionsWindow::ajouterInteraction()
{
    QModelIndex index = interactionsList->currentIndex();

    if (index.isValid())
    {
        QSqlRecord contactRecord = interactionsModel->record(index.row());
        QString contactID = contactRecord.value("ID").toString();

        interactionDialog addDialog(this);
        if (addDialog.exec() == QDialog::Accepted)
        {
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO Interaction (Contact, Contenu, Date) VALUES (:contact, :contenu, DATE())");
            insertQuery.bindValue(":contact", contactID);
            insertQuery.bindValue(":contenu", addDialog.getInteractionText());

            if (insertQuery.exec())
            {
                qDebug() << "Interaction ajoutée avec succès";
                rechercherContact();
            }
            else
            {
                qDebug() << "Échec de l'ajout de l'interaction";
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
        qDebug() << "Aucun contact sélectionné pour ajouter une interaction";
    }
}

/**
 * Destructeur de la classe InteractionsWindow.
 * @brief InteractionsWindow::~InteractionsWindow
 */
InteractionsWindow::~InteractionsWindow()
{
}
