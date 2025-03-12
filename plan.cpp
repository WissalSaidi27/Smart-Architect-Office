#include "plan.h"
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
plan::plan(int id_plan, QString nom_plan,QString type_plan ,QString description ,QString photo,QDate date_creation)
{
    this->id_plan=id_plan;
    this->nom_plan=nom_plan;
    this->type_plan=type_plan;
    this->description=description;
    this->photo=photo;
    this->date_creation=date_creation;

}
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
QSqlQueryModel* plan::chercher(int id) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM plan WHERE id_plan = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche :" << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);
    return model;
}
QSqlQueryModel* plan::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM plan");
    return model;
}



bool plan::modifier(int id_plan)
{
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
