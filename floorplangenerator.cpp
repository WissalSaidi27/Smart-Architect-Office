#include "FloorPlanGenerator.h"
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QGroupBox>
#include <QMessageBox>
#include <QPixmap>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>


FloorPlanGenerator::~FloorPlanGenerator()
{
    // Cleanup if needed
}
FloorPlanGenerator::FloorPlanGenerator(QWidget *parent)
    : QDialog(parent)
{
    // Lier les éléments de l'interface UI à ceux existants
    planTypeCombo = parent->findChild<QComboBox*>("planTypeCombo");
    widthSpinBox = parent->findChild<QSpinBox*>("widthSpinBox");
    heightSpinBox = parent->findChild<QSpinBox*>("heightSpinBox");
    roomCountSpinBox = parent->findChild<QSpinBox*>("roomCountSpinBox");
    generateButton = parent->findChild<QPushButton*>("generateButton");
    saveButton = parent->findChild<QPushButton*>("saveButton");
    view = parent->findChild<QGraphicsView*>("View");

    scene = new QGraphicsScene(this);
    if (view) {
        view->setScene(scene);
    }

    createConnections();
}

void FloorPlanGenerator::createConnections()
{
    connect(planTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &FloorPlanGenerator::onPlanTypeChanged);
    connect(generateButton, &QPushButton::clicked, this, &FloorPlanGenerator::generateFloorPlan);
    connect(saveButton, &QPushButton::clicked, this, &FloorPlanGenerator::savePlan);
}
void FloorPlanGenerator::generateFloorPlan()
{
    scene->clear();

    // Récupérer les paramètres
    QString planType = planTypeCombo->currentText();
    int width = widthSpinBox->value() * 30; // Conversion en pixels (échelle)
    int height = heightSpinBox->value() * 30;
    int roomCount = roomCountSpinBox->value();

    // Génération des murs extérieurs
    drawOuterWalls(width, height);

    // Génération des pièces en fonction du type de plan
    QVector<Room> rooms;

    if (planType == "Maison") {
        generateHousePlan(width, height, roomCount, rooms);
    } else if (planType == "Bureau") {
        generateOfficePlan(width, height, roomCount, rooms);
    } else if (planType == "Appartement") {
        generateApartmentPlan(width, height, roomCount, rooms);
    } else if (planType == "Restaurant") {
        generateRestaurantPlan(width, height, roomCount, rooms);
    } else if (planType == "Magasin") {
        generateStorePlan(width, height, roomCount, rooms);
    }

    // Dessin des pièces
    for (const Room &room : rooms) {
        drawRoom(room);
    }


    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    saveButton->setEnabled(true);
}

void FloorPlanGenerator::savePlan()
{
     QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Sauvegarder le Plan",
                                                    QString(),
                                                    "Images (*.png *.jpg )");

    if (fileName.isEmpty()) {
        return;
    }


        QPixmap pixmap(scene->sceneRect().size().toSize());
        pixmap.fill(Qt::white);

        QPainter painter(&pixmap);
        painter.setRenderHint(QPainter::Antialiasing);
        scene->render(&painter);
        painter.end();

        pixmap.save(fileName);


    QMessageBox::information(this, "Sauvegarde", "Plan sauvegardé avec succès!");
}

void FloorPlanGenerator::onPlanTypeChanged(int index)
{
    QString planType = planTypeCombo->itemText(index);

    // Ajuster les contrôles en fonction du type de plan
    if (planType == "Maison") {
        roomCountSpinBox->setRange(3, 8);
        roomCountSpinBox->setValue(4);
    } else if (planType == "Bureau") {
        roomCountSpinBox->setRange(2, 12);
        roomCountSpinBox->setValue(6);
    } else if (planType == "Appartement") {
        roomCountSpinBox->setRange(2, 6);
        roomCountSpinBox->setValue(3);
    } else if (planType == "Restaurant") {
        roomCountSpinBox->setRange(2, 5);
        roomCountSpinBox->setValue(3);
    } else if (planType == "Magasin") {
        roomCountSpinBox->setRange(1, 4);
        roomCountSpinBox->setValue(2);
    }
}

void FloorPlanGenerator::drawOuterWalls(int width, int height)
{
    QPen wallPen(Qt::darkGray, 3);

    // Murs extérieurs
    QGraphicsRectItem *outerWalls = scene->addRect(0, 0, width, height, wallPen);
    outerWalls->setPos(0, 0);
}

void FloorPlanGenerator::drawRoom(const Room &room)
{
    // Murs de la pièce
    QPen wallPen(Qt::darkGray, 2);
    QGraphicsRectItem *roomItem = scene->addRect(room.x, room.y, room.width, room.height, wallPen);

    // Nom de la pièce
    QGraphicsTextItem *roomText = scene->addText(room.name);
    roomText->setPos(room.x + room.width/2 - roomText->boundingRect().width()/2,
                     room.y + room.height/2 - roomText->boundingRect().height()/2);

    // Porte si nécessaire
    if (room.hasDoor) {
        QPen doorPen(Qt::black, 1);
        int doorWidth = 20;
        double doorX = room.x;
        double doorY = room.y;

        switch (room.doorPosition) {
        case 0: // Nord
            doorX = room.x + room.width/2 - doorWidth/2;
            doorY = room.y;
            scene->addLine(doorX, doorY, doorX + doorWidth, doorY, doorPen);
            break;
        case 1: // Est
            doorX = room.x + room.width;
            doorY = room.y + room.height/2 - doorWidth/2;
            scene->addLine(doorX, doorY, doorX, doorY + doorWidth, doorPen);
            break;
        case 2: // Sud
            doorX = room.x + room.width/2 - doorWidth/2;
            doorY = room.y + room.height;
            scene->addLine(doorX, doorY, doorX + doorWidth, doorY, doorPen);
            break;
        case 3: // Ouest
            doorX = room.x;
            doorY = room.y + room.height/2 - doorWidth/2;
            scene->addLine(doorX, doorY, doorX, doorY + doorWidth, doorPen);
            break;
        }
    }
}

//maison
void FloorPlanGenerator::generateHousePlan(int width, int height, int roomCount, QVector<Room> &rooms)
{
    // Salon
    Room livingRoom;
    livingRoom.name = "Salon";
    livingRoom.x = width * 0.05;
    livingRoom.y = height * 0.05;
    livingRoom.width = width * 0.5;
    livingRoom.height = height * 0.4;
    livingRoom.hasDoor = true;
    livingRoom.doorPosition = 2;
    rooms.append(livingRoom);

    // Cuisine
    Room kitchen;
    kitchen.name = "Cuisine";
    kitchen.x = width * 0.6;
    kitchen.y = height * 0.05;
    kitchen.width = width * 0.35;
    kitchen.height = height * 0.25;
    kitchen.hasDoor = true;
    kitchen.doorPosition = 3;
    rooms.append(kitchen);

    // Distribution des autres pièces en fonction du nombre demandé
    if (roomCount >= 3) {
        // Chambre principale
        Room masterBedroom;
        masterBedroom.name = "Chambre";
        masterBedroom.x = width * 0.05;
        masterBedroom.y = height * 0.5;
        masterBedroom.width = width * 0.4;
        masterBedroom.height = height * 0.45;
        masterBedroom.hasDoor = true;
        masterBedroom.doorPosition = 0;
        rooms.append(masterBedroom);
    }

    if (roomCount >= 4) {
        // Salle de bain
        Room bathroom;
        bathroom.name = "SdB";
        bathroom.x = width * 0.5;
        bathroom.y = height * 0.5;
        bathroom.width = width * 0.2;
        bathroom.height = height * 0.25;
        bathroom.hasDoor = true;
        bathroom.doorPosition = 0;
        rooms.append(bathroom);
    }

    if (roomCount >= 5) {
        // Chambre 2
        Room bedroom2;
        bedroom2.name = "Chambre 2";
        bedroom2.x = width * 0.75;
        bedroom2.y = height * 0.35;
        bedroom2.width = width * 0.2;
        bedroom2.height = height * 0.3;
        bedroom2.hasDoor = true;
        bedroom2.doorPosition = 3;
        rooms.append(bedroom2);
    }

    if (roomCount >= 6) {
        // Bureau
        Room office;
        office.name = "Bureau";
        office.x = width * 0.75;
        office.y = height * 0.7;
        office.width = width * 0.2;
        office.height = height * 0.25;
        office.hasDoor = true;
        office.doorPosition = 0;
        rooms.append(office);
    }


}
//office
void FloorPlanGenerator::generateOfficePlan(int width, int height, int roomCount, QVector<Room> &rooms)
{
    // Réception
    Room reception;
    reception.name = "Réception";
    reception.x = width * 0.05;
    reception.y = height * 0.05;
    reception.width = width * 0.25;
    reception.height = height * 0.3;
    reception.hasDoor = true;
    reception.doorPosition = 2;
    rooms.append(reception);

    // Espace ouvert
    Room openSpace;
    openSpace.name = "Open Space";
    openSpace.x = width * 0.35;
    openSpace.y = height * 0.05;
    openSpace.width = width * 0.6;
    openSpace.height = height * 0.45;
    openSpace.hasDoor = true;
    openSpace.doorPosition = 3;
    rooms.append(openSpace);

    // Distribution du reste des pièces
    int remainingRooms = roomCount - 2;
    double roomWidth = width * 0.25;
    double roomHeight = height * 0.2;
    double startX = width * 0.05;
    double startY = height * 0.4;

    for (int i = 0; i < remainingRooms && i < 10; i++) {
        Room office;
        office.name = "Bureau " + QString::number(i + 1);

        int row = i / 3;
        int col = i % 3;

        office.x = startX + col * (roomWidth + 5);
        office.y = startY + row * (roomHeight + 5);
        office.width = roomWidth;
        office.height = roomHeight;
        office.hasDoor = true;
        office.doorPosition = (i % 4);

        rooms.append(office);
    }



}
//appartement
void FloorPlanGenerator::generateApartmentPlan(int width, int height, int roomCount, QVector<Room> &rooms)
{
    // Entrée et espace de vie principal
    Room livingArea;
    livingArea.name = "Séjour";
    livingArea.x = width * 0.05;
    livingArea.y = height * 0.05;
    livingArea.width = width * 0.6;
    livingArea.height = height * 0.4;
    livingArea.hasDoor = true;
    livingArea.doorPosition = 0;
    rooms.append(livingArea);

    // Cuisine
    Room kitchen;
    kitchen.name = "Cuisine";
    kitchen.x = width * 0.7;
    kitchen.y = height * 0.05;
    kitchen.width = width * 0.25;
    kitchen.height = height * 0.25;
    kitchen.hasDoor = true;
    kitchen.doorPosition = 3;
    rooms.append(kitchen);

    // Distribution des chambres et salle de bain
    if (roomCount >= 3) {
        // Chambre principale
        Room bedroom;
        bedroom.name = "Chambre";
        bedroom.x = width * 0.05;
        bedroom.y = height * 0.5;
        bedroom.width = width * 0.45;
        bedroom.height = height * 0.45;
        bedroom.hasDoor = true;
        bedroom.doorPosition = 0;
        rooms.append(bedroom);
    }

    if (roomCount >= 4) {
        // Salle de bain
        Room bathroom;
        bathroom.name = "SdB";
        bathroom.x = width * 0.55;
        bathroom.y = height * 0.5;
        bathroom.width = width * 0.2;
        bathroom.height = height * 0.2;
        bathroom.hasDoor = true;
        bathroom.doorPosition = 0;
        rooms.append(bathroom);
    }

    if (roomCount >= 5) {
        // WC séparé
        Room toilet;
        toilet.name = "WC";
        toilet.x = width * 0.8;
        toilet.y = height * 0.5;
        toilet.width = width * 0.15;
        toilet.height = height * 0.15;
        toilet.hasDoor = true;
        toilet.doorPosition = 0;
        rooms.append(toilet);
    }

    if (roomCount >= 6) {
        // Deuxième chambre
        Room bedroom2;
        bedroom2.name = "Ch. 2";
        bedroom2.x = width * 0.55;
        bedroom2.y = height * 0.75;
        bedroom2.width = width * 0.4;
        bedroom2.height = height * 0.2;
        bedroom2.hasDoor = true;
        bedroom2.doorPosition = 0;
        rooms.append(bedroom2);
    }



}
//Restaurant
void FloorPlanGenerator::generateRestaurantPlan(int width, int height, int roomCount, QVector<Room> &rooms)
{
    // Salle principale
    Room diningArea;
    diningArea.name = "Salle";
    diningArea.x = width * 0.05;
    diningArea.y = height * 0.05;
    diningArea.width = width * 0.65;
    diningArea.height = height * 0.6;
    diningArea.hasDoor = true;
    diningArea.doorPosition = 0;
    rooms.append(diningArea);

    // Cuisine
    Room kitchen;
    kitchen.name = "Cuisine";
    kitchen.x = width * 0.75;
    kitchen.y = height * 0.05;
    kitchen.width = width * 0.2;
    kitchen.height = height * 0.4;
    kitchen.hasDoor = true;
    kitchen.doorPosition = 3;
    rooms.append(kitchen);

    if (roomCount >= 3) {
        // Entrée et bar
        Room barArea;
        barArea.name = "Bar";
        barArea.x = width * 0.05;
        barArea.y = height * 0.7;
        barArea.width = width * 0.3;
        barArea.height = height * 0.25;
        barArea.hasDoor = true;
        barArea.doorPosition = 0;
        rooms.append(barArea);
    }

    if (roomCount >= 4) {
        // Sanitaires
        Room restrooms;
        restrooms.name = "Sanitaires";
        restrooms.x = width * 0.4;
        restrooms.y = height * 0.7;
        restrooms.width = width * 0.25;
        restrooms.height = height * 0.25;
        restrooms.hasDoor = true;
        restrooms.doorPosition = 0;
        rooms.append(restrooms);
    }

    if (roomCount >= 5) {
        // Réserve
        Room storage;
        storage.name = "Réserve";
        storage.x = width * 0.7;
        storage.y = height * 0.7;
        storage.width = width * 0.25;
        storage.height = height * 0.25;
        storage.hasDoor = true;
        storage.doorPosition = 0;
        rooms.append(storage);
    }



}
//magasin
void FloorPlanGenerator::generateStorePlan(int width, int height, int roomCount, QVector<Room> &rooms)
{
    // Espace principal
    Room mainArea;
    mainArea.name = "Vente";
    mainArea.x = width * 0.05;
    mainArea.y = height * 0.05;
    mainArea.width = width * 0.7;
    mainArea.height = height * 0.7;
    mainArea.hasDoor = true;
    mainArea.doorPosition = 0;
    rooms.append(mainArea);

    if (roomCount >= 2) {
        // Réserve
        Room storage;
        storage.name = "Stock";
        storage.x = width * 0.8;
        storage.y = height * 0.05;
        storage.width = width * 0.15;
        storage.height = height * 0.45;
        storage.hasDoor = true;
        storage.doorPosition = 3;
        rooms.append(storage);
    }

    if (roomCount >= 3) {
        // Bureau
        Room office;
        office.name = "Bureau";
        office.x = width * 0.8;
        office.y = height * 0.55;
        office.width = width * 0.15;
        office.height = height * 0.2;
        office.hasDoor = true;
        office.doorPosition = 3;
        rooms.append(office);
    }

    if (roomCount >= 4) {
        // Caisse
        Room checkout;
        checkout.name = "Caisse";
        checkout.x = width * 0.05;
        checkout.y = height * 0.8;
        checkout.width = width * 0.2;
        checkout.height = height * 0.15;
        checkout.hasDoor = false;
        rooms.append(checkout);
    }


}
