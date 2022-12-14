QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../view/calcx.cpp \
    ../view/graph.cpp \
    ../view/main.cpp \
    ../view/mainwindow.cpp \
    ../controller/controller.cpp \
    ../model/expression.cpp \
    ../model/calculator.cpp \
    ../model/model.cpp \
    ../qcustomplot.cpp


HEADERS += \
    ../view/calcx.h \
    ../view/graph.h \
    ../view/mainwindow.h \
    ../model/calculator.h \
    ../model/expression.h \
    ../model/model.h \
    ../controller/controller.h \
    ../qcustomplot.h

FORMS += \
    ../view/mainwindow.ui \
    ../view/dialog_calcx.ui \
    ../view/graph.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
