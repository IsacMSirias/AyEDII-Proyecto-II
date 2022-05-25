/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExport;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionPencil;
    QAction *actionPen;
    QAction *actionColorPicker;
    QAction *actionFill;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionmagicWand;
    QAction *actionEraser;
    QAction *actionSelect;
    QAction *actionRotate;
    QAction *actionGrayscale;
    QAction *actionNegative;
    QAction *actionColor_Palette;
    QAction *actionScrollUp;
    QAction *actionScrollDown;
    QAction *actionScroll_Left;
    QAction *actionScroll_Right;
    QAction *actionThickness;
    QAction *actionGeometry;
    QAction *actionNew_canvas;
    QAction *actionExperimental_1;
    QAction *actionExperimental_2;
    QWidget *centralwidget;
    QWidget *thicknessWidget;
    QSpinBox *thickness_spinBox;
    QLabel *thickness_label;
    QPushButton *thickness_pushButton;
    QWidget *pathWidget;
    QLabel *path_label;
    QPushButton *path_pushButton;
    QLineEdit *path_lineEdit;
    QWidget *filenameWidget;
    QLabel *filename_label;
    QPushButton *filename_pushButton;
    QLineEdit *filename_lineEdit;
    QWidget *canvasSizeWidget;
    QLabel *canvasSize_label;
    QPushButton *canvasSize_pushButton;
    QSpinBox *width_spinBox;
    QSpinBox *height_spinBox;
    QLabel *height_label;
    QLabel *width_label;
    QWidget *geometryWidget;
    QLabel *geometry_label;
    QPushButton *geometry_pushButton;
    QComboBox *geometry_comboBox;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuFilters;
    QMenu *menuEdit;
    QMenu *menuView;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(811, 642);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionOpen->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QString::fromUtf8("actionExport"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport->setIcon(icon1);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon2);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon3);
        actionPencil = new QAction(MainWindow);
        actionPencil->setObjectName(QString::fromUtf8("actionPencil"));
        actionPencil->setCheckable(true);
        actionPencil->setChecked(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPencil->setIcon(icon4);
        actionPen = new QAction(MainWindow);
        actionPen->setObjectName(QString::fromUtf8("actionPen"));
        actionPen->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/feather.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPen->setIcon(icon5);
        actionColorPicker = new QAction(MainWindow);
        actionColorPicker->setObjectName(QString::fromUtf8("actionColorPicker"));
        actionColorPicker->setCheckable(true);
        actionColorPicker->setChecked(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/eye-dropper.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionColorPicker->setIcon(icon6);
        actionFill = new QAction(MainWindow);
        actionFill->setObjectName(QString::fromUtf8("actionFill"));
        actionFill->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/fill.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFill->setIcon(icon7);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QString::fromUtf8("actionZoomIn"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/acercarse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon8);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QString::fromUtf8("actionZoomOut"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/disminuir-el-zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon9);
        actionmagicWand = new QAction(MainWindow);
        actionmagicWand->setObjectName(QString::fromUtf8("actionmagicWand"));
        actionmagicWand->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/varita-magica.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionmagicWand->setIcon(icon10);
        actionEraser = new QAction(MainWindow);
        actionEraser->setObjectName(QString::fromUtf8("actionEraser"));
        actionEraser->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/lapiz.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEraser->setIcon(icon11);
        actionSelect = new QAction(MainWindow);
        actionSelect->setObjectName(QString::fromUtf8("actionSelect"));
        actionSelect->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/expandir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect->setIcon(icon12);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QString::fromUtf8("actionRotate"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon13);
        actionGrayscale = new QAction(MainWindow);
        actionGrayscale->setObjectName(QString::fromUtf8("actionGrayscale"));
        actionNegative = new QAction(MainWindow);
        actionNegative->setObjectName(QString::fromUtf8("actionNegative"));
        actionColor_Palette = new QAction(MainWindow);
        actionColor_Palette->setObjectName(QString::fromUtf8("actionColor_Palette"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionColor_Palette->setIcon(icon14);
        actionScrollUp = new QAction(MainWindow);
        actionScrollUp->setObjectName(QString::fromUtf8("actionScrollUp"));
        actionScrollDown = new QAction(MainWindow);
        actionScrollDown->setObjectName(QString::fromUtf8("actionScrollDown"));
        actionScroll_Left = new QAction(MainWindow);
        actionScroll_Left->setObjectName(QString::fromUtf8("actionScroll_Left"));
        actionScroll_Right = new QAction(MainWindow);
        actionScroll_Right->setObjectName(QString::fromUtf8("actionScroll_Right"));
        actionThickness = new QAction(MainWindow);
        actionThickness->setObjectName(QString::fromUtf8("actionThickness"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/line-width.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionThickness->setIcon(icon15);
        actionGeometry = new QAction(MainWindow);
        actionGeometry->setObjectName(QString::fromUtf8("actionGeometry"));
        actionGeometry->setCheckable(true);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/resources.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGeometry->setIcon(icon16);
        actionNew_canvas = new QAction(MainWindow);
        actionNew_canvas->setObjectName(QString::fromUtf8("actionNew_canvas"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/add-document.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_canvas->setIcon(icon17);
        actionExperimental_1 = new QAction(MainWindow);
        actionExperimental_1->setObjectName(QString::fromUtf8("actionExperimental_1"));
        actionExperimental_2 = new QAction(MainWindow);
        actionExperimental_2->setObjectName(QString::fromUtf8("actionExperimental_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(false);
        thicknessWidget = new QWidget(centralwidget);
        thicknessWidget->setObjectName(QString::fromUtf8("thicknessWidget"));
        thicknessWidget->setEnabled(true);
        thicknessWidget->setGeometry(QRect(240, 190, 271, 141));
        thicknessWidget->setStyleSheet(QString::fromUtf8("QWidget#thicknessWidget {\n"
"background-color: rgb(241, 241, 241);\n"
"border-radius: 5px;\n"
"border: 1px solid rgb(154, 153, 150);\n"
"}"));
        thickness_spinBox = new QSpinBox(thicknessWidget);
        thickness_spinBox->setObjectName(QString::fromUtf8("thickness_spinBox"));
        thickness_spinBox->setGeometry(QRect(110, 50, 45, 24));
        thickness_spinBox->setStyleSheet(QString::fromUtf8(""));
        thickness_spinBox->setMinimum(1);
        thickness_label = new QLabel(thicknessWidget);
        thickness_label->setObjectName(QString::fromUtf8("thickness_label"));
        thickness_label->setEnabled(true);
        thickness_label->setGeometry(QRect(70, 10, 131, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Ubuntu")});
        font.setPointSize(12);
        font.setBold(false);
        thickness_label->setFont(font);
        thickness_label->setAutoFillBackground(false);
        thickness_pushButton = new QPushButton(thicknessWidget);
        thickness_pushButton->setObjectName(QString::fromUtf8("thickness_pushButton"));
        thickness_pushButton->setGeometry(QRect(90, 100, 83, 24));
        pathWidget = new QWidget(centralwidget);
        pathWidget->setObjectName(QString::fromUtf8("pathWidget"));
        pathWidget->setGeometry(QRect(230, 190, 291, 141));
        pathWidget->setStyleSheet(QString::fromUtf8("QWidget#pathWidget {\n"
"background-color: rgb(241, 241, 241);\n"
"border-radius: 5px;\n"
"border: 1px solid rgb(154, 153, 150);\n"
"}"));
        path_label = new QLabel(pathWidget);
        path_label->setObjectName(QString::fromUtf8("path_label"));
        path_label->setEnabled(true);
        path_label->setGeometry(QRect(20, 10, 251, 20));
        path_label->setFont(font);
        path_label->setAutoFillBackground(false);
        path_pushButton = new QPushButton(pathWidget);
        path_pushButton->setObjectName(QString::fromUtf8("path_pushButton"));
        path_pushButton->setGeometry(QRect(100, 100, 83, 24));
        path_lineEdit = new QLineEdit(pathWidget);
        path_lineEdit->setObjectName(QString::fromUtf8("path_lineEdit"));
        path_lineEdit->setGeometry(QRect(20, 50, 251, 23));
        filenameWidget = new QWidget(centralwidget);
        filenameWidget->setObjectName(QString::fromUtf8("filenameWidget"));
        filenameWidget->setGeometry(QRect(230, 190, 291, 141));
        filenameWidget->setStyleSheet(QString::fromUtf8("QWidget#filenameWidget {\n"
"background-color: rgb(241, 241, 241);\n"
"border-radius: 5px;\n"
"border: 1px solid rgb(154, 153, 150);\n"
"}"));
        filename_label = new QLabel(filenameWidget);
        filename_label->setObjectName(QString::fromUtf8("filename_label"));
        filename_label->setEnabled(true);
        filename_label->setGeometry(QRect(20, 10, 251, 20));
        filename_label->setFont(font);
        filename_label->setAutoFillBackground(false);
        filename_pushButton = new QPushButton(filenameWidget);
        filename_pushButton->setObjectName(QString::fromUtf8("filename_pushButton"));
        filename_pushButton->setGeometry(QRect(100, 100, 83, 24));
        filename_lineEdit = new QLineEdit(filenameWidget);
        filename_lineEdit->setObjectName(QString::fromUtf8("filename_lineEdit"));
        filename_lineEdit->setGeometry(QRect(20, 50, 251, 23));
        canvasSizeWidget = new QWidget(centralwidget);
        canvasSizeWidget->setObjectName(QString::fromUtf8("canvasSizeWidget"));
        canvasSizeWidget->setGeometry(QRect(230, 190, 291, 141));
        canvasSizeWidget->setStyleSheet(QString::fromUtf8("QWidget#canvasSizeWidget {\n"
"background-color: rgb(241, 241, 241);\n"
"border-radius: 5px;\n"
"border: 1px solid rgb(154, 153, 150);\n"
"}"));
        canvasSize_label = new QLabel(canvasSizeWidget);
        canvasSize_label->setObjectName(QString::fromUtf8("canvasSize_label"));
        canvasSize_label->setEnabled(true);
        canvasSize_label->setGeometry(QRect(20, 10, 251, 20));
        canvasSize_label->setFont(font);
        canvasSize_label->setAutoFillBackground(false);
        canvasSize_pushButton = new QPushButton(canvasSizeWidget);
        canvasSize_pushButton->setObjectName(QString::fromUtf8("canvasSize_pushButton"));
        canvasSize_pushButton->setGeometry(QRect(100, 100, 83, 24));
        width_spinBox = new QSpinBox(canvasSizeWidget);
        width_spinBox->setObjectName(QString::fromUtf8("width_spinBox"));
        width_spinBox->setGeometry(QRect(80, 50, 51, 24));
        width_spinBox->setMinimum(1);
        width_spinBox->setMaximum(1000);
        height_spinBox = new QSpinBox(canvasSizeWidget);
        height_spinBox->setObjectName(QString::fromUtf8("height_spinBox"));
        height_spinBox->setGeometry(QRect(210, 50, 51, 24));
        height_spinBox->setMinimum(1);
        height_spinBox->setMaximum(1000);
        height_label = new QLabel(canvasSizeWidget);
        height_label->setObjectName(QString::fromUtf8("height_label"));
        height_label->setEnabled(true);
        height_label->setGeometry(QRect(150, 47, 60, 30));
        height_label->setFont(font);
        height_label->setAutoFillBackground(false);
        width_label = new QLabel(canvasSizeWidget);
        width_label->setObjectName(QString::fromUtf8("width_label"));
        width_label->setEnabled(true);
        width_label->setGeometry(QRect(20, 47, 60, 30));
        width_label->setFont(font);
        width_label->setAutoFillBackground(false);
        geometryWidget = new QWidget(centralwidget);
        geometryWidget->setObjectName(QString::fromUtf8("geometryWidget"));
        geometryWidget->setGeometry(QRect(230, 190, 291, 141));
        geometryWidget->setStyleSheet(QString::fromUtf8("QWidget#geometryWidget {\n"
"background-color: rgb(241, 241, 241);\n"
"border-radius: 5px;\n"
"border: 1px solid rgb(154, 153, 150);\n"
"}"));
        geometry_label = new QLabel(geometryWidget);
        geometry_label->setObjectName(QString::fromUtf8("geometry_label"));
        geometry_label->setEnabled(true);
        geometry_label->setGeometry(QRect(10, 10, 271, 20));
        geometry_label->setFont(font);
        geometry_label->setAutoFillBackground(false);
        geometry_pushButton = new QPushButton(geometryWidget);
        geometry_pushButton->setObjectName(QString::fromUtf8("geometry_pushButton"));
        geometry_pushButton->setGeometry(QRect(100, 100, 83, 24));
        geometry_comboBox = new QComboBox(geometryWidget);
        geometry_comboBox->addItem(QString());
        geometry_comboBox->addItem(QString());
        geometry_comboBox->addItem(QString());
        geometry_comboBox->setObjectName(QString::fromUtf8("geometry_comboBox"));
        geometry_comboBox->setGeometry(QRect(70, 50, 141, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 811, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFilters = new QMenu(menuFile);
        menuFilters->setObjectName(QString::fromUtf8("menuFilters"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::RightToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(actionNew_canvas);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(menuFilters->menuAction());
        menuFilters->addAction(actionGrayscale);
        menuFilters->addAction(actionNegative);
        menuFilters->addAction(actionExperimental_1);
        menuFilters->addAction(actionExperimental_2);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuView->addAction(actionZoomIn);
        menuView->addAction(actionZoomOut);
        menuView->addSeparator();
        menuView->addAction(actionRotate);
        menuView->addSeparator();
        menuView->addAction(actionScrollUp);
        menuView->addAction(actionScrollDown);
        menuView->addAction(actionScroll_Left);
        menuView->addAction(actionScroll_Right);
        toolBar->addAction(actionPencil);
        toolBar->addAction(actionEraser);
        toolBar->addAction(actionPen);
        toolBar->addAction(actionFill);
        toolBar->addAction(actionColorPicker);
        toolBar->addAction(actionSelect);
        toolBar->addAction(actionmagicWand);
        toolBar->addAction(actionGeometry);
        toolBar->addSeparator();
        toolBar->addAction(actionColor_Palette);
        toolBar->addAction(actionThickness);
        toolBar->addSeparator();
        toolBar->addAction(actionZoomIn);
        toolBar->addAction(actionZoomOut);
        toolBar->addAction(actionRotate);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExport->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
#if QT_CONFIG(shortcut)
        actionExport->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPencil->setText(QCoreApplication::translate("MainWindow", "Pencil", nullptr));
        actionPen->setText(QCoreApplication::translate("MainWindow", "Pen", nullptr));
        actionColorPicker->setText(QCoreApplication::translate("MainWindow", "ColorPicker", nullptr));
        actionFill->setText(QCoreApplication::translate("MainWindow", "Fill", nullptr));
        actionZoomIn->setText(QCoreApplication::translate("MainWindow", "ZoomIn", nullptr));
#if QT_CONFIG(shortcut)
        actionZoomIn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl++", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoomOut->setText(QCoreApplication::translate("MainWindow", "ZoomOut", nullptr));
#if QT_CONFIG(shortcut)
        actionZoomOut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionmagicWand->setText(QCoreApplication::translate("MainWindow", "MagicWand", nullptr));
        actionEraser->setText(QCoreApplication::translate("MainWindow", "Eraser", nullptr));
        actionSelect->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        actionRotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        actionGrayscale->setText(QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        actionNegative->setText(QCoreApplication::translate("MainWindow", "Negative", nullptr));
        actionColor_Palette->setText(QCoreApplication::translate("MainWindow", "Color Palette", nullptr));
        actionScrollUp->setText(QCoreApplication::translate("MainWindow", "Scroll Up", nullptr));
#if QT_CONFIG(shortcut)
        actionScrollUp->setShortcut(QCoreApplication::translate("MainWindow", "Up", nullptr));
#endif // QT_CONFIG(shortcut)
        actionScrollDown->setText(QCoreApplication::translate("MainWindow", "Scroll Down", nullptr));
#if QT_CONFIG(shortcut)
        actionScrollDown->setShortcut(QCoreApplication::translate("MainWindow", "Down", nullptr));
#endif // QT_CONFIG(shortcut)
        actionScroll_Left->setText(QCoreApplication::translate("MainWindow", "Scroll Left", nullptr));
#if QT_CONFIG(shortcut)
        actionScroll_Left->setShortcut(QCoreApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        actionScroll_Right->setText(QCoreApplication::translate("MainWindow", "Scroll Right", nullptr));
#if QT_CONFIG(shortcut)
        actionScroll_Right->setShortcut(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
        actionThickness->setText(QCoreApplication::translate("MainWindow", "Thickness", nullptr));
        actionGeometry->setText(QCoreApplication::translate("MainWindow", "Geometry", nullptr));
        actionNew_canvas->setText(QCoreApplication::translate("MainWindow", "New canvas", nullptr));
        actionExperimental_1->setText(QCoreApplication::translate("MainWindow", "Experimental 1", nullptr));
        actionExperimental_2->setText(QCoreApplication::translate("MainWindow", "Experimental 2", nullptr));
        thickness_label->setText(QCoreApplication::translate("MainWindow", "Choose thickness:", nullptr));
        thickness_pushButton->setText(QCoreApplication::translate("MainWindow", "Okay", nullptr));
        path_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Write filepath:</p></body></html>", nullptr));
        path_pushButton->setText(QCoreApplication::translate("MainWindow", "Okay", nullptr));
        filename_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Write file name:</p></body></html>", nullptr));
        filename_pushButton->setText(QCoreApplication::translate("MainWindow", "Okay", nullptr));
        canvasSize_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Write canvas size:</p></body></html>", nullptr));
        canvasSize_pushButton->setText(QCoreApplication::translate("MainWindow", "Okay", nullptr));
        height_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Height:</p></body></html>", nullptr));
        width_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Width:</p></body></html>", nullptr));
        geometry_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Select figure:</p></body></html>", nullptr));
        geometry_pushButton->setText(QCoreApplication::translate("MainWindow", "Okay", nullptr));
        geometry_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        geometry_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        geometry_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Circle", nullptr));

        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuFilters->setTitle(QCoreApplication::translate("MainWindow", "Filters", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
