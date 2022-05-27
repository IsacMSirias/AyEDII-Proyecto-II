#include <QMouseEvent>
#include <QColorDialog>
#include <fstream>
#include <vector>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BmpImage.h"
#include "rgbMatrix.h"
#include "Graphics.h"
#include "Stack.h"

rgbMatrix *imgMatrix = new rgbMatrix(200, 200);
rgbColor *selectedColor = new rgbColor(0, 0, 0);
rgbColor eraserColor(255, 255, 255);
int thickness = 1;
int zoomSize = 2;
int scrollY = 0;
int scrollX = 0;
int posX1, posY1;
Graphics paint;
std::vector<BmpImage> undo;
std::vector<BmpImage> redo;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->thicknessWidget->hide();
    ui->pathWidget->hide();
    ui->filenameWidget->hide();
    ui->canvasSizeWidget->hide();
    ui->geometryWidget->hide();
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


int MainWindow::calculateRelativePosX (int x) {
    return (x-10-scrollX)/zoomSize;
}


int MainWindow::calculateRelativePosY (int y) {
    return (y-ui->menubar->height()-10-scrollY)/zoomSize;
}

bool MainWindow::inBounds(int x, int y) {
    if (x < imgMatrix->get_Width() && y < imgMatrix->get_Height() && 0 <= x && 0 <= y) {
        return true;
    }
    return false;
}

void MainWindow::on_actionOpen_triggered()
{
    ui->pathWidget->show();
}

void MainWindow::on_actionExport_triggered()
{
    ui->filenameWidget->show();
}

void MainWindow::on_actionUndo_triggered()
{
    if (undo.size() != 0) {
        imgMatrix->CreateRgbArray();
        redo.push_back(BmpImage("temp", imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize()));
        imgMatrix = new rgbMatrix(undo.back().getDataArray(), undo.back().get_Height(), undo.back().get_Width());
        undo.pop_back();
        update();
    }
}

void MainWindow::on_actionRedo_triggered()
{
    if (redo.size() != 0) {
        imgMatrix->CreateRgbArray();
        undo.push_back(BmpImage("temp", imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize()));
        imgMatrix = new rgbMatrix(redo.back().getDataArray(), redo.back().get_Height(), redo.back().get_Width());
        redo.pop_back();
        update();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (inBounds(calculateRelativePosX(event->position().x()), calculateRelativePosY(event->position().y()))) {
        imgMatrix->CreateRgbArray();
        undo.push_back(BmpImage("temp", imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize()));

        int posX = calculateRelativePosX(event->position().x());
        int posY = calculateRelativePosY(event->position().y());

        if (ui->actionPencil->isChecked())
        {
            paint.draw_WithPencil(*selectedColor, posY, posX, thickness, *imgMatrix);
        }
        else if (ui->actionEraser->isChecked())
        {
            paint.draw_WithPencil(eraserColor, posY, posX, thickness, *imgMatrix);
        }
        else if (ui->actionColorPicker->isChecked())
        {
            rgbColor color = imgMatrix->getColor(posY, posX);
            selectedColor = new rgbColor(color.r, color.g, color.b);
        }
        else if (ui->actionFill->isChecked())
        {
            paint.paintFill(imgMatrix->getColor(posY, posX), *selectedColor, posX, posY, *imgMatrix);
        }
        else if (ui->actionmagicWand->isChecked())
        {
            paint.paintFill(imgMatrix->getColor(posY, posX), eraserColor, posX, posY, *imgMatrix);
        }
        else if (ui->actionPen->isChecked() || ui->actionGeometry->isChecked() || ui->actionSelect->isChecked())
        {
            posY1 = posY;
            posX1 = posX;
        }
        update();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (inBounds(calculateRelativePosX(event->position().x()), calculateRelativePosY(event->position().y()))) {
        int posX = calculateRelativePosX(event->position().x());
        int posY = calculateRelativePosY(event->position().y());

        if (ui->actionPencil->isChecked())
        {
            paint.draw_WithPencil(*selectedColor, posY, posX, thickness, *imgMatrix);
        }
        else if (ui->actionEraser->isChecked())
        {
            paint.draw_WithPencil(eraserColor, posY, posX, thickness, *imgMatrix);
        }
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (inBounds(calculateRelativePosX(event->position().x()), calculateRelativePosY(event->position().y()))) {
        int posX = calculateRelativePosX(event->position().x());
        int posY = calculateRelativePosY(event->position().y());

        if (ui->actionPen->isChecked())
        {
            paint.draw_WithPen(*selectedColor, posY1, posX1, posY, posX, thickness, *imgMatrix);
        }
        else if(ui->actionGeometry->isChecked())
        {
            if (ui->geometry_comboBox->currentText() == "Rectangle")
            {
                paint.square(*selectedColor, posX1, posY1, posX, posY, thickness, *imgMatrix);
            }
            else if (ui->geometry_comboBox->currentText() == "Triangle")
            {
                paint.triangle(*selectedColor, posX1, posY1, posX, posY, thickness, *imgMatrix);
            }
            else if (ui->geometry_comboBox->currentText() == "Circle")
            {
                paint.circle(*selectedColor, posY1, posX1, posY, posX, thickness, *imgMatrix);
            }
        }
        else if (ui->actionSelect->isChecked())
        {
            paint.squareFill(eraserColor, posX1, posY1, posX, posY, *imgMatrix);
        }
        update();
    }
}

void MainWindow::on_actionZoomIn_triggered()
{
    zoomSize += 1;
    update();
}


void MainWindow::on_actionZoomOut_triggered()
{
    if (zoomSize > 1)
    {
        zoomSize -= 1;
        update();
    }
}


void MainWindow::on_actionRotate_triggered()
{
    imgMatrix->CreateRgbArray();
    undo.push_back(BmpImage("temp", imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize()));
    imgMatrix->rotate90CW();
    update();
}


void MainWindow::on_actionGrayscale_triggered()
{
    imgMatrix->CreateRgbArray();
    undo.push_back(BmpImage("temp", imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize()));
    paint.grayFilter(*imgMatrix);
    update();
}


void MainWindow::on_actionNegative_triggered()
{
    imgMatrix->CreateRgbArray();
    undo.push_back(BmpImage("temp", imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize()));
    paint.negativeFilter(*imgMatrix);
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


void MainWindow::on_thickness_pushButton_clicked()
{
    thickness = ui->thickness_spinBox->value();
    ui->thicknessWidget->hide();
}


void MainWindow::on_actionThickness_triggered()
{
    ui->thicknessWidget->show();
}


void MainWindow::on_path_pushButton_clicked()
{
    BmpImage readImg(ui->path_lineEdit->text().toStdString().c_str());
    ui->pathWidget->hide();
    imgMatrix = new rgbMatrix(readImg.getDataArray(), readImg.get_Height(), readImg.get_Width());
    update();
}


void MainWindow::on_filename_pushButton_clicked()
{
    imgMatrix->CreateRgbArray();
    BmpImage exportImg(ui->filename_lineEdit->text().toStdString().c_str(), imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize());
    ui->filenameWidget->hide();
}


void MainWindow::on_actionNew_canvas_triggered()
{
    ui->canvasSizeWidget->show();
}


void MainWindow::on_canvasSize_pushButton_clicked()
{
    imgMatrix = new rgbMatrix(ui->height_spinBox->value(), ui->width_spinBox->value());
    ui->canvasSizeWidget->hide();
    update();
}


void MainWindow::on_geometry_pushButton_clicked()
{
    ui->geometryWidget->hide();
}


void MainWindow::on_actionGeometry_triggered(bool checked)
{
    if (checked)
    {
        ui->geometryWidget->show();
    }
}


void MainWindow::on_actionExperimental_1_triggered()
{
    imgMatrix->CreateRgbArray();
    undo.push_back(BmpImage("temp", imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize()));
    paint.experimentalFilter1(*imgMatrix);
    update();
}


void MainWindow::on_actionExperimental_2_triggered()
{
    imgMatrix->CreateRgbArray();
    undo.push_back(BmpImage("temp", imgMatrix->get_Width(), imgMatrix->get_Height(), imgMatrix->get_rgbArray(), imgMatrix->get_rgbArraySize()));
    paint.experimentalFilter2(*imgMatrix);
    update();
}

