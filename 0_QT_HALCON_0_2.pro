#-------------------------------------------------
#
# Project created by QtCreator 2021-02-01T09:40:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 0_QT_HALCON_0_2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        cmylabel.cpp \
    dialogFile/closiongdialog.cpp \
    dialogFile/createscaledshapemodeldialog.cpp \
    dialogFile/dilationdialog.cpp \
    dialogFile/erosioncircledialog.cpp \
    dialogFile/openingdialog.cpp \
    dialogFile/scaleimagedialog.cpp \
    dialogFile/selectdialog.cpp \
        dialogFile/thresholddialog.cpp \
        htmyqlistwidget.cpp \
        main.cpp \
        mainwindow.cpp \
    struct/domclosing.cpp \
    struct/domconnection.cpp \
    struct/domcreatescaledshapemodel.cpp \
    struct/domdilation.cpp \
    struct/domerosioncircle.cpp \
    struct/domopening.cpp \
    struct/domscaleimage.cpp \
    struct/domselectshape.cpp \
        struct/domthreshold.cpp \
        struct/drawroiFile/drawroiqh.cpp \
        struct/drawroiFile/drawroiqhcircle.cpp \
        struct/drawroiFile/drawroiqhellipse.cpp \
        struct/drawroiFile/drawroiqhrectangle1.cpp \
        struct/drawroiFile/drawroiqhrectangle2.cpp \
        struct/drawroiFile/drawroiqhritate.cpp \
        struct/drawroiFile/thresholddom.cpp \
    struct/mainwindowatt.cpp \
        struct/rgb1tograydom.cpp \
        struct/superstruct.cpp \

HEADERS += \
        cmylabel.h \
    dialogFile/closiongdialog.h \
    dialogFile/createscaledshapemodeldialog.h \
    dialogFile/dilationdialog.h \
    dialogFile/erosioncircledialog.h \
    dialogFile/openingdialog.h \
    dialogFile/scaleimagedialog.h \
    dialogFile/selectdialog.h \
        dialogFile/thresholddialog.h \
        htmyqlistwidget.h \
        mainwindow.h \
        mainwindowatt.h \
    struct/domclosing.h \
    struct/domconnection.h \
    struct/domcreatescaledshapemodel.h \
    struct/domdilation.h \
    struct/domerosioncircle.h \
    struct/domopening.h \
    struct/domscaleimage.h \
    struct/domselectshape.h \
        struct/domthreshold.h \
        struct/drawroiFile/drawroiqh.h \
        struct/drawroiFile/drawroiqhcircle.h \
        struct/drawroiFile/drawroiqhellipse.h \
        struct/drawroiFile/drawroiqhrectangle1.h \
        struct/drawroiFile/drawroiqhrectangle2.h \
        struct/drawroiFile/drawroiqhritate.h \
        struct/rgb1tograydom.h \
        struct/superstruct.h \

FORMS += \
        dialogFile/closiongdialog.ui \
        dialogFile/createscaledshapemodeldialog.ui \
        dialogFile/dilationdialog.ui \
        dialogFile/erosioncircledialog.ui \
        dialogFile/openingdialog.ui \
        dialogFile/scaleimagedialog.ui \
        dialogFile/selectdialog.ui \
        dialogFile/thresholddialog.ui \
        mainwindow.ui

# *************************Qt配置Halcon*****************************
# MacOS specific settings. Note that while dyld will search under
# /Library/Frameworks by default, the preprocessor/compiler/linker will not
# and need to be told explicitly.
macx {
  QMAKE_CXXFLAGS += -F/Library/Frameworks
  QMAKE_LFLAGS   += -F/Library/Frameworks
  LIBS           += -framework HALCONCpp
}
else {
  #defines
  win32:DEFINES += WIN32

  #includes
  INCLUDEPATH   += "$$(HALCONROOT)/include"
  INCLUDEPATH   += "$$(HALCONROOT)/include/halconcpp"

  #libs
  QMAKE_LIBDIR  += "$$(HALCONROOT)/lib/$$(HALCONARCH)"
  unix:LIBS     += -lhalconcpp -lhalcon -lXext -lX11 -ldl -lpthread
  win32:LIBS    += "$$(HALCONROOT)/lib/$$(HALCONARCH)/halconcpp.lib" \
                   "$$(HALCONROOT)/lib/$$(HALCONARCH)/halcon.lib"
}
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image/image.qrc
