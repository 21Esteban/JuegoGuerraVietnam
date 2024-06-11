// iniciojuego.cpp
#include "iniciojuego.h"

InicioJuego::InicioJuego(QWidget *parent)
    : QWidget(parent) {
    setFixedSize(1280, 720); // Establece el tamaño de la ventana

    // Cargar la imagen del fondo y escalarla
    QPixmap backgroundImage(":/imagenes/SPRITE/fondo5.jpg");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);

    // Establecer el fondo utilizando la imagen cargada y escalada
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage); // Usar QPalette::Window en lugar de QPalette::Background
    this->setPalette(palette);

    // Botón de iniciar juego
    startButton = new QPushButton("Iniciar Juego", this);
    startButton->setGeometry(590, 280, 100, 50);
    connect(startButton, &QPushButton::clicked, this, &InicioJuego::onStartButtonClicked);

    // Botón de salir del juego
    exitButton = new QPushButton("Salir", this);
    exitButton->setGeometry(600, 355, 80, 30);
    connect(exitButton, &QPushButton::clicked, this, &InicioJuego::onExitButtonClicked);
}

void InicioJuego::onStartButtonClicked() {
    emit startGame();
}

void InicioJuego::onExitButtonClicked() {
    this->close();
}
