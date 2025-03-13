#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "Inscription.h"  // Inclure le fichier d'en-tête de la fenêtre d'inscription
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)  // Assure-toi que la classe Ui::Login est bien définie
{
    ui->setupUi(this);

    // Connecter le bouton d'inscription à la fonction ouvrirInscription
    connect(ui->pushButton_inscrire, &QPushButton::clicked, this, &Login::ouvrirInscription);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom d'utilisateur et un mot de passe.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE EMAIL = :email AND MDP = :mdp");
    query.bindValue(":email", username);
    query.bindValue(":mdp", password);

    if (query.exec() && query.next()) {  // Vérifie si l'utilisateur existe
        QMessageBox::information(this, "Connexion réussie", "Bienvenue, " + username + " !");

        MainWindow *mainWin = new MainWindow();
        mainWin->show();

        this->close();
    } else {
        QMessageBox::warning(this, "Échec de connexion", "Email ou mot de passe incorrect.");
    }
}

// Fonction pour ouvrir la page d'inscription
void Login::ouvrirInscription()
{
    this->close();  // Ferme la fenêtre de login
    Inscription inscriptionWindow;  // Crée une instance de la fenêtre d'inscription
    inscriptionWindow.exec();  // Affiche la fenêtre d'inscription
}
