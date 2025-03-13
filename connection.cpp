#include "connection.h"
#include <QDebug>
#include <QMessageBox>

Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createconnect()
{
    bool test = false;
    db.setDatabaseName("Source_Projet2A"); // Insérer le nom de la source de données
    db.setUserName("ibrahim"); // Insérer nom de l'utilisateur
    db.setPassword("123456789"); // Insérer mot de passe de cet utilisateur

    if (db.open()) {
        test = true;
    } else {
        qDebug() << "Erreur de connexion : " << db.lastError().text();
    }

    return test;
}

void Connection::closeConnection()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "Connexion fermée avec succès.";
    }
}
