#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "connection.h"
#include <QDebug>
#include <QMessageBox>
#include "plan.h"
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>



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

// anuller fonction ajouter
void MainWindowCrud::viderFormulaireAdd() {
    ui->textEdit->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->plainTextEdit->clear();
    ui->label_ch->clear();

    ui->dateEdit->setDate(QDate::currentDate());
}


//annuler fonction modifier
void MainWindowCrud::viderFormulaireUpdate() {
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
    ui->comboBox_2->setCurrentIndex(0);
    ui->label_12->clear();
    ui->plainTextEdit_2->clear();

    ui->dateEdit_2->setDate(QDate::currentDate());
}
//button telecharger image(ajout)
void MainWindowCrud::on_pushButton_clicked() {
    qDebug()<<"Buton exporter image cliqué";
    QString cheminImage = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!cheminImage.isEmpty()) {
        ui->label_ch->setText(cheminImage);
    } else {
        qDebug()<<"chemin sélectionné :"<< cheminImage;
        QMessageBox::warning(this, "Aucune image", "Aucune image sélectionnée.");
    }
}
//button ajouter
void MainWindowCrud::on_pushButton_2_clicked() {

    int id = ui->textEdit->toPlainText().toInt();
    QString nom = ui->textEdit->toPlainText();
    QString type = ui->comboBox->currentText();
    QString description = ui->plainTextEdit->toPlainText();
    QString photo = ui->lineEdit_4->text();
    QDate date_creation = ui->dateEdit->date();

    //objet Plan
    plan p(id ,nom, type, description, photo, date_creation);
    if (nom.isEmpty() ||type.isEmpty() || description.isEmpty() || photo.isEmpty()){
        QMessageBox::critical(this, "Attention", "il y'a un champ vide!");
        return;
    }
    if (!date_creation.isValid() || date_creation > QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date de création doit être inférieure ou égale à aujourd'hui !");
        return;
    }
    if (p.ajouter()) {
        QMessageBox::information(this, "Succès", "Le plan a été ajouté !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du plan !");
    }
}
//button annuler ajouter
void MainWindowCrud::on_pushButton_3_clicked() {
    viderFormulaireAdd();
}

//interface afficher
void MainWindowCrud::on_pushButton_4_clicked() {
    plan p;
    QSqlQueryModel* model = p.afficher_Plan();

    if (model) {
        ui->tableView->setModel(model);  // 🔹 Associer le modèle à la tableView
        qDebug() << "✅ TableView mis à jour avec" << model->rowCount() << " plans.";
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les plans !");
    }
}




//fonction afficher les plan a modifer
void MainWindowCrud::afficherPlansMod() {
    plan p;
    QSqlQueryModel* model = p.afficher();
    ui->tableView_2->setModel(model);
}
//button télecharger image (modifier)
void MainWindowCrud::on_pushButton_6_clicked() {
    qDebug()<<"Buton exporter image cliqué";
    QString cheminImage = QFileDialog::getOpenFileName(this, "Choisir une image", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!cheminImage.isEmpty()) {
        ui->label_12->setText(cheminImage);
    } else {
        qDebug()<<"chemin sélectionné :"<< cheminImage;
        QMessageBox::warning(this, "Aucune image", "Aucune image sélectionnée.");
    }
}
//button modifier
void MainWindowCrud::on_pushButton_7_clicked() {
    int id = ui->textEdit_4->toPlainText().toInt();
    QString nom = ui->textEdit_5->toPlainText();
    QString type = ui->comboBox_2->currentText();
    QString description = ui->plainTextEdit_2->toPlainText();
    QString photo = ui->lineEdit_10->text();
    QDate date_creation = ui->dateEdit_2->date();
    qDebug() << "Date récupérée :" << date_creation.toString("yyyy-MM-dd");
    // Vérifier si l'ID est valide
    if (id == 0 ) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un ID valide !");
        return;
    }
    if (nom.isEmpty() ||type.isEmpty() || description.isEmpty() || photo.isEmpty()){
        QMessageBox::critical(this, "Attention", "il y'a un champ vide!");
        return;
    }
    if (!date_creation.isValid() || date_creation > QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date de création doit être inférieure ou égale à aujourd'hui !");
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
    plan p(id ,nom, type, description, photo, date_creation);
    if (p.modifier(id)) {
        QMessageBox::information(this, "Succès", "Le plan a été modifié !");
        afficherPlansMod();  // Mettre à jour la table après la modification
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du plan !");
    }
}
//button annuler modifier
void MainWindowCrud::on_pushButton_8_clicked() {
    viderFormulaireUpdate();
}
//button supprimer
void MainWindowCrud::on_pushButton_9_clicked() {
    int id_plan = ui->plainTextEdit_3->toPlainText().toInt();

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
    plan p;
    if (p.supprimer(id_plan)) {
        QMessageBox::information(this, "Succès", "Le plan a été supprimé !");

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du plan !");
    }
}
void MainWindowCrud::on_pushButton_5_clicked() {
        plan p;

        // Récupérer le critère de tri (nom de la colonne)
        QString critere = ui->comboBox_3->currentText();

        // Récupérer l'ordre de tri (ASC ou DESC)
        QString mode;
        if (ui->radioButton->isChecked()) {
            mode = "ASC";
        } else if (ui->radioButton_2->isChecked()) {
            mode = "DESC";
        }
        ui->tableView->setModel(p.trier(critere, mode));
    }
void MainWindowCrud::on_lineEdit_6_textChanged(const QString &arg1)
{
    plan p;
    if (arg1.isEmpty())  // ✅ Vérification correcte
    {
        ui->tableView->setModel(p.afficher());
    }
    else
    {
        ui->tableView->setModel(p.rechercher(arg1));
    }
}
void MainWindowCrud::exporterPDF_Plan() {

        /* QPrinter printer;
    printer.setPrinterName ("le nom de l'imprimante");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec()== QDialog::Rejected)return;
    ui->tableView->render(&printer);*/

        QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();
        QString TT = QDate::currentDate().toString("yyyy/MM/dd");

        out <<  "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"

               //     "<align='right'> " << datefich << "</align>"



               "<center> <H1>Liste des Plans</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView->isColumnHidden(column)) {
                    QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));


                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n";
        out << "<tr>\n"

               "</body>\n"
               "</html>\n";

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter *printer=new  QPrinter(QPrinter::PrinterResolution);
        printer->setOutputFormat(QPrinter::PdfFormat);
        printer->setPageSize(QPageSize(QPageSize::A4));
        printer->setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        //doc.setPageSize(printer->pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(printer);

        QPrinter *p=new QPrinter();
        QPrintDialog dialog(p,this);
        if(dialog.exec()== QDialog::Rejected)
        {
            return;
        }

    }

void MainWindowCrud::on_pushButton_10_clicked() {
    exporterPDF_Plan();
}
void MainWindowCrud::afficherStatistiquesPlans() {
    plan p;
    QMap<QString, int> stats = p.statistiquesPlans();

    if (stats.isEmpty()) {
        QMessageBox::warning(this, "Statistiques", "Aucune donnée à afficher !");
        return;
    }

    QPieSeries *series = new QPieSeries();
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        series->append(it.key(), it.value());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des plans par type");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 400);
    chartView->show();
}
void MainWindowCrud::on_pushButton_11_clicked() {
    afficherStatistiquesPlans();
}

