#ifndef FONDOMOVIDO_H
#define FONDOMOVIDO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class FondoMovido : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit FondoMovido(const QString &imagePath1, const QString &imagePath2, QGraphicsItem *parent = nullptr);
    void startMoving();

private slots:
    void move();

private:
    QTimer *timer;
    QPixmap pixmap1, pixmap2;
    int currentImage;
    qreal initialPosX; // Posición inicial de la primera image

};

#endif // FONDOMOVIDO_H
