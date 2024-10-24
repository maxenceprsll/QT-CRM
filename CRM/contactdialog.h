#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QLayout>
/**
 * @brief La classe contactDialog représente une fenêtre de dialogue pour la création ou la modification d'un contact.
 */
class contactDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe contactDialog pour la création d'un nouveau contact.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    contactDialog(QWidget *parent = nullptr);

    /**
     * @brief Constructeur de la classe contactDialog pour la modification d'un contact existant.
     * @param nom Nom du contact.
     * @param prenom Prénom du contact.
     * @param entreprise Entreprise du contact.
     * @param mail Adresse e-mail du contact.
     * @param telephone Numéro de téléphone du contact.
     * @param photo Chemin vers la photo du contact.
     * @param creation Date de création du contact.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    contactDialog(const QString &nom, const QString &prenom, const QString &entreprise, const QString &mail, const QString &telephone, const QString &photo, const QString &creation, QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe contactDialog.
     */
    ~contactDialog();

    /**
     * @brief Obtient le nom mis à jour du contact.
     * @return Nom du contact.
     */
    QString getUpdatedNom() const;

    /**
     * @brief Obtient le prénom mis à jour du contact.
     * @return Prénom du contact.
     */
    QString getUpdatedPrenom() const;

    /**
     * @brief Obtient l'entreprise mise à jour du contact.
     * @return Entreprise du contact.
     */
    QString getUpdatedEntreprise() const;

    /**
     * @brief Obtient l'adresse e-mail mise à jour du contact.
     * @return Adresse e-mail du contact.
     */
    QString getUpdatedMail() const;

    /**
     * @brief Obtient le numéro de téléphone mis à jour du contact.
     * @return Numéro de téléphone du contact.
     */
    QString getUpdatedTelephone() const;

    /**
     * @brief Obtient le chemin vers la photo mise à jour du contact.
     * @return Chemin vers la photo du contact.
     */
    QString getUpdatedPhoto() const;

private:
    QLineEdit *nomLineEdit;
    QLineEdit *prenomLineEdit;
    QLineEdit *entrepriseLineEdit;
    QLineEdit *mailLineEdit;
    QLineEdit *telephoneLineEdit;
    QLineEdit *photoLineEdit;

    QLabel *creationLabel;

    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *browseButton;

public slots:
    /**
     * @brief Slot pour parcourir et sélectionner une photo.
     */
    void browsePhoto();
};

#endif // CONTACTDIALOG_H

