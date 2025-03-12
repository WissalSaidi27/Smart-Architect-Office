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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowCrud
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_5;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_9;
    QWidget *tab_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_6;
    QTextEdit *textEdit_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_10;
    QWidget *tab_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_7;
    QTextEdit *textEdit_4;
    QLineEdit *lineEdit_8;
    QTextEdit *textEdit_5;
    QLineEdit *lineEdit_9;
    QTextEdit *textEdit_6;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_11;
    QDateEdit *dateEdit_2;
    QLineEdit *lineEdit_12;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label_11;
    QWidget *tab_4;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_13;
    QPlainTextEdit *plainTextEdit_3;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowCrud)
    {
        if (MainWindowCrud->objectName().isEmpty())
            MainWindowCrud->setObjectName("MainWindowCrud");
        MainWindowCrud->resize(800, 600);
        centralwidget = new QWidget(MainWindowCrud);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(-10, 0, 791, 551));
        tab = new QWidget();
        tab->setObjectName("tab");
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(-20, 0, 811, 521));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/back.jpg")));
        label->setScaledContents(true);
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(180, 140, 121, 28));
        QFont font;
        font.setPointSize(11);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(180, 190, 113, 28));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(180, 240, 161, 28));
        lineEdit_3->setFont(font);
        lineEdit_3->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(180, 290, 141, 28));
        lineEdit_4->setFont(font);
        lineEdit_4->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 280, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #004AAD; /* Bleu */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #003580; /* Bleu fonc\303\251 au survol */\n"
"}\n"
""));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(330, 130, 161, 41));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #F3F5F8;  /* Fond gris clair */\n"
"    color: #333333;             /* Texte fonc\303\251 */\n"
"    font-size: 14px;\n"
"    border: 2px solid #004AAD;  /* Bordure bleue */\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
""));
        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(330, 180, 161, 41));
        textEdit_2->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #F3F5F8;  /* Fond gris clair */\n"
"    color: #333333;             /* Texte fonc\303\251 */\n"
"    font-size: 14px;\n"
"    border: 2px solid #004AAD;  /* Bordure bleue */\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
""));
        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(330, 240, 110, 29));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(180, 340, 113, 28));
        lineEdit_5->setFont(font);
        lineEdit_5->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(330, 340, 161, 85));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 50, 391, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        font1.setStrikeOut(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(260, 450, 83, 29));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(360, 450, 83, 29));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(-30, 0, 161, 101));
        label_9->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/logo app.png")));
        label_9->setScaledContents(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-20, 0, 811, 511));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/back.jpg")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(240, 50, 341, 41));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(true);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("c"));
        lineEdit_6 = new QLineEdit(tab_2);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(170, 160, 113, 28));
        lineEdit_6->setFont(font);
        lineEdit_6->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        textEdit_3 = new QTextEdit(tab_2);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(260, 150, 201, 41));
        textEdit_3->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #F3F5F8;  /* Fond gris clair */\n"
"    color: #333333;             /* Texte fonc\303\251 */\n"
"    font-size: 14px;\n"
"    border: 2px solid #004AAD;  /* Bordure bleue */\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
""));
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(270, 220, 83, 29));
        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(370, 220, 83, 29));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(-30, 0, 161, 101));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/logo app.png")));
        label_10->setScaledContents(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label_5 = new QLabel(tab_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(-10, 0, 801, 521));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/back.jpg")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(tab_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(260, 50, 261, 31));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("c"));
        lineEdit_7 = new QLineEdit(tab_3);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(150, 150, 113, 28));
        lineEdit_7->setFont(font);
        lineEdit_7->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        textEdit_4 = new QTextEdit(tab_3);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(290, 150, 181, 31));
        lineEdit_8 = new QLineEdit(tab_3);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(150, 190, 131, 28));
        lineEdit_8->setFont(font);
        lineEdit_8->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        textEdit_5 = new QTextEdit(tab_3);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(290, 190, 181, 31));
        QFont font3;
        font3.setPointSize(9);
        textEdit_5->setFont(font3);
        lineEdit_9 = new QLineEdit(tab_3);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(150, 230, 131, 28));
        lineEdit_9->setFont(font);
        lineEdit_9->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        textEdit_6 = new QTextEdit(tab_3);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(290, 230, 181, 31));
        lineEdit_10 = new QLineEdit(tab_3);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(150, 330, 151, 28));
        lineEdit_10->setFont(font);
        lineEdit_10->setAutoFillBackground(false);
        lineEdit_10->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(290, 320, 181, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #004AAD; /* Bleu */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #003580; /* Bleu fonc\303\251 au survol */\n"
"}\n"
""));
        lineEdit_11 = new QLineEdit(tab_3);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(150, 280, 151, 28));
        lineEdit_11->setFont(font);
        lineEdit_11->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        dateEdit_2 = new QDateEdit(tab_3);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(300, 280, 110, 29));
        lineEdit_12 = new QLineEdit(tab_3);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(150, 380, 113, 28));
        lineEdit_12->setFont(font);
        lineEdit_12->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        plainTextEdit_2 = new QPlainTextEdit(tab_3);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(290, 380, 171, 61));
        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(220, 460, 83, 29));
        pushButton_8 = new QPushButton(tab_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(330, 460, 83, 29));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(-30, 0, 161, 91));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/logo app.png")));
        label_11->setScaledContents(true);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_7 = new QLabel(tab_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 0, 791, 521));
        label_7->setFont(font3);
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/back.jpg")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(tab_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(230, 40, 291, 41));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("c"));
        lineEdit_13 = new QLineEdit(tab_4);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(200, 140, 113, 28));
        lineEdit_13->setFont(font);
        lineEdit_13->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;\n"
"color: white; /* Change la couleur du texte si n\303\251cessaire */\n"
""));
        plainTextEdit_3 = new QPlainTextEdit(tab_4);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(270, 140, 171, 31));
        pushButton_9 = new QPushButton(tab_4);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(320, 220, 83, 29));
        tabWidget->addTab(tab_4, QString());
        MainWindowCrud->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowCrud);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindowCrud->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowCrud);
        statusbar->setObjectName("statusbar");
        MainWindowCrud->setStatusBar(statusbar);

        retranslateUi(MainWindowCrud);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowCrud);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowCrud)
    {
        MainWindowCrud->setWindowTitle(QCoreApplication::translate("MainWindowCrud", "MainWindowCrud", nullptr));
        label->setText(QString());
        lineEdit->setText(QCoreApplication::translate("MainWindowCrud", "Nom de plan:", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindowCrud", "Type de plan:", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindowCrud", "Date de creation:", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindowCrud", "Image de plan:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowCrud", "Exporter Image", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "Nom", nullptr));
        textEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "Type", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindowCrud", "Description:", nullptr));
        plainTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "Description de plan", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowCrud", "Ajouter un nouveau plan ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindowCrud", "Ajouter", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindowCrud", "Annuler", nullptr));
        label_9->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindowCrud", "Create", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindowCrud", "Afficher un plan", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindowCrud", "Id de plan:", nullptr));
        textEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "Id de plan", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindowCrud", "Chercher", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindowCrud", "Annuler", nullptr));
        label_10->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindowCrud", "Read", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindowCrud", "Modifier un plan", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindowCrud", "Id :", nullptr));
        textEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "id de plan", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("MainWindowCrud", "Nouveau nom :", nullptr));
        textEdit_5->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "nom de plan", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("MainWindowCrud", "Nouveau Type :", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "background: transparent;\\nborder: none;\\ncolor: white; /* Change la couleur du texte si n\303\251cessaire */\\n", nullptr));
        textEdit_6->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "Type de plan", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindowCrud", "Nouveau Image :", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindowCrud", "Exporter une image", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindowCrud", "Date de cr\303\251ation :", nullptr));
        lineEdit_12->setText(QCoreApplication::translate("MainWindowCrud", "Description :", nullptr));
        plainTextEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "Description de la plan", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindowCrud", "Modifier", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindowCrud", "Annuler", nullptr));
        label_11->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindowCrud", "Update", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindowCrud", "Supprimer un plan", nullptr));
        lineEdit_13->setText(QCoreApplication::translate("MainWindowCrud", "Id :", nullptr));
        plainTextEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindowCrud", "id de plan", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindowCrud", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindowCrud", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowCrud: public Ui_MainWindowCrud {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
