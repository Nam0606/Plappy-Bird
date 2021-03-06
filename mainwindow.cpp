#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
//#include "pillaritem.h"
#include "birditem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(-250, -300, 500, 600);

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/new/prefix1/images/background_day.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0, 0) -QPointF(pixItem->boundingRect().width()/2, pixItem->boundingRect().height()/2));

//    scene->addLine(-400, 0, 400, 0, QPen(Qt::blue));
//    scene->addLine(0, -400, 0, 400, QPen(Qt::blue));

    BirdItem * bird = new BirdItem(QPixmap(":/new/prefix1/images/bird_blue_up.png"));
    scene->addItem(bird);

//    PillarItem * pillar = new PillarItem();
//    scene->addItem(pillar);

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

