#include "player.h"
#include "bala.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "enemigo.h"
#include <QDebug>
#include "game.h"
#include "piedra.h"

extern Game *game;

Player::Player(QObject *parent)
    : QObject(parent), Personaje()
{
    // Inicialización de variables para el salto
    isJumping = false;
    jumpVelocity = -10.0; // Velocidad inicial del salto (ajústalo según sea necesario)
    jumpHeight = 100.0;   // Altura máxima del salto (ajústalo según sea necesario)
    currentJumpHeight = 0.0;

    // Inicialización de las animaciones
    this->animaciones.push_back(":/imagenes/movimiento1SinFondo.png");
    this->animaciones.push_back(":/imagenes/movimiento2SinFondo.png");
    this->animaciones.push_back(":/imagenes/movimiento3SinFondo.png");

    setPixmap(QPixmap(this->animaciones[0]).scaled(100, 100, Qt::KeepAspectRatio));

    // Inicialización del sonido de disparo
    sonidoDisparo = new QSoundEffect();
    sonidoDisparo->setSource(QUrl("qrc:/sonidos/sonido2Acortado.wav"));

    // Creación del temporizador auxiliar para cambiar la imagen al disparar
    temporizadorAux = new QTimer();
    connect(temporizadorAux, &QTimer::timeout, this, &Player::cambiarImagenAlDisparar);

    // Inicialización del temporizador de movimiento
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Player::updateMovement);
    timer->start(30);  // Intervalo de actualización, ajusta según sea necesario

    // Instalamos el filtro de eventos para manejar múltiples teclas
    this->installEventFilter(this);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        event->ignore();
        return;
    }

    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        keysPressed.insert(Qt::Key_Left);
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        keysPressed.insert(Qt::Key_Right);
    }
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up) {
        if (!isJumping) {
            isJumping = true;
            jump();
        }
    }
    if (event->key() == Qt::Key_Space) {
        shoot();
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        event->ignore();
        return;
    }

    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        keysPressed.remove(Qt::Key_Left);
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        keysPressed.remove(Qt::Key_Right);
    }
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up) {
        // No necesitamos hacer nada en la liberación de W o Up
    }
}

void Player::updateMovement()
{
    QList<QGraphicsItem *> elementos_colisionados = collidingItems();

    if (keysPressed.contains(Qt::Key_Left)) {
        for (int i = 0; i < elementos_colisionados.size(); ++i) {
            if (typeid(*(elementos_colisionados[i])) == typeid(Piedra)) {
                qDebug() << "Colisión con Objeto detectada. Movimiento bloqueado.";
                return;
            }
        }

        if (pos().x() > 0) {
            setPos(x() - 10, y());
            frame = (frame + 1) % 3; // Esto hará que el frame se reinicie a 0 después de alcanzar 2
            setPixmap(QPixmap(animaciones[frame]).scaled(100, 100, Qt::KeepAspectRatio));
        }
    }

    if (keysPressed.contains(Qt::Key_Right)) {
        for (int i = 0; i < elementos_colisionados.size(); ++i) {
            if (typeid(*(elementos_colisionados[i])) == typeid(Piedra)) {
                qDebug() << "Colisión con Objeto detectada. Movimiento bloqueado.";
                return;
            }
        }

        setPos(x() + 10, y());
        frame = (frame + 1) % 3; // Esto hará que el frame se reinicie a 0 después de alcanzar 2
        setPixmap(QPixmap(animaciones[frame]).scaled(100, 100, Qt::KeepAspectRatio));
    }
}

void Player::jump()
{
    if (currentJumpHeight < jumpHeight) {
        qreal newY = y() + jumpVelocity;
        if (newY >= 0) {
            setY(newY);
            currentJumpHeight += qAbs(jumpVelocity);
            QTimer::singleShot(20, this, &Player::jump);
        } else {
            currentJumpHeight = jumpHeight;
            isJumping = false;
        }
    } else {
        qreal newY = y() + 3; // Velocidad de caída (ajustar según sea necesario)
        if (newY <= scene()->height() - boundingRect().height() - 30) {
            setY(newY);
            QTimer::singleShot(20, this, &Player::jump);
        } else {
            setY(scene()->height() - boundingRect().height() - 30);
            currentJumpHeight = 0.0;
            isJumping = false;
        }
    }
}

void Player::shoot()
{
    Bala *bala = new Bala(true);
    bala->setPos(x() + 70, y() + 24);
    scene()->addItem(bala);
    setPixmap(QPixmap(":/imagenes/disparandoSinFondo.png").scaled(100, 100, Qt::KeepAspectRatio));
    sonidoDisparo->play();
    temporizadorAux->start(100);
}

void Player::spawn()
{
    game->incrementarNumEnemigos();
    //creamos un enemigo pero si hay mas de 3 enemigos no generamos mas enemigos haciendo la desconexion para dejar de emitir una señal
    if (game->getNumeroDeEnemigos() > 3){
        QObject::disconnect(game->timer, SIGNAL(timeout()), this, SLOT(spawn()));
        // QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    }
    Enemigo *enemigo = new Enemigo();
    //enemigo->setPos(1280,y()+70);
    scene()->addItem(enemigo);
    qDebug() <<"Enemigo añadido";
    //acedemos a game y sumamos uno a enemigo añadido llamando al metodo creado
}

void Player::cambiarImagenAlDisparar()
{
    setPixmap(QPixmap(":/imagenes/movimiento1SinFondo.png").scaled(100, 100, Qt::KeepAspectRatio));
    temporizadorAux->stop();
}
