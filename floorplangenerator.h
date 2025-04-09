#ifndef FLOORPLANGENERATOR_H
#define FLOORPLANGENERATOR_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <QString>

class QComboBox;
class QSpinBox;
class QPushButton;

// Structures de données
struct Room {
    QString name;
    double x;
    double y;
    double width;
    double height;
    bool hasDoor;
    int doorPosition; // 0: Nord, 1: Est, 2: Sud, 3: Ouest
};



class FloorPlanGenerator : public QDialog {
    Q_OBJECT

public:
    explicit FloorPlanGenerator(QWidget *parent = nullptr);
    ~FloorPlanGenerator() override;
    // UI Components
    QGraphicsScene *scene;
    QGraphicsView *view;
    QComboBox *planTypeCombo;
    QSpinBox *widthSpinBox;
    QSpinBox *heightSpinBox;
    QSpinBox *roomCountSpinBox;
    QPushButton *generateButton;
    QPushButton *saveButton;
    void generateFloorPlan();
    void savePlan();
    void onPlanTypeChanged(int index);

private slots:



private:


    // Drawing methods
    void drawOuterWalls(int width, int height);
    void drawRoom(const Room &room);


    // Plan generation methods
    void generateHousePlan(int width, int height, int roomCount, QVector<Room> &rooms);
    void generateOfficePlan(int width, int height, int roomCount, QVector<Room> &rooms);
    void generateApartmentPlan(int width, int height, int roomCount, QVector<Room> &rooms);
    void generateRestaurantPlan(int width, int height, int roomCount, QVector<Room> &rooms);
    void generateStorePlan(int width, int height, int roomCount, QVector<Room> &rooms);


    // Furniture methods


    void setupUI();
    void createConnections();
};

#endif // FLOORPLANGENERATOR_H
