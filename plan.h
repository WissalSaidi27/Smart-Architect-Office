#ifndef PLAN_H
#define PLAN_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
#include <QSqlTableModel>
#include <QGraphicsScene>

#include <QGraphicsRectItem>

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
    QSqlQueryModel* afficher_Plan();
    bool modifier(int);
    bool supprimer(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* trier(const QString &critere, const QString &mode);
    QSqlQueryModel * rechercher (const QString &aux);
    QMap<QString, int> statistiquesPlans();
    //void genererPlan();



};

#endif // PLAN_H
