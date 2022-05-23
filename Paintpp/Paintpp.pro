QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BmpImage.cpp \
    Filters.cpp \
    Stack.cpp \
    main.cpp \
    mainwindow.cpp \
    rgbMatrix.cpp

HEADERS += \
    BmpImage.h \
    Filters.h \
    Stack.h \
    mainwindow.h \
    rgbMatrix.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    images.qrc

DISTFILES += \
    images/acercarse.png \
    images/add-document.png \
    images/disk.png \
    images/disminuir-el-zoom.png \
    images/edit-alt.png \
    images/escoba.png \
    images/expandir.png \
    images/eye-dropper.png \
    images/feather.png \
    images/fill.png \
    images/lapiz.png \
    images/pencil.png \
    images/redo.png \
    images/rotate.png \
    images/search.png \
    images/undo.png \
    images/varita-magica.png \
    in.bmp
