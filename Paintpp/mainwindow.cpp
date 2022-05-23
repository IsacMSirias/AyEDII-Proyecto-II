#include <QMouseEvent>
#include <QColorDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BmpImage.h"
#include "rgbMatrix.h"
#include "Filters.h"
#include "Stack.h"

rgbMatrix *imgMatrix = new rgbMatrix(200, 200);
rgbColor *selectedColor = new rgbColor(0, 0, 0);
rgbColor eraserColor(255, 255, 255);
int zoomSize = 2;
int scrollY = 0;
int scrollX = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imgMatrix->whiteCanvas();
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

    pen.setWidth(zoomSize);

    for (int i = 0; i < imgMatrix->get_Width(); ++i) {
        for (int j = 0; j < imgMatrix->get_Height(); ++j) {
            color.setRgb(imgMatrix->getColor(j, i).r, imgMatrix->getColor(j, i).g, imgMatrix->getColor(j, i).b);
            pen.setColor(color);
            painter.setPen(pen);
            painter.drawPoint(i*zoomSize+10+scrollX,j*zoomSize+ui->menubar->height()+10+scrollY);
        }
    }
}


void MainWindow::on_actionOpen_triggered()
{
    BmpImage readImg("/home/danielcob/Documents/AyEDII-Proyecto-II/Paintpp/in.bmp");
    imgMatrix = new rgbMatrix(readImg.getDataArray(), readImg.get_Height(), readImg.get_Width());
    update();
}


void MainWindow::on_actionExport_triggered()
{
    imgMatrix->CreateRgbArray();
    BmpImage exportImg("out", imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize());
}


void MainWindow::on_actionUndo_triggered()
{

}


void MainWindow::on_actionRedo_triggered()
{

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (ui->actionPencil->isChecked())
    {
        imgMatrix->setColor(*selectedColor, (event->position().y()-ui->menubar->height()-10-scrollY)/zoomSize, (event->position().x()-10-scrollX)/zoomSize);
    }
    if (ui->actionEraser->isChecked())
    {
        imgMatrix->setColor(eraserColor, (event->position().y()-ui->menubar->height()-10-scrollY)/zoomSize, (event->position().x()-10-scrollX)/zoomSize);
    }
    if (ui->actionColorPicker->isChecked())
    {
        rgbColor color = imgMatrix->getColor((event->position().y()-ui->menubar->height()-10-scrollY)/zoomSize, (event->position().x()-10-scrollX)/zoomSize);
        selectedColor = new rgbColor(color.r, color.g, color.b);
    }
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (ui->actionPencil->isChecked())
    {
        imgMatrix->setColor(*selectedColor, (event->position().y()-ui->menubar->height()-10-scrollY)/zoomSize, (event->position().x()-10-scrollX)/zoomSize);
    }
    if (ui->actionEraser->isChecked())
    {
        imgMatrix->setColor(eraserColor, (event->position().y()-ui->menubar->height()-10-scrollY)/zoomSize, (event->position().x()-10-scrollX)/zoomSize);
    }
    update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //update();
}

void MainWindow::on_actionZoomIn_triggered()
{
    zoomSize += 1;
    update();
}


void MainWindow::on_actionZoomOut_triggered()
{
    if (zoomSize > 2)
    {
        zoomSize -= 1;
        update();
    }
}


void MainWindow::on_actionRotate_triggered()
{
    imgMatrix->rotate90CW();
    update();
}


void MainWindow::on_actionGrayscale_triggered()
{
    Filters filters;
    filters.grayFilter(*imgMatrix);
    update();
}


void MainWindow::on_actionNegative_triggered()
{
    Filters filters;
    filters.negativeFilter(*imgMatrix);
    update();
}


void MainWindow::on_actionColor_Palette_triggered()
{
    QColor newColor = QColorDialog::getColor(QColor(selectedColor->r,selectedColor->g,selectedColor->b));
    selectedColor = new rgbColor(newColor.red(), newColor.green(), newColor.blue());
}


void MainWindow::on_actionScrollUp_triggered()
{
    scrollY -= 10;
    update();
}


void MainWindow::on_actionScrollDown_triggered()
{
    scrollY += 10;
    update();
}

void MainWindow::on_actionScroll_Left_triggered()
{
    scrollX -= 10;
    update();
}


void MainWindow::on_actionScroll_Right_triggered()
{
    scrollX += 10;
    update();
}

