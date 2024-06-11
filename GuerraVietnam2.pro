QT       += core gui multimedia



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    enemigo.cpp \
    fondomovido.cpp \
    game.cpp \
    main.cpp \
    personaje.cpp \
    plataforma.cpp \
    player.cpp \
    pruebaenemigo.cpp \
    vida.cpp

HEADERS += \
    bala.h \
    enemigo.h \
    fondomovido.h \
    game.h \
    personaje.h \
    plataforma.h \
    player.h \
    pruebaenemigo.h \
    vida.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc