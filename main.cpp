#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "login.h"
#include "inscription.h"  // Si vous voulez afficher la fenêtre d'inscription
#include <QSqlDatabase>
#include <QSqlError>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Connexion à la base de données
    Connection c;
    if (c.createconnect()) {  // Vérifiez la connexion à la base de données
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click OK to continue."), QMessageBox::Ok);

        // Affichage de la fenêtre de connexion
        Login l;
        if (l.exec() == QDialog::Accepted) {
            // Si la connexion est réussie, on ouvre la fenêtre principale
            MainWindow w;  // Crée un objet MainWindow
            w.show();      // Affiche la fenêtre principale
            return a.exec(); // Lance l'application
        }
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        return -1; // Si la connexion échoue, quitter l'application
    }

    // Si l'utilisateur souhaite s'inscrire, afficher la fenêtre d'inscription
    Inscription w;  // Crée un objet Inscription
    w.show();       // Affiche la fenêtre d'inscription

    return a.exec();  // Lance l'application
}
