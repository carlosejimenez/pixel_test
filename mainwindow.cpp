#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int sizeX = 32;
    int sizeY = 32;

    QImage image = QImage(sizeX, sizeY, QImage::Format_ARGB32);

    for(int i =0; i < 32; i++){
        for (int c = 0; c < 32; c++){
            image.setPixel(i, c, qRgb(100, 150, 200));
        }
    }

    image.setPixel(14, 14, qRgb(100, 300, 250));
    image.setPixelColor(14, 15, qRgb(50, 150, 25));

    QGraphicsScene* graphic_vew = new QGraphicsScene(this);

    graphic_vew->addPixmap(QPixmap::fromImage(image).scaled(500,500));

    ui->graphicsView->setScene(graphic_vew);

}

MainWindow::~MainWindow()
{
    delete ui;
}
