#include "inscription.h"
#include "ui_inscription.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Inscription::Inscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inscription)  // Initialise l'interface utilisateur
{
    ui->setupUi(this);  // Assure-toi que le setup est correctement fait
}

Inscription::~Inscription()
{
    delete ui;  // Détruit l'interface utilisateur
}

void Inscription::on_pushButton_register_clicked()
{
    // Récupère les valeurs du formulaire
    QString email = ui->lineEdit_email->text();
    QString motDePasse = ui->lineEdit_password->text();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();

    // Vérification si tous les champs sont remplis
    if (email.isEmpty() || motDePasse.isEmpty() || nom.isEmpty() || prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        query.next();
        if (query.value(0).toInt() > 0) {
            QMessageBox::warning(this, "Erreur", "Cet email est déjà utilisé.");
            return;
        }
    } else {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    // **Ne pas hacher le mot de passe**, insérer directement le mot de passe
    QString password = motDePasse;  // Utilise le mot de passe tel quel

    query.prepare("INSERT INTO EMPLOYES (EMAIL, MDP, NOM, PRENOM) VALUES (:email, :mdp, :nom, :prenom)");
    query.bindValue(":email", email);
    query.bindValue(":mdp", password);  // Insère directement le mot de passe sans le hacher
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Employé enregistré avec succès.");
        this->close();
    } else {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
    }
}
