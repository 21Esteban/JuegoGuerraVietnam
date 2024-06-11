#include "fondomovido.h"
#include <QGraphicsScene>

FondoMovido::FondoMovido(const QString &imagePath1, const QString &imagePath2, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), timer(new QTimer(this)), currentImage(1), initialPosX(0) {
    // Cargar y escalar las imágenes una vez
    pixmap1.load(imagePath1);
    pixmap2.load(imagePath2);
    pixmap1 = pixmap1.scaled(1280, 720);
    pixmap2 = pixmap2.scaled(1280, 720);

    setPixmap(pixmap1); // Inicia con la primera imagen
    connect(timer, &QTimer::timeout, this, &FondoMovido::move);
}

void FondoMovido::startMoving() {
    timer->start(20); // Ajustar según sea necesario para la velocidad de movimiento
}

void FondoMovido::move() {
    qreal speed = 10; // Ajustar según sea necesario
    initialPosX -= speed; // Mueve la imagen hacia la izquierda

    // Verificar si la imagen necesita cambiar
    if (initialPosX <= -pixmap().width()) {
        initialPosX += pixmap().width(); // Reposiciona para el bucle continuo
        currentImage = (currentImage == 1) ? 2 : 1; // Cambia la imagen actual
    }

    // Cambiar la imagen cuando se acerca al borde izquierdo
    if (initialPosX <= 0 && initialPosX > -pixmap().width() + speed) {
        setPixmap(currentImage == 1 ? pixmap1 : pixmap2);
    }

    setPos(initialPosX, y());
}
