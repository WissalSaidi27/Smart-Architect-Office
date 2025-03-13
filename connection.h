#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
private:
    QSqlDatabase db; // Déclaration de l'objet base de données

public:
    Connection();
    bool createconnect();
    void closeConnection();
};

#endif // CONNECTION_H
