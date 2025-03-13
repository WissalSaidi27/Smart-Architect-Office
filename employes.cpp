#include "employes.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

// Constructeur par défaut
Employe::Employe() {
    matricule_employe = 0;
    nom = "";
    prenom = "";
    email = "";
    mdp = "";
}

// Constructeur avec paramètres (pour 5 paramètres)
Employe::Employe(int matricule, QString nom, QString prenom, QString email, QString mdp)
    : matricule_employe(matricule), nom(nom), prenom(prenom), email(email), mdp(mdp) {}

// Constructeur avec 3 paramètres (comme celui utilisé dans MainWindow)
Employe::Employe(int matricule, const QString &nom, const QString &prenom)
    : matricule_employe(matricule), nom(nom), prenom(prenom), email(""), mdp("") {}

// Ajouter un employé
bool Employe::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (MATRICULE_EMPLOYE, NOM, PRENOM, EMAIL, MDP) "
                  "VALUES (:matricule, :nom, :prenom, :email, :mdp)");
    query.bindValue(":matricule", matricule_employe);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);

    return query.exec();
}

// Supprimer un employé par son matricule
bool Employe::supprimer(int matricule) {
    QSqlQuery query;
    QString res = QString::number(matricule);
    query.prepare("DELETE FROM EMPLOYES WHERE MATRICULE_EMPLOYE = :matricule");
    query.bindValue(":matricule", res);
    return query.exec();
}

// Afficher les employés
QSqlQueryModel* Employe::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT MATRICULE_EMPLOYE, NOM, PRENOM, EMAIL FROM EMPLOYES");

    // Définition des en-têtes de colonnes (facultatif mais recommandé)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));

    return model;
}

// Modifier un employé
bool Employe::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYES SET NOM = :nom, PRENOM = :prenom, EMAIL = :email, MDP = :mdp "
                  "WHERE MATRICULE_EMPLOYE = :matricule");
    query.bindValue(":matricule", matricule_employe);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":mdp", mdp);

    return query.exec();
}
