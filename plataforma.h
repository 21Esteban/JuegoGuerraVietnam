#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include <QObject>
#include <QGraphicsRectItem>

class Plataforma : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Plataforma(QObject *parent = nullptr);

signals:
};

#endif // PLATAFORMA_H
