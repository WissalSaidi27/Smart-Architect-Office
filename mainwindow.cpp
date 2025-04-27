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
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QPen>
#include <QRandomGenerator>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QBrush>
#include "floorplangenerator.h"
#include <QStandardPaths>
#include <QSerialPortInfo>
#include <QSqlQuery>
#include <QSerialPort>

QSerialPort *serial;

MainWindowCrud::MainWindowCrud(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowCrud)

{
    ui->setupUi(this);


    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindowCrud::on_generateButton_clicked);
    QPixmap logo(":/Images/Images/logo_app.png");
    ui->labelLogo->setPixmap(logo);
    ui->labelLogo->setScaledContents(true);
    ui->labelLogo_2->setPixmap(logo);
    ui->labelLogo_2->setScaledContents(true);
    ui->labelLogo_3->setPixmap(logo);
    ui->labelLogo_3->setScaledContents(true);
    ui->labelLogo_4->setPixmap(logo);
    ui->labelLogo_4->setScaledContents(true);
    ui->labelLogo_5->setPixmap(logo);
    ui->labelLogo_5->setScaledContents(true);

    serial = new QSerialPort(this);

    // ⚡ Sélectionner le bon port COM
    serial->setPortName("COM3"); // Attention : METS le bon COM de ton Arduino !

    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {
        connect(serial, &QSerialPort::readyRead, this, &MainWindowCrud::readSerialData);
        qDebug() << "Connexion Arduino réussie!";
    } else {
        qDebug() << "Erreur ouverture Arduino:" << serial->errorString();
    }





}
MainWindowCrud::~MainWindowCrud()
{
    if (serial->isOpen()){
        serial->close();
    }

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
    QString photo = ui->label_12->text();
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
//button tri
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
//zone recherche
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
//fonction pdf
void MainWindowCrud::exporterPDF_Plan() {
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();
    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");
    QString logoPath = "C:/Users/21692/OneDrive/Pictures/logo_app.png";


    out << "<html>\n"
           "<head>\n"
           "<meta charset='UTF-8'>\n"
           "<title>Exportation PDF</title>\n"
           "<style>"
           "body { font-family: 'Segoe UI', sans-serif; }"
           "table { border-collapse: collapse; width: 90%; margin: auto; }"
           "th, td { border: 1px solid #000000; padding: 8px; text-align: center; }"
           "th { background-color: #02315b; color: white; }"
           "h1 { color: #02315b; }"
           "</style>\n"
           "</head>\n"
           "<body>\n";

    // Header avec logo
    out << "<div style='width: 100%; display: flex; justify-content: space-between; align-items: center;'>"
           "<div style='flex: 1;'>"
           "<img src='" + logoPath + "' width='150' height='150' alt='Logo'>"
                            "</div>"
                            "<div style='text-align: right; font-size: 12px; color: #555;'>"
                            "<p style='margin: 0;'>Date : " << currentDate << "</p>"
                          "<p style='margin: 0;'>Document: Liste des Plans</p>"
                          "</div>"
                          "</div>"
                          "<hr style='margin-top: 10px; margin-bottom: 10px;'>";


    out << "<h1 style='text-align:center;'>Liste des Plans</h1><br>";
    out << "<table>\n";
    out << "<thead><tr><th>#</th>";

    for (int column = 0; column < columnCount; column++) {
        if (!ui->tableView->isColumnHidden(column)) {
            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";

    for (int row = 0; row < rowCount; row++) {
        out << "<tr><td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView->isColumnHidden(column)) {
                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                out << QString("<td>%1</td>").arg(!data.isEmpty() ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }

    out << "</table>\n";
    out << "<br><br><div style='text-align: right; padding-right: 60px;'>"
           "<p>Signature responsable</p><br><br>"
           "______________________________"
           "</div>";
    out << "</body></html>";

    QString fileName = QFileDialog::getSaveFileName(nullptr, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) fileName.append(".pdf");

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(10, 10, 10, 10)); // marges en mm


    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
}



//button pdf
void MainWindowCrud::on_pushButton_10_clicked() {
    exporterPDF_Plan();
}
//fonction stat
void MainWindowCrud::afficherStatistiquesPlans() {
    plan p;
    QMap<QString, int> stats = p.statistiquesPlans();

    if (stats.isEmpty()) {
        QMessageBox::warning(this, "Statistiques", "Aucune donnée à afficher !");
        return;
    }

    QPieSeries *series = new QPieSeries();
    int total = 0;

    // D'abord calculer le total
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        total += it.value();
    }

    // Ajouter les parts avec labels contenant le pourcentage
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        qreal percentage = (static_cast<qreal>(it.value()) / total) * 100.0;
        QString label = QString("%1 (%2%)").arg(it.key()).arg(QString::number(percentage, 'f', 1));
        QPieSlice *slice = series->append(label, it.value());
        slice->setLabelVisible(true);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des plans par type");
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 400);
    chartView->show();
}

//button stat
void MainWindowCrud::on_pushButton_11_clicked() {
    afficherStatistiquesPlans();
}





void MainWindowCrud::on_generateButton_clicked()
{
    FloorPlanGenerator *gen = new FloorPlanGenerator(this);

    // Connecter les widgets de l'interface Qt Designer
    gen->planTypeCombo = ui->planTypeCombo;
    gen->widthSpinBox = ui->widthSpinBox;
    gen->heightSpinBox = ui->heightSpinBox;
    gen->roomCountSpinBox = ui->roomCountSpinBox;
    gen->view = ui->View;

    // Créer une nouvelle scène et l'afficher dans la vue
    gen->scene = new QGraphicsScene(this);
    ui->View->setScene(gen->scene);


    gen->generateFloorPlan();


}
void MainWindowCrud::sendResponseToArduino(const QString &message)
{
    serial->write(message.toUtf8() + "\n");
    qDebug() << "Message envoyé à l'Arduino : " << message;
}


QString MainWindowCrud::getEmployeeNameByUID(const QString &uid)
{
    QSqlQuery query;
    query.prepare("SELECT prenom FROM employe WHERE mot_de_passe = :uid");
    query.bindValue(":uid", uid);
    if (query.exec() && query.next()) {
        return query.value(0).toString();  // Retourne le nom de l'employé
    } else {
        return QString();  // UID non trouvé
    }
}
void MainWindowCrud::readSerialData()
{
    QByteArray data = serial->readAll();
    QString uid = QString::fromUtf8(data).trimmed();
    qDebug() << "UID reçu : " << uid;

    // Rechercher le nom de l'employé dans la base de données
    QString employeeName = getEmployeeNameByUID(uid);
    if (!employeeName.isEmpty()) {
    sendResponseToArduino("WELCOME:" + employeeName);
    } else {
        sendResponseToArduino("DENIED");
    }
}






