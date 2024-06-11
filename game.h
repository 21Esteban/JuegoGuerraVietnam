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
#include "piedra.h"

class Game : public QGraphicsView
{
public:
    explicit Game(QWidget *parent = 0);

    QGraphicsScene * escena;
    QGraphicsScene * nuevaEscena;
    Player * player;
    Player * player1;
    Plataforma *plataforma;
    Vida * vida;
    QTimer * timer;
    Vida * enemigo;
    Piedra *piedra;


    void incrementarNumEnemigos();
    int getNumeroDeEnemigos();
    void generarEnemigos();
    void cambiarEscena();

private:

    int enemigosSpawneados;
    //FondoMovido *fondoMovido;


signals:
};

#endif // GAME_H
