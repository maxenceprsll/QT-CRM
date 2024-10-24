#include "contactdialog.h"

/**
 * Constructeur par défaut de la classe ContactDialog.
 * @brief contactDialog::contactDialog
 * @param parent Le widget parent.
 */
contactDialog::contactDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Ajouter un contact");

    // Initialisation des widgets
    nomLineEdit = new QLineEdit(this);
    prenomLineEdit = new QLineEdit(this);
    entrepriseLineEdit = new QLineEdit(this);
    mailLineEdit = new QLineEdit(this);
    telephoneLineEdit = new QLineEdit(this);
    photoLineEdit = new QLineEdit(this);

    creationLabel = new QLabel(this);

    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Annuler", this);
    browseButton = new QPushButton("Parcourir", this);

    QHBoxLayout *photoLine = new QHBoxLayout();
    photoLine->addWidget(photoLineEdit);
    photoLine->addWidget(browseButton);

    // Configuration du layout
    QFormLayout *formLayout = new QFormLayout(this);
    formLayout->addRow("Nom:", nomLineEdit);
    formLayout->addRow("Prénom:", prenomLineEdit);
    formLayout->addRow("Entreprise:", entrepriseLineEdit);
    formLayout->addRow("Mail:", mailLineEdit);
    formLayout->addRow("Téléphone:", telephoneLineEdit);
    formLayout->addRow("Photo:", photoLine);
    formLayout->addRow("Date de création:", creationLabel);
    formLayout->addRow(okButton, cancelButton);

    // Connexion des signaux et slots
    connect(browseButton, &QPushButton::clicked, this, &contactDialog::browsePhoto);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

/**
 * Constructeur surchargé de la classe ContactDialog.
 * @brief contactDialog::contactDialog
 * @param nom Le nom du contact.
 * @param prenom Le prénom du contact.
 * @param entreprise Le nom de l'entreprise du contact.
 * @param mail L'adresse e-mail du contact.
 * @param telephone Le numéro de téléphone du contact.
 * @param photo Le chemin vers la photo du contact.
 * @param creation La date de création du contact.
 * @param parent Le widget parent.
 */
contactDialog::contactDialog(const QString &nom, const QString &prenom, const QString &entreprise, const QString &mail, const QString &telephone, const QString &photo, const QString &creation, QWidget *parent)
    : contactDialog(parent)
{
    setWindowTitle("Modifier un contact");

    // Pré-remplissage des champs avec les informations existantes
    nomLineEdit->setText(nom);
    prenomLineEdit->setText(prenom);
    entrepriseLineEdit->setText(entreprise);
    mailLineEdit->setText(mail);
    telephoneLineEdit->setText(telephone);
    photoLineEdit->setText(photo);
    creationLabel->setText(creation);
}

/**
 * Destructeur de la classe ContactDialog.
 * @brief contactDialog::~contactDialog
 */
contactDialog::~contactDialog()
{
}

/**
 * Getter pour le nom mis à jour du contact.
 * @brief contactDialog::getUpdatedNom
 * @return Le nom du contact.
 */
QString contactDialog::getUpdatedNom() const
{
    return nomLineEdit->text();
}

/**
 * Getter pour le prénom mis à jour du contact.
 * @brief contactDialog::getUpdatedPrenom
 * @return Le prénom du contact.
 */
QString contactDialog::getUpdatedPrenom() const
{
    return prenomLineEdit->text();
}

/**
 * Getter pour le nom de l'entreprise mis à jour du contact.
 * @brief contactDialog::getUpdatedEntreprise
 * @return Le nom de l'entreprise du contact.
 */
QString contactDialog::getUpdatedEntreprise() const
{
    return entrepriseLineEdit->text();
}

/**
 * Getter pour l'adresse e-mail mise à jour du contact.
 * @brief contactDialog::getUpdatedMail
 * @return L'adresse e-mail du contact.
 */
QString contactDialog::getUpdatedMail() const
{
    return mailLineEdit->text();
}

/**
 * Getter pour le numéro de téléphone mis à jour du contact.
 * @brief contactDialog::getUpdatedTelephone
 * @return Le numéro de téléphone du contact.
 */
QString contactDialog::getUpdatedTelephone() const
{
    return telephoneLineEdit->text();
}

/**
 * Getter pour le chemin de la photo mis à jour du contact.
 * @brief contactDialog::getUpdatedPhoto
 * @return Le chemin vers la photo du contact.
 */
QString contactDialog::getUpdatedPhoto() const
{
    return photoLineEdit->text();
}

/**
 * Slot pour ouvrir la boîte de dialogue de parcours de fichiers et choisir une photo.
 * @brief contactDialog::browsePhoto
 */
void contactDialog::browsePhoto()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Choisir une photo"), QDir::homePath(), tr("Images (*.png *.jpg *.bmp *.jpeg)"));
    if (!filePath.isEmpty())
    {
        photoLineEdit->setText(filePath);
    }
}
