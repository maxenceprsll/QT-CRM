#ifndef TODODIALOG_H
#define TODODIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QCheckBox>

/**
 * @brief La classe todoDialog représente une fenêtre de dialogue pour la gestion des tâches (todos).
 * Elle permet d'ajouter, éditer ou supprimer des tâches.
 */
class todoDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe todoDialog.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    todoDialog(QWidget *parent = nullptr);

    /**
     * @brief Constructeur de la classe todoDialog pour l'édition d'une tâche existante.
     * @param contenu Contenu de la tâche à éditer.
     * @param date Date de la tâche à éditer.
     * @param todoList Liste des cases à cocher associées à la tâche.
     * @param parent Pointeur vers le widget parent (par défaut nullptr).
     */
    todoDialog(const QString &contenu, const QString &date, const QStringList &todoList, QWidget *parent = nullptr);

    /**
     * @brief Récupère le texte de la tâche.
     * @return Texte de la tâche.
     */
    QString getTodoText() const;

private slots:
    /**
     * @brief Ajoute une nouvelle case à cocher à la liste des tâches.
     */
    void ajouterCase();

private:
    QTextEdit *todoTextEdit;
    QListWidget *todoListWidget;
    QPushButton *ajouterButton;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // TODODIALOG_H
