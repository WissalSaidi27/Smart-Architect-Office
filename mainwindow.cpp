#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "connection.h"
#include <QDebug>
#include <QMessageBox>
#include "plan.h"
#include <QFileDialog>




MainWindowCrud::MainWindowCrud(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowCrud)
{
    ui->setupUi(this);
}

MainWindowCrud::~MainWindowCrud()
{
    delete ui;
}
void MainWindowCrud::viderFormulaireAdd() {
    // Vider les champs manuellement
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->plainTextEdit->clear();
    ui->lineEdit_4->clear();

    // Réinitialiser la date au jour actuel
    ui->dateEdit->setDate(QDate::currentDate());
}
void MainWindowCrud::viderFormulaireREAD() {
    // Vider les champs manuellement
    ui->textEdit_3->clear();

}
void MainWindowCrud::viderFormulaireUpdate() {
    // Vider les champs manuellement
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
    ui->textEdit_6->clear();
    ui->lineEdit_10->clear();
    ui->plainTextEdit_2->clear();

    // Réinitialiser la date au jour actuel
    ui->dateEdit_2->setDate(QDate::currentDate());
}

void MainWindowCrud::on_pushButton_clicked() {
    qDebug()<<"Buton exporter image cliqué";
    // 🔹 Ouvrir une boîte de dialogue pour choisir une image
    QString cheminImage = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!cheminImage.isEmpty()) {
        // 🔹 Afficher le chemin dans le QLineEdit, mais NE PAS EXÉCUTER LA REQUÊTE SQL !
        ui->lineEdit_4->setText(cheminImage);
    } else {
        qDebug()<<"chemin sélectionné :"<< cheminImage;
        QMessageBox::warning(this, "Aucune image", "Aucune image sélectionnée.");
    }
}

void MainWindowCrud::on_pushButton_2_clicked() {
    // 🔹 Récupérer les valeurs des champs de l'interface
    int id = ui->textEdit->toPlainText().toInt();  // ID du plan
    QString nom = ui->textEdit->toPlainText();   // Nom du plan
    QString type = ui->textEdit_2->toPlainText();  // Type du plan
    QString description = ui->plainTextEdit->toPlainText(); // Description
    QString photo = ui->lineEdit_4->text();  // Lien vers la photo
    QDate date_creation = ui->dateEdit->date();  // Date de création

    // 🔹 Créer un objet Plan avec les données récupérées
    plan p(id ,nom, type, description, photo, date_creation);

    // 🔹 Ajouter le plan à la base de données
    if (p.ajouter()) {
        QMessageBox::information(this, "Succès", "Le plan a été ajouté !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du plan !");
    }
}
void MainWindowCrud::on_pushButton_3_clicked() {
    viderFormulaireAdd();
}

void MainWindowCrud::on_pushButton_4_clicked() {
    plan p;
    int id = ui->textEdit_3->toPlainText().toInt();  // Récupérer l'ID entré par l'utilisateur

    if (id == 0) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un ID valide !");
        return;
    }

    QSqlQueryModel* model = p.chercher(id);

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Résultat", "Aucun plan trouvé avec cet ID !");
    } else {
        ui->tableView->setModel(model);  // Afficher le plan trouvé
    }
}
void MainWindowCrud::on_pushButton_5_clicked() {
    viderFormulaireREAD();
}

void MainWindowCrud::afficherPlans() {
    plan p;
    QSqlQueryModel* model = p.afficher();  // `p` est un objet de type `plan`
    ui->tableView_2->setModel(model);  // Associer le modèle au QTableView
}
void MainWindowCrud::on_pushButton_6_clicked() {
    qDebug()<<"Buton exporter image cliqué";
    // 🔹 Ouvrir une boîte de dialogue pour choisir une image
    QString cheminImage = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!cheminImage.isEmpty()) {
        // 🔹 Afficher le chemin dans le QLineEdit, mais NE PAS EXÉCUTER LA REQUÊTE SQL !
        ui->lineEdit_4->setText(cheminImage);
    } else {
        qDebug()<<"chemin sélectionné :"<< cheminImage;
        QMessageBox::warning(this, "Aucune image", "Aucune image sélectionnée.");
    }
}

void MainWindowCrud::on_pushButton_7_clicked() {
    int id = ui->textEdit_4->toPlainText().toInt();
    QString nom = ui->textEdit_5->toPlainText();
    QString type = ui->textEdit_6->toPlainText();
    QString description = ui->plainTextEdit_2->toPlainText();
    QString photo = ui->lineEdit_10->text();
    QDate date_creation = ui->dateEdit_2->date();
    qDebug() << "Date récupérée :" << date_creation.toString("yyyy-MM-dd");
    // Vérifier si l'ID est valide
    if (id == 0 ) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un ID valide !");
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM plan WHERE id_plan = :id_plan");
    query.bindValue(":id_plan", id);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la vérification de l'existence du plan:" << query.lastError().text();
        return;
    }


    if (query.next()) {
    int count = query.value(0).toInt();
    // Si l'ID n'existe pas dans la base de données
    if (count == 0) {
        QMessageBox::warning(this, "Attention", "Cet ID n'existe pas dans la base de données !");
        return;
    }
    }else{
        qDebug() << "Erreur: Aucun résultat retourné pour la vérification de l'ID.";
        return;

    }
    // Créer un objet `plan` avec les nouvelles valeurs
    plan p(id ,nom, type, description, photo, date_creation);
    // Modifier le plan en base de données
    if (p.modifier(id)) {
        QMessageBox::information(this, "Succès", "Le plan a été modifié !");
        afficherPlans();  // Mettre à jour la table après la modification
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du plan !");
    }
}
void MainWindowCrud::on_pushButton_8_clicked() {
    viderFormulaireUpdate();
}
void MainWindowCrud::on_pushButton_9_clicked() {
    // Récupérer l'ID du plan à supprimer depuis l'interface (par exemple, un champ de texte)
    int id_plan = ui->plainTextEdit_3->toPlainText().toInt();

    // Vérifier si l'ID est valide
    if (id_plan == 0) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un ID valide pour supprimer !");
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM plan WHERE id_plan = :id_plan");
    query.bindValue(":id_plan", id_plan);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la vérification de l'existence du plan:" << query.lastError().text();
        return;
    }

    query.next();
    if (query.value(0).toInt() == 0) {
        // Si l'ID n'existe pas
        QMessageBox::warning(this, "Erreur", "Cet ID n'existe pas dans la base de données !");
        return;
    }

    // Créer un objet plan et appeler la méthode de suppression
    plan p;
    if (p.supprimer(id_plan)) {
        QMessageBox::information(this, "Succès", "Le plan a été supprimé !");
        afficherPlans();  // Mettre à jour l'affichage des plans après la suppression
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du plan !");
    }
}



