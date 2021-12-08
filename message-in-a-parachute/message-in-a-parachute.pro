QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    letter.cpp \
    main.cpp \
    mainwindow.cpp \
    message.cpp \
    messageview.cpp \
    parachutewidget.cpp \
    binarywidget.cpp \
    colorbutton.cpp

HEADERS += \
    letter.h \
    mainwindow.h \
    message.h \
    messageview.h \
    parachutewidget.h \
    binarywidget.h \
    colorbutton.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    message-in-a-parachute-fr-FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    message-in-a-parachute-fr-FR.ts
