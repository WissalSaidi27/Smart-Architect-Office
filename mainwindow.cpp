#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    display();


}

MainWindow::~MainWindow()
{

    delete ui;
}
void MainWindow::display(){
    Client client;
    QSqlQueryModel* model = client.afficher();
    ui->tableViewClients->setModel(model);
}
void MainWindow::on_ajouterClient_clicked()
{

    QString nom = ui->nomClient->text();
    QString prenom = ui->prenomClient->text();
    QString email = ui->emailClient->text();
    QString adresse = ui->addressClient->text();
    bool conversionOk;
    int numero_tel = ui->numTelClient->text().toInt(&conversionOk);

    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || adresse.isEmpty() || !conversionOk) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs correctement.");
        return;
    }

    Client client(nom, prenom, email, adresse, numero_tel);
    if (client.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout du client a échoué.");
    }
display();
    clear();
}


void MainWindow::on_updateClient_clicked()
{
    int id = ui->idClient->text().toInt();
    QString nom = ui->nomClient_up->text();
    QString prenom = ui->prenomClient_up->text();
    QString email = ui->emailClient_up->text();
    QString adresse = ui->addressClient_up->text();
    bool conversionOk;
    int numero_tel = ui->numTelClient_up->text().toInt(&conversionOk);

    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || adresse.isEmpty() || !conversionOk) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs correctement.");
        return;
    }

    Client client;
    bool check = client.modifier(id,nom,prenom,email,adresse,numero_tel);

    if (check) {
        QMessageBox::information(this, "Succès", "Client modifie avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "la modification du client a échoué.");
    }
display();
    clear();
}


void MainWindow::on_deleteclient_clicked()
{
    int id = ui->idClient_del->text().toInt();
    Client client;
    bool check = client.supprimer(id);

    if (check) {
        QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "la suppression du client a échoué.");
    }

display();
    clear();
}
void MainWindow::clear()
    {
    ui->idClient->clear();
     ui->nomClient_up->clear();
    ui->prenomClient_up->clear();
     ui->emailClient_up->clear();
     ui->addressClient_up->clear();

     ui->numTelClient->clear();

     ui->nomClient->clear();
     ui->prenomClient->clear();
     ui->emailClient->clear();
     ui->addressClient->clear();

     ui->numTelClient->clear();
     ui->idClient_del->clear();
    }




