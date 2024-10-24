#include "interactiondialog.h"

/**
 * Constructeur de la classe InteractionDialog.
 * @brief InteractionDialog::InteractionDialog
 * @param parent Le widget parent.
 */
interactionDialog::interactionDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Ajouter une interaction");

    interactionTextEdit = new QTextEdit(this);
    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Annuler", this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(interactionTextEdit);
    mainLayout->addWidget(okButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);

    // Connexion des signaux et slots
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

/**
 * Constructeur de la classe InteractionDialog avec des valeurs initiales.
 * @brief InteractionDialog::InteractionDialog
 * @param contenu Le contenu initial de l'interaction.
 * @param date La date initiale de l'interaction.
 * @param parent Le widget parent.
 */
interactionDialog::interactionDialog(const QString &contenu, const QString &date, QWidget *parent)
    : interactionDialog(parent)
{
    setWindowTitle("Edition interaction");
    interactionTextEdit->setText(contenu);
}

/**
 * Getter pour obtenir le texte de l'interaction.
 * @brief InteractionDialog::getInteractionText
 * @return Le texte de l'interaction.
 */
QString interactionDialog::getInteractionText() const
{
    return interactionTextEdit->toPlainText();
}
