#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterClient_clicked();

    void on_updateClient_clicked();

    void on_deleteclient_clicked();
    void display();
    void clear();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
