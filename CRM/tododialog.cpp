#include "tododialog.h"

/**
 * @brief Constructeur de la classe todoDialog.
 * @param parent Pointeur vers le widget parent (par défaut nullptr).
 */
todoDialog::todoDialog(QWidget *parent) : QDialog(parent)
{
    // Configuration de la fenêtre de dialogue
    setWindowTitle("Ajouter une tâche");

        // Création des éléments d'interface utilisateur
        todoTextEdit = new QTextEdit(this);
    todoListWidget = new QListWidget(this);
    ajouterButton = new QPushButton("Ajouter une case", this);
    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Annuler", this);

    // Création du layout principal
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Ajout des éléments au layout principal
    mainLayout->addWidget(todoTextEdit);
    mainLayout->addWidget(todoListWidget);
    mainLayout->addWidget(ajouterButton);
    mainLayout->addWidget(okButton);
    mainLayout->addWidget(cancelButton);

    // Définition du layout principal de la fenêtre
    setLayout(mainLayout);

    // Connexion des signaux aux slots
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    connect(ajouterButton, &QPushButton::clicked, this, &todoDialog::ajouterCase);
}

/**
 * @brief Constructeur de la classe todoDialog pour l'édition d'une tâche existante.
 * @param contenu Texte de la tâche.
 * @param date Date de la tâche.
 * @param todoList Liste des cases à cocher.
 * @param parent Pointeur vers le widget parent (par défaut nullptr).
 */
todoDialog::todoDialog(const QString &contenu, const QString &date, const QStringList &todoList, QWidget *parent)
    : todoDialog(parent)
{
    // Configuration de la fenêtre de dialogue pour l'édition de tâche
    setWindowTitle("Edition tâche");

        // Affichage du contenu de la tâche dans le champ de texte
        todoTextEdit->setText(contenu);

    // Ajout des éléments de la liste de tâches à la QListWidget
    foreach (const QString &todo, todoList)
    {
        QCheckBox *checkBox = new QCheckBox(todo);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(checkBox->sizeHint());
        todoListWidget->addItem(item);
        todoListWidget->setItemWidget(item, checkBox);
    }
}

/**
 * @brief Obtient le texte de la tâche.
 * @return Texte de la tâche.
 */
QString todoDialog::getTodoText() const
{
    // Récupération du texte de la tâche
    return todoTextEdit->toPlainText();
}

/**
 * @brief Slot appelé lors de l'ajout d'une nouvelle case à cocher.
 */
void todoDialog::ajouterCase()
{
    // Ajout d'une nouvelle case à cocher à la QListWidget
    QCheckBox *checkBox = new QCheckBox("Nouvelle case");
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(checkBox->sizeHint());
    todoListWidget->addItem(item);
    todoListWidget->setItemWidget(item, checkBox);
}
