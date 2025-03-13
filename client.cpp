#include "client.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "connection.h"
#include <QPdfWriter>
#include <QPainter>

// Constructeur par défaut
Client::Client() {}

// Constructeur avec paramètres
Client::Client(int id, QString nom, QString prenom, QString email, QString adresse, int numero_tel)
    : nom(nom), prenom(prenom), email(email), adresse(adresse), id(id), numero_tel(numero_tel)
{
}

Client::Client(QString nom, QString prenom, QString email, QString adresse, int numero_tel)
    : nom(nom), prenom(prenom), email(email), adresse(adresse), numero_tel(numero_tel)
{
}
// Ajouter un client
bool Client::ajouter()
{
    QString res_id = QString::number(id);
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTS (NOM, PRENOM, EMAIL, ADRESSE, NUMERO_TEL) "
                  "VALUES (:nom, :prenom, :email, :adresse, :numero_tel)");


    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":numero_tel", numero_tel);

    return query.exec();
}

// Supprimer un client
bool Client::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTS WHERE ID = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// Afficher tous les clients
QSqlQueryModel* Client::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTS");
    return model;
}

// Modifier un client
bool Client::modifier(int id, QString nom, QString prenom, QString email, QString adresse, int numero_tel) {
    QSqlQuery query;
    query.prepare("UPDATE CLIENTS SET NOM = :nom, PRENOM = :prenom, EMAIL = :email, ADRESSE = :adresse, NUMERO_TEL = :numero_tel WHERE ID = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":numero_tel", numero_tel);
    query.bindValue(":id", id);

    return query.exec();
}

QSqlQueryModel* Client::trie_id(bool asc) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM CLIENTS ORDER BY ID " + QString(asc ? "ASC" : "DESC");
    model->setQuery(queryStr);
    return model;
}

// Trier les clients par Nom
QSqlQueryModel* Client::trie_nom(bool asc) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM CLIENTS ORDER BY NOM " + QString(asc ? "ASC" : "DESC");
    model->setQuery(queryStr);
    return model;
}

// Rechercher un client par Nom
QSqlQueryModel* Client::cherchernom(QString recherche) {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENTS WHERE LOWER(NOM) LIKE LOWER('" + recherche + "%')");
    return model;
}

// Générer un PDF des clients
void Client::pdfprinter()
{
    QPdfWriter pdf("C:/Users/soufi/Documents/ambulance/clients.pdf");
    QPainter painter(&pdf);

    // Titre
    painter.setPen(Qt::red);
    painter.setFont(QFont("Arial", 50));
    painter.drawText(2000, 1000, "CLIENTS");

    // Logo
    QPixmap originalPixmap("C:/Users/soufi/Downloads/logoqttrans (1).jpg");
    QPixmap scaledPixmap = originalPixmap.scaled(QSize(3000, 1300), Qt::KeepAspectRatio);
    painter.drawPixmap(QRect(7000, 70, 3000, 1300), scaledPixmap);

    // En-tête du tableau
    painter.setFont(QFont("Arial", 10));
    painter.setPen(Qt::red);
    painter.drawText(500, 3300, "ID");
    painter.drawText(1400, 3300, "Nom");
    painter.drawText(2250, 3300, "Prénom");
    painter.drawText(3500, 3300, "Email");
    painter.drawText(5000, 3300, "Adresse");
    painter.drawText(6500, 3300, "Téléphone");

    QSqlQuery query;
    int i = 4000;

    query.prepare("SELECT * FROM CLIENTS");
    if (query.exec()) {
        while (query.next()) {
            painter.setPen(Qt::black);
            painter.setFont(QFont("Arial", 8));
            painter.drawText(500, i, query.value(0).toString()); // ID
            painter.drawText(1400, i, query.value(1).toString()); // Nom
            painter.drawText(2250, i, query.value(2).toString()); // Prénom
            painter.drawText(3500, i, query.value(3).toString()); // Email
            painter.drawText(5000, i, query.value(4).toString()); // Adresse
            painter.drawText(6500, i, query.value(5).toString()); // Téléphone

            i += 500;
        }
    }
}
