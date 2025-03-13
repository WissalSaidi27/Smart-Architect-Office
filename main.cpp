#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    // First, establish the connection
    bool test = c.createconnect();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful.\nClick OK to continue."),
                                 QMessageBox::Ok);


        MainWindow w;
        w.show();
        return a.exec();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection Failed"),
                              QObject::tr("Connection failed.\nClick OK to exit."),
                              QMessageBox::Ok);
        return -1;
    }
}
