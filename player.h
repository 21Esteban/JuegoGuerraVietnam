#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QSet>
#include <QTimer>
#include <QSoundEffect>
#include "personaje.h"

class Player : public QObject, public Personaje
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
   // virtual ~Player();

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void updateMovement();
    void cambiarImagenAlDisparar();
    void jump();
    void shoot();
    void spawn();

private:
    bool isJumping;
    qreal jumpVelocity;
    qreal jumpHeight;
    qreal currentJumpHeight;
    QList<QString> animaciones;
    QTimer *temporizadorAux;
    QSet<int> keysPressed;
    QSoundEffect *sonidoDisparo;
    int frame;

    void moveLeft();
    void moveRight();
};

#endif // PLAYER_H
