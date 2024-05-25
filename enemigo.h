#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include "personaje.h"

class Enemigo :  public QObject , public Personaje
{
    Q_OBJECT
public:
    explicit Enemigo(QObject *parent = nullptr);

public slots:
    void move();

signals:
};

#endif // ENEMIGO_H
