#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plan.h"


#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QSequentialAnimationGroup>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSqlDatabase>




QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowCrud;
}
QT_END_NAMESPACE

class MainWindowCrud : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindowCrud(QWidget *parent = nullptr);


    ~MainWindowCrud();
private slots:
    void viderFormulaireAdd();

    void viderFormulaireUpdate();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_5_clicked();
    //void afficherPlans();
    void afficherPlansMod();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_lineEdit_6_textChanged(const QString &arg1);
    void exporterPDF_Plan();
    void on_pushButton_10_clicked();
    void afficherStatistiquesPlans();
    void on_pushButton_11_clicked();

    void on_generateButton_clicked();
    void readSerialData();
    void sendResponseToArduino(const QString &message);






private:
    Ui::MainWindowCrud *ui;
    //plan p;
    plan p;
    QSerialPort *serial;
    QSqlDatabase db;
    QString getEmployeeNameByUID(const QString &uid);



};


#endif // MAINWINDOW_H
