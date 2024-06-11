QT       += core gui multimedia



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    enemigo.cpp \
    enemigo2.cpp \
    fondomovido.cpp \
    game.cpp \
    iniciojuego.cpp \
    main.cpp \
    personaje.cpp \
    piedra.cpp \
    plataforma.cpp \
    player.cpp \
    pruebaenemigo.cpp \
    vida.cpp

HEADERS += \
    bala.h \
    enemigo.h \
    enemigo2.h \
    fondomovido.h \
    game.h \
    iniciojuego.h \
    personaje.h \
    piedra.h \
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
