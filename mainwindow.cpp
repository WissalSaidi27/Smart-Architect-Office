#include "mainwindow.h"
#include "employes.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Assurez-vous que l'objet employé (Etmp) est initialisé avant l'utilisation
    connect(ui->pushButton_ajouter, &QPushButton::clicked, this, &MainWindow::on_pushButton_ajouter_clicked);
    connect(ui->pushButton_supprimer, &QPushButton::clicked, this, &MainWindow::on_pushButton_supprimer_clicked);
    connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int matricule = ui->lineEdit_matricule->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();

    // Utilisation du constructeur avec 3 paramètres
    Employe E(matricule, nom, prenom); // Constructeur avec 3 paramètres
    bool test = E.ajouter(); // Appelle la méthode ajouter et assigne le résultat à test

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Ok"), QObject::tr("Ajout effectué\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"), QObject::tr("Ajout non effectué\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int matricule = ui->lineEdit_matricule->text().toInt();

    // Supposons que Etmp soit un objet de la classe employe déjà défini quelque part
    bool test = Etmp.supprimer(matricule); // Appelle la méthode supprimer et assigne le résultat à test

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Ok"), QObject::tr("Suppression effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"), QObject::tr("Suppression non effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_modifier_clicked()
{
    int matricule = ui->lineEdit_matricule->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString email = ui->lineEdit_email->text();
    QString mdp = ui->lineEdit_mdp->text();

    Employe E(matricule, nom, prenom, email, mdp); // Crée un objet employé avec les valeurs de la UI
    bool test = E.modifier(); // Appelle la méthode modifier et assigne le résultat à test

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Ok"), QObject::tr("Modification effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"), QObject::tr("Modification non effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}
