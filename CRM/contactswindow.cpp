#include "contactswindow.h"
#include "contactdialog.h"

/**
 * Constructeur de la classe ContactsWindow.
 * @brief ContactsWindow::ContactsWindow
 * @param parent Le widget parent.
 */
ContactsWindow::ContactsWindow(QWidget *parent) : QWidget(parent)
{
    cLayout = new QVBoxLayout();

    vl_contact = new QVBoxLayout();
    hl_search = new QHBoxLayout();

    // Configuration du formulaire de recherche
    form_rech = new QFormLayout;
    nom = new QLineEdit();
    prenom = new QLineEdit();
    form_rech->addRow(new QLabel("Rechercher un contact :"));
    form_rech->addRow(new QLabel("Nom"), nom);
    form_rech->addRow(new QLabel("Prénom"), prenom);

        researchBut = new QPushButton("Rechercher");

    hl_search->addLayout(form_rech);
    hl_search->addWidget(researchBut);

    // Initialisation de la liste de contacts
    contactList = new QListView();

    // Configuration du layout vertical pour les contacts
    vl_contact->addLayout(hl_search);
    vl_contact->addWidget(contactList);

    hl_crud = new QHBoxLayout();

    // Configuration des boutons pour CRUD
    remove = new QPushButton("-");
    edit = new QPushButton("Modifier");
    add = new QPushButton("+");

    hl_crud->addWidget(remove);
    hl_crud->addWidget(edit);
    hl_crud->addWidget(add);

    // Ajout des layouts au layout principal
    vl_contact->addLayout(hl_crud);
    cLayout->addLayout(vl_contact);

    setLayout(cLayout);

    //*****//

    // Configuration du modèle de la liste de contacts
    contactsModel = new QSqlQueryModel(this);
    contactList->setModel(contactsModel);

    itemDelegate = new QStyledItemDelegate(this);
    contactList->setItemDelegate(itemDelegate);

    //*****//

    // Connexion des signaux et slots
    connect(researchBut, &QPushButton::clicked, this, &ContactsWindow::rechercherContacts);
    connect(edit, &QPushButton::clicked, this, &ContactsWindow::editerContact);
    connect(contactList, &QListView::doubleClicked, this, &ContactsWindow::editerContact);
    connect(remove, &QPushButton::clicked, this, &ContactsWindow::supprimerContact);
    connect(add, &QPushButton::clicked, this, &ContactsWindow::ajouterContact);
}

/**
 * Slot pour rechercher les contacts en fonction des critères de recherche.
 * @brief ContactsWindow::rechercherContacts
 */
void ContactsWindow::rechercherContacts()
{
    QString rechercheNom = nom->text();
    QString recherchePrenom = prenom->text();

    QSqlQuery query;
    query.prepare("SELECT ID, Nom, Prenom, Entreprise, Mail, Telephone, Photo, Creation FROM Contact WHERE Nom LIKE :nom AND Prenom LIKE :prenom");
    query.bindValue(":nom", "%" + rechercheNom + "%");
    query.bindValue(":prenom", "%" + recherchePrenom + "%");

    if (query.exec())
    {
        qDebug() << "Requête exécutée";
        contactsModel->setQuery(query);
        contactList->setModelColumn(1);
    }
    else
    {
        qDebug() << "Impossible d'exécuter la requête !";
        qDebug() << "Erreur SQL : " << query.lastError().text();
    }
}

/**
 * Slot pour éditer un contact sélectionné.
 * @brief ContactsWindow::editerContact
 */
void ContactsWindow::editerContact()
{
    QModelIndex index = contactList->currentIndex();

    if (index.isValid())
    {
        QSqlRecord record = contactsModel->record(index.row());
        QString nom = record.value("Nom").toString();
        QString prenom = record.value("Prenom").toString();
        QString entreprise = record.value("Entreprise").toString();
        QString mail = record.value("Mail").toString();
        QString telephone = record.value("Telephone").toString();
        QString photo = record.value("Photo").toString();
        QString creation = record.value("Creation").toString();

        // Ouvrir la boîte de dialogue pour éditer le contact
        contactDialog editDialog(nom, prenom, entreprise, mail, telephone, photo, creation, this);

        if (editDialog.exec() == QDialog::Accepted)
        {
            // Demander confirmation avant de mettre à jour le contact
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment modifier ce contact?", QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes)
            {
                // Mettre à jour le contact dans la base de données
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE Contact SET Nom = :nom, Prenom = :prenom, Entreprise = :entreprise, Mail = :mail, Telephone = :telephone, Photo = :photo WHERE ID = :id");
                updateQuery.bindValue(":nom", editDialog.getUpdatedNom());
                updateQuery.bindValue(":prenom", editDialog.getUpdatedPrenom());
                updateQuery.bindValue(":entreprise", editDialog.getUpdatedEntreprise());
                updateQuery.bindValue(":mail", editDialog.getUpdatedMail());
                updateQuery.bindValue(":telephone", editDialog.getUpdatedTelephone());
                updateQuery.bindValue(":photo", editDialog.getUpdatedPhoto());
                updateQuery.bindValue(":id", record.value("ID"));

                if (updateQuery.exec())
                {
                    qDebug() << "Contact mis à jour avec succès";
                    rechercherContacts();
                }
                else
                {
                    qDebug() << "Échec de la mise à jour du contact";
                    qDebug() << "Erreur SQL : " << updateQuery.lastError().text();
                }
            }
            else
            {
                qDebug() << "Modification annulée";
            }
        }
    }
    else
    {
        qDebug() << "Aucun contact sélectionné pour la modification";
    }
}

/**
 * Slot pour supprimer le contact sélectionné.
 * @brief ContactsWindow::supprimerContact
 */
void ContactsWindow::supprimerContact()
{
    QModelIndex index = contactList->currentIndex();

    if (index.isValid())
    {
        QSqlRecord record = contactsModel->record(index.row());

        // Demander confirmation avant de supprimer le contact
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce contact?", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            // Supprimer le contact de la base de données
            QSqlQuery deleteQuery;
            deleteQuery.prepare("DELETE FROM Contact WHERE ID = :id");
            deleteQuery.bindValue(":id", record.value("ID"));

            if (deleteQuery.exec())
            {
                qDebug() << "Contact supprimé avec succès";
                rechercherContacts();
            }
            else
            {
                qDebug() << "Échec de la suppression du contact";
                    qDebug() << "Erreur SQL : " << deleteQuery.lastError().text();
            }
        }
        else
        {
            qDebug() << "Suppression annulée";
        }
    }
    else
    {
        qDebug() << "Aucun contact sélectionné pour la suppression";
    }
}

/**
 * Slot pour ajouter un nouveau contact.
 * @brief ContactsWindow::ajouterContact
 */
void ContactsWindow::ajouterContact()
{
    // Ouvrir la boîte de dialogue pour ajouter un nouveau contact
    contactDialog addDialog(this);
    if (addDialog.exec() == QDialog::Accepted)
    {
        // Insérer le nouveau contact dans la base de données
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO Contact (Nom, Prenom, Entreprise, Mail, Telephone, Photo, Creation) VALUES (:nom, :prenom, :entreprise, :mail, :telephone, :photo, DATE())");
        insertQuery.bindValue(":nom", addDialog.getUpdatedNom());
        insertQuery.bindValue(":prenom", addDialog.getUpdatedPrenom());
        insertQuery.bindValue(":entreprise", addDialog.getUpdatedEntreprise());
        insertQuery.bindValue(":mail", addDialog.getUpdatedMail());
        insertQuery.bindValue(":telephone", addDialog.getUpdatedTelephone());
        insertQuery.bindValue(":photo", addDialog.getUpdatedPhoto());

        if (insertQuery.exec())
        {
            qDebug() << "Contact ajouté avec succès";
            rechercherContacts();
        }
        else
        {
            qDebug() << "Échec de l'ajout du contact";
                qDebug() << "Erreur SQL : " << insertQuery.lastError().text();
        }
    }
    else
    {
        qDebug() << "Ajout annulé";
    }
}

/**
 * Destructeur de la classe ContactsWindow.
 * @brief ContactsWindow::~ContactsWindow
 */
ContactsWindow::~ContactsWindow()
{
}
