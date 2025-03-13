// login.h
#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_login_clicked();  // Connexion
    void ouvrirInscription();           // Déclaration du slot pour ouvrir la page d'inscription

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
