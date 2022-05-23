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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QWidget *centralwidget;
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
        icon.addFile(QString::fromUtf8(":/images/add-document.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(false);
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
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExport);
        menuFile->addSeparator();
        menuFile->addAction(menuFilters->menuAction());
        menuFilters->addAction(actionGrayscale);
        menuFilters->addAction(actionNegative);
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
        toolBar->addAction(actionColor_Palette);
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
