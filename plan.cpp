#include "plan.h"
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
#include <QMessageBox>
#include<QWidget>
#include <QPrinter>
plan::plan(int id_plan, QString nom_plan,QString type_plan ,QString description ,QString photo,QDate date_creation)
{
    this->id_plan=id_plan;
    this->nom_plan=nom_plan;
    this->type_plan=type_plan;
    this->description=description;
    this->photo=photo;
    this->date_creation=date_creation;

}
//fonction ajouter plan
bool plan::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO PLAN (NOM_PLAN, TYPE_PLAN, DESCRIPTION, DATE_CREATION, PHOTO) "
                  "VALUES (:nom_plan, :type_plan, :description, TO_DATE(:date_creation, 'DD-MM-YYYY'), :photo)");

    //query.bindValue(":id_plan", id_plan);
    query.bindValue(":nom_plan", nom_plan);
    query.bindValue(":type_plan", type_plan);
    query.bindValue(":description", description);
    query.bindValue(":photo", photo);
    query.bindValue(":date_creation", date_creation.toString("dd-MM-yyyy"));


    qDebug() << " Requête SQL:" << query.executedQuery();
    qDebug() << "Valeurs:"
             << nom_plan << type_plan << description << photo << date_creation.toString("yyyy-MM-dd");


    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du plan:" << query.lastError().text();
        return false;
    }
    return true;
}
//fonction afficher plan
QSqlQueryModel* plan::afficher_Plan() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Vérifie si la base est ouverte
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "❌ ERREUR : La base de données est fermée ! Tentative de reconnexion...";
        if (!db.open()) {
            qDebug() << "⚠️ Impossible de rouvrir la connexion :" << db.lastError().text();
            return nullptr;
        }
    }

    // Exécuter la requête d'affichage
    query.prepare("SELECT * FROM PLAN");
    if (!query.exec()) {
        qDebug() << "❌ ERREUR SQL lors de l'affichage des plans :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(query);
    qDebug() << "✅ Nombre de plans affichés :" << model->rowCount();
    return model;
}



//fonction afficher plan Modifier
QSqlQueryModel* plan::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM plan");
    return model;
}
//fonction modifier plan
bool plan::modifier(int id_plan)
{
    if (nom_plan.isEmpty() || type_plan.isEmpty() || description.isEmpty() || photo.isEmpty()) {
        qDebug() << " Erreur : Un ou plusieurs champs sont vides.";
        return false;  // Annuler l'ajout si un champ est vide
    }
    QSqlQuery query;
    query.prepare("UPDATE plan SET nom_plan = :nom_plan, type_plan = :type_plan, description = :description, "
                  "date_creation = TO_DATE(:date_creation, 'YYYY-MM-DD'), photo = :photo WHERE id_plan = :id_plan");

    query.bindValue(":id_plan", id_plan);
    query.bindValue(":nom_plan", this->nom_plan);
    query.bindValue(":type_plan", this->type_plan);
    query.bindValue(":description", this->description);
    query.bindValue(":photo", this->photo);
    query.bindValue(":date_creation", date_creation.toString("yyyy-MM-dd"));
    qDebug() << "Requête SQL :" << query.executedQuery();
    qDebug() << " Valeurs :" << id_plan << nom_plan << type_plan << description << photo << date_creation.toString("yyyy-MM-dd");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification :" << query.lastError().text();
        return false;
    }
    return true;
}
//fonction supprimer plan
bool plan::supprimer(int id_plan)
{
    QSqlQuery query;
    query.prepare("DELETE FROM plan WHERE id_plan = :id_plan");
    query.bindValue(":id_plan", id_plan);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du plan:" << query.lastError().text();
        return false;
    }
    return true;

}
//tri
QSqlQueryModel *  plan::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from plan order by "+critere+" "+mode+"");

    return model;
}
//recherche
QSqlQueryModel* plan::rechercher(const QString &aux)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // ✅ Requête SQL protégée contre l'injection SQL
    query.prepare("SELECT * FROM plan WHERE "
                  "TO_CHAR(id_plan) LIKE :search");

    query.bindValue(":search", "%" + aux + "%");

    if (!query.exec()) {
        qDebug() << "❌ ERREUR SQL lors de la recherche :" << query.lastError().text();
        delete model;  // ✅ Éviter les fuites mémoire
        return nullptr;
    }

    model->setQuery(query);
    return model;
}
QMap<QString, int> plan::statistiquesPlans() {
    QMap<QString, int> stats;
    QSqlQuery query;
    query.prepare("SELECT TYPE_PLAN, COUNT(*) AS COUNT_TYPE_PLAN FROM PLAN GROUP BY TYPE_PLAN");


    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des statistiques :" << query.lastError().text();
        return stats;
    }

    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        stats.insert(type, count);
    }

    return stats;
}

