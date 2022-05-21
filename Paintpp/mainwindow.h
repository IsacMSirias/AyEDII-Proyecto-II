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
    void on_actionOpen_triggered();

    void on_actionExport_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();
    void on_actionZoomIn_triggered();

    void on_actionZoomOut_triggered();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
