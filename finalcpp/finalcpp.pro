QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    asset/adresse.png \
    asset/im.png \
    asset/person.png \
    asset/projet.jpg \
    asset/services.png

HEADERS += \
    component/card.h \
    component/modulebutton.h \
    config/db.h \
    config/utility.h \
    model/adresse.h \
    model/affectation.h \
    model/employe.h \
    model/fonction.h \
    model/projet.h \
    model/service.h \
    view/mainwindow.h \
    view/page/adressepage.h \
    view/page/employepage.h \
    view/page/projetpage.h \
    view/page/servicepage.h

SOURCES += \
    component/card.cpp \
    component/modulebutton.cpp \
    config/db.cpp \
    main.cpp \
    model/adresse.cpp \
    model/affectation.cpp \
    model/employe.cpp \
    model/fonction.cpp \
    model/projet.cpp \
    model/service.cpp \
    view/mainwindow.cpp \
    view/page/adressepage.cpp \
    view/page/employepage.cpp \
    view/page/projetpage.cpp \
    view/page/servicepage.cpp

DISTFILES += \
    asset/af.png
