#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>  // Ajout de l'inclusion pour QDate

using namespace std;

class Client
{
private:
    QString nom, prenom, email, adresse;
    int id, numero_tel;

public:
    // Constructeurs
    Client();
    Client(int id, QString nom, QString prenom, QString email, QString adresse, int numero_tel);
    Client(QString nom, QString prenom, QString email, QString adresse, int numero_tel);

    // Getters
    QString getNom() { return nom; }
    QString getPrenom() { return prenom; }
    QString getEmail() { return email; }
    QString getAdresse() { return adresse; }
    int getNumero_tel() { return numero_tel; }
    int getId() { return id; }

    // Setters
    void setNom(QString n) { nom = n; }
    void setPrenom(QString p) { prenom = p; }
    void setEmail(QString e) { email = e; }
    void setAdresse(QString ad) { adresse = ad; }
    void setNumero_tel(int num) { numero_tel = num; }
    void setId(int id) { this->id = id; }

    // Fonctions liées à la base de données
    QString get_function();
    QSqlQueryModel* afficher();
    QSqlQueryModel* trie_id(bool asc);  // Ajout du paramètre bool asc
    QSqlQueryModel* trie_nom(bool asc);  // Ajout du paramètre bool asc
    void pdfprinter();
    QSqlQueryModel* cherchernom(QString nom);
    bool ajouter();
    bool supprimer(int id);
    bool modifier(int id, QString nom, QString prenom, QString email, QString adresse, int numero_tel); // Déclaration corrigée
};

#endif // CLIENT_H
