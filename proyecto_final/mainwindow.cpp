// mainwindow.cpp
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Crear la escena y la vista
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    // Configurar la ventana
    setCentralWidget(view);
    setFixedSize(800, 600);

    // Crear y añadir el personaje
    character = new GameCharacter();
    scene->addItem(character);

    // Permitir que el personaje reciba eventos de teclado
    character->setFlag(QGraphicsItem::ItemIsFocusable);
    character->setFocus();
}



