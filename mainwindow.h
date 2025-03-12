#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void viderFormulaireREAD();
    void viderFormulaireUpdate();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void afficherPlans();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();

private:
    Ui::MainWindowCrud *ui;
};

#endif // MAINWINDOW_H
