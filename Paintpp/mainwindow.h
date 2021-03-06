#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "rgbMatrix.h"
#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);

private slots:

    int calculateRelativePosX (int x);

    int calculateRelativePosY (int y);

    bool inBounds(int x, int y);

    void on_actionOpen_triggered();

    void on_actionExport_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionZoomIn_triggered();

    void on_actionZoomOut_triggered();

    void on_actionRotate_triggered();

    void on_actionGrayscale_triggered();

    void on_actionNegative_triggered();

    void on_actionColor_Palette_triggered();

    void on_actionScrollUp_triggered();

    void on_actionScrollDown_triggered();

    void on_actionScroll_Left_triggered();

    void on_actionScroll_Right_triggered();

    void on_thickness_pushButton_clicked();

    void on_actionThickness_triggered();

    void on_path_pushButton_clicked();

    void on_filename_pushButton_clicked();

    void on_actionNew_canvas_triggered();

    void on_canvasSize_pushButton_clicked();

    void on_geometry_pushButton_clicked();

    void on_actionGeometry_triggered(bool checked);

    void on_actionExperimental_1_triggered();

    void on_actionExperimental_2_triggered();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
