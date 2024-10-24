#ifndef INTERACTIONDIALOG_H
#define INTERACTIONDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QLayout>

/**
 * @brief La classe interactionDialog représente la fenêtre de dialogue pour les interactions.
 */
class interactionDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe interactionDialog.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    interactionDialog(QWidget *parent = nullptr);

    /**
     * @brief Constructeur surchargé de la classe interactionDialog pour l'édition d'une interaction existante.
     * @param contenu Contenu de l'interaction à éditer.
     * @param date Date de l'interaction à éditer.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    interactionDialog(const QString &contenu, const QString &date, QWidget *parent = nullptr);

    /**
     * @brief Récupère le texte de l'interaction.
     * @return Texte de l'interaction.
     */
    QString getInteractionText() const;

private:
    QTextEdit *interactionTextEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

};

#endif // INTERACTIONDIALOG_H
