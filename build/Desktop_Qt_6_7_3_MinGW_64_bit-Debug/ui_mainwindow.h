/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QTableView *tableViewClients;
    QWidget *tab;
    QPushButton *ajouterClient;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *nomClient;
    QLineEdit *prenomClient;
    QLineEdit *emailClient;
    QLineEdit *addressClient;
    QLineEdit *numTelClient;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *nomClient_up;
    QLineEdit *prenomClient_up;
    QLineEdit *emailClient_up;
    QLineEdit *addressClient_up;
    QLineEdit *numTelClient_up;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *idClient;
    QPushButton *updateClient;
    QWidget *tab_3;
    QGroupBox *groupBox_3;
    QPushButton *deleteclient;
    QLabel *label_12;
    QLineEdit *idClient_del;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(584, 446);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 571, 371));
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tableViewClients = new QTableView(tab_2);
        tableViewClients->setObjectName("tableViewClients");
        tableViewClients->setGeometry(QRect(0, 10, 561, 321));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        ajouterClient = new QPushButton(tab);
        ajouterClient->setObjectName("ajouterClient");
        ajouterClient->setGeometry(QRect(250, 280, 75, 23));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(130, 40, 311, 221));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 47, 13));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 47, 13));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 110, 41, 41));
        nomClient = new QLineEdit(groupBox);
        nomClient->setObjectName("nomClient");
        nomClient->setGeometry(QRect(140, 40, 113, 20));
        prenomClient = new QLineEdit(groupBox);
        prenomClient->setObjectName("prenomClient");
        prenomClient->setGeometry(QRect(140, 80, 113, 20));
        emailClient = new QLineEdit(groupBox);
        emailClient->setObjectName("emailClient");
        emailClient->setGeometry(QRect(140, 120, 113, 20));
        addressClient = new QLineEdit(groupBox);
        addressClient->setObjectName("addressClient");
        addressClient->setGeometry(QRect(140, 150, 113, 20));
        numTelClient = new QLineEdit(groupBox);
        numTelClient->setObjectName("numTelClient");
        numTelClient->setGeometry(QRect(140, 190, 113, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 190, 61, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 160, 61, 16));
        tabWidget->addTab(tab, QString());
        widget = new QWidget();
        widget->setObjectName("widget");
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(140, 20, 311, 261));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 80, 47, 13));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 120, 47, 13));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 150, 41, 41));
        nomClient_up = new QLineEdit(groupBox_2);
        nomClient_up->setObjectName("nomClient_up");
        nomClient_up->setGeometry(QRect(140, 80, 113, 20));
        prenomClient_up = new QLineEdit(groupBox_2);
        prenomClient_up->setObjectName("prenomClient_up");
        prenomClient_up->setGeometry(QRect(140, 120, 113, 20));
        emailClient_up = new QLineEdit(groupBox_2);
        emailClient_up->setObjectName("emailClient_up");
        emailClient_up->setGeometry(QRect(140, 160, 113, 20));
        addressClient_up = new QLineEdit(groupBox_2);
        addressClient_up->setObjectName("addressClient_up");
        addressClient_up->setGeometry(QRect(140, 190, 113, 20));
        numTelClient_up = new QLineEdit(groupBox_2);
        numTelClient_up->setObjectName("numTelClient_up");
        numTelClient_up->setGeometry(QRect(140, 230, 113, 20));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 230, 61, 16));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 200, 61, 16));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 40, 47, 13));
        idClient = new QLineEdit(groupBox_2);
        idClient->setObjectName("idClient");
        idClient->setGeometry(QRect(140, 40, 113, 20));
        updateClient = new QPushButton(widget);
        updateClient->setObjectName("updateClient");
        updateClient->setGeometry(QRect(260, 300, 75, 23));
        tabWidget->addTab(widget, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(110, 30, 351, 181));
        deleteclient = new QPushButton(groupBox_3);
        deleteclient->setObjectName("deleteclient");
        deleteclient->setGeometry(QRect(140, 120, 75, 23));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(60, 50, 47, 13));
        idClient_del = new QLineEdit(groupBox_3);
        idClient_del->setObjectName("idClient_del");
        idClient_del->setGeometry(QRect(190, 50, 113, 20));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 584, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "CLIENTS", nullptr));
        ajouterClient->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter Client", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "NumTel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "CREATE", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Update Client", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "NumTel", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        updateClient->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("MainWindow", "UPDATE", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Delete Client", nullptr));
        deleteclient->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
