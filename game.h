#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "plataforma.h"
#include "vida.h"
#include <QTimer>
#include <QRandomGenerator>
#include "fondomovido.h"

class Game : public QGraphicsView
{
public:
    explicit Game(QWidget *parent = 0);

    QGraphicsScene * escena;
    Player * player;
    Plataforma *plataforma;
    Vida * vida;
    QTimer * timer;
    Vida * enemigo;


    void incrementarNumEnemigos();
    int getNumeroDeEnemigos();
    void generarEnemigos();

private:

    int enemigosSpawneados;
    //FondoMovido *fondoMovido;


signals:
};

#endif // GAME_H
