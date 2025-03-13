#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe {
public:
    Employe();
    Employe(int matricule, QString nom, QString prenom, QString email, QString mdp);
    Employe(int matricule, const QString &nom, const QString &prenom);
    bool ajouter();
    bool supprimer(int matricule);
    bool modifier();
    QSqlQueryModel* afficher();

    int getCin() { return matricule_employe; }
    QString getNom() { return nom; }
    QString getPrenom() { return prenom; }
    QString getEmail() { return email; }


private:
    int matricule_employe;
    QString nom, prenom, email, mdp;


};

#endif // EMPLOYE_H
