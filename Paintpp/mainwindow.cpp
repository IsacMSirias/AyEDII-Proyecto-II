#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "image.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QColor color;

    painter.setPen(pen);

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            color.setRgb(1, 1, 1);
            pen.setColor(color);
            painter.drawPoint(i,j);
        }
    }
}


void MainWindow::on_actionOpen_triggered()
{
    update();
}


void MainWindow::on_actionExport_triggered()
{

}


void MainWindow::on_actionUndo_triggered()
{

}


void MainWindow::on_actionRedo_triggered()
{

}

