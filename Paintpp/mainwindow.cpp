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


void MainWindow::on_actionOpen_triggered()
{
    Image img;
    img.generate(400,400);
    img.Read("in.bmp");
    //ui->canvas->pixmap().loadFromData(); //hay que ver qué ponemos acá
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

