#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "plataforma.h"
#include "vida.h"

class Game : public QGraphicsView
{
public:
    explicit Game(QWidget *parent = nullptr);

    QGraphicsScene * escena;
    Player * player;
    Plataforma *plataforma;
    Vida * vida;




signals:
};

#endif // GAME_H
