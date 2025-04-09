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

MainWindowCrud::MainWindowCrud(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowCrud)

{
    ui->setupUi(this);

    // Lier le bouton "Générer" à la fonction `genererPlan`

    //connect(ui->pushButton_generer_2D, &QPushButton::clicked, this, &MainWindowCrud::genererPlan2D);
    // Dans le constructeur de ta classe principale
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindowCrud::on_generateButton_clicked);





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
//button stat
void MainWindowCrud::on_pushButton_11_clicked() {
    afficherStatistiquesPlans();
}



// Fonction pour générer la visualisation 2D du plan
/*void MainWindowCrud::genererPlan2D() {
    int longueur = ui->lineEdit_longueur->text().toInt();
    int largeur = ui->lineEdit_largeur->text().toInt();
    int nb_murs = ui->spinBox_nb_murs->value();
    int nb_portes = ui->spinBox_nb_portes->value();
    int nb_fenetres = ui->spinBox_nb_fenetres->value();

    if (longueur <= 0 || largeur <= 0) {
        QMessageBox::warning(this, "Erreur", "Les dimensions doivent être positives !");
        return;
    }

    // Création de la scène
    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView_2D->setScene(scene);

    // Échelle pour un meilleur rendu
    int scale = 50;

    // 🔹 Dessiner le cadre principal
    QPen pen(Qt::black);
    pen.setWidth(3);
    scene->addRect(0, 0, longueur * scale, largeur * scale, pen);

    // 🔹 Ajouter une grille (optionnel, améliore la précision)
    QPen gridPen(Qt::gray, 1, Qt::DashLine);
    for (int i = 0; i <= longueur; i++) {
        scene->addLine(i * scale, 0, i * scale, largeur * scale, gridPen);
    }
    for (int j = 0; j <= largeur; j++) {
        scene->addLine(0, j * scale, longueur * scale, j * scale, gridPen);
    }

    // 🔹 Ajouter des murs plus réalistes
    QPen murPen(Qt::darkGray);
    murPen.setWidth(6);
    for (int i = 0; i < nb_murs; i++) {
        int x = QRandomGenerator::global()->bounded(longueur - 2) * scale;
        int y = QRandomGenerator::global()->bounded(largeur - 2) * scale;
        scene->addRect(x, y, scale, scale / 4, murPen);
    }

    // 🔹 Ajouter des portes
    QPen portePen(Qt::blue);
    portePen.setWidth(4);
    for (int i = 0; i < nb_portes; i++) {
        int x = QRandomGenerator::global()->bounded(longueur) * scale;
        int y = 0;
        scene->addLine(x, y, x + scale / 2, y, portePen);
    }

    // 🔹 Ajouter des fenêtres
    QPen fenetrePen(Qt::cyan);
    fenetrePen.setWidth(3);
    for (int i = 0; i < nb_fenetres; i++) {
        int x = QRandomGenerator::global()->bounded(longueur) * scale;
        int y = largeur * scale;
        scene->addLine(x, y, x + scale / 2, y, fenetrePen);
    }

    // 🔹 Ajouter le texte des dimensions
    QGraphicsTextItem *dimText = scene->addText(QString("%1m x %2m").arg(longueur).arg(largeur));
    dimText->setDefaultTextColor(Qt::white);
    dimText->setFont(QFont("Arial", 14, QFont::Bold));
    dimText->setPos(longueur * scale / 2 - 20, largeur * scale + 10);
}
*/
/*void MainWindowCrud::genererPlan2D()
{
    // 📌 Récupération des valeurs saisies
    int longueur = ui->lineEdit_longueur->text().toInt();
    int largeur = ui->lineEdit_largeur->text().toInt();
    int nb_murs = ui->spinBox_nb_murs->value();
    int nb_portes = ui->spinBox_nb_portes->value();
    int nb_fenetres = ui->spinBox_nb_fenetres->value();

    // 📌 Vérification des dimensions minimales
    if (longueur < 50 || largeur < 50) {
        QMessageBox::warning(this, "Erreur", "Les dimensions doivent être supérieures à 50 !");
        return;
    }

    // 📌 Création de la scène
    if (!ui->graphicsView_2D->scene()) {
        ui->graphicsView_2D->setScene(new QGraphicsScene(this));
    }
    ui->graphicsView_2D->scene()->clear();

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView_2D->setScene(scene);

    // === 🏠 DESSIN DU PLAN PRINCIPAL (Cadre du plan) ===
    QRectF planRect(0, 0, longueur, largeur);
    QPen cadrePen(Qt::black, 3);
    scene->addRect(planRect, cadrePen);

    // === 🚧 AJOUT DES MURS (DÉPLAÇABLES) ===
    for (int i = 0; i < nb_murs; ++i) {
        int x = QRandomGenerator::global()->bounded(10, longueur - 50);
        int y = QRandomGenerator::global()->bounded(10, largeur - 50);
        int width = QRandomGenerator::global()->bounded(50, 150);
        int height = 8; // Épaisseur du mur

        PlanItem *mur = new PlanItem(x, y, width, height, Qt::darkGray);
        scene->addItem(mur);
    }

    // === 🚪 AJOUT DES PORTES (DÉPLAÇABLES) ===
    for (int i = 0; i < nb_portes; ++i) {
        int x = QRandomGenerator::global()->bounded(10, longueur - 50);
        int y = QRandomGenerator::global()->bounded(10, largeur - 50);

        PlanItem *porte = new PlanItem(x, y, 30, 5, QColor(139, 69, 19)); // Marron (brown)
        scene->addItem(porte);
    }

    // === 🪟 AJOUT DES FENÊTRES (DÉPLAÇABLES) ===
    for (int i = 0; i < nb_fenetres; ++i) {
        int x = QRandomGenerator::global()->bounded(10, longueur - 50);
        int y = QRandomGenerator::global()->bounded(10, largeur - 50);

        PlanItem *fenetre = new PlanItem(x, y, 40, 5, Qt::cyan);
        scene->addItem(fenetre);
    }

    // 📌 Ajuster la vue
    ui->graphicsView_2D->fitInView(planRect, Qt::KeepAspectRatio);
}

void MainWindowCrud::on_pushButton_generer_2D_clicked(){
    genererPlan2D();
}*/


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

    // Générer le plan (appel d'une méthode de génération, par exemple)
    gen->generateFloorPlan(); // Assure-toi que generatePlan() fait quelque chose ici

    // Il n'est pas nécessaire de faire appel à show() si on affiche déjà la scène
    // gen->show();
}


