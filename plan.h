#ifndef PLAN_H
#define PLAN_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
#include <QSqlTableModel>

class plan
{
    int id_plan;
    QString nom_plan,type_plan,description,photo;
    QDate date_creation;
public:
    //constructeur
    plan(){}

    plan(int id_plan,QString nom_plan,QString type_plan,QString description,QString photo, QDate date_creation);

    //Getters
    int getId_plan(){return id_plan;}
    QString getNom_plan(){return nom_plan;}
    QString getType_plan(){return type_plan;}
    QString getDescription(){return description;}
    QString getPhoto(){return photo;}
    QDate getDate_creation(){return date_creation;}

    //Setters
    void setId_plan(int id_plan);
    void setNom_plan(QString nom_plan);
    void setType_plan(QString type_plan);
    void setDate_Creation(QDate date_creation);
    void setPhoto(QString photo);
    void setDescription(QString description);

    //fonctionnalités
    bool ajouter();
    QSqlQueryModel * chercher(int);
    bool modifier(int);
    bool supprimer(int);
    QSqlQueryModel* afficher();


};

#endif // PLAN_H
