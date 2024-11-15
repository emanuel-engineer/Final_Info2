
#include "gamecharacter.h"

GameCharacter::GameCharacter(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    // Cargar el sprite desde un archivo
    setPixmap(QPixmap(":/sprites/character.png"));
    speed = 10;  // Velocidad de movimiento en píxeles


    //SALTO
    // Configurar variables de salto
    isJumping = false;
    verticalVelocity = 0;
    gravity = 0.8;        // Ajusta este valor para cambiar la gravedad
    jumpForce = -15;      // Ajusta este valor para cambiar la altura del salto

    // Configurar timer para actualizar el salto
    jumpTimer = new QTimer(this);
    connect(jumpTimer, &QTimer::timeout, this, &GameCharacter::updateJump);
    jumpTimer->start(16); // 60 FPS aproximadamente
}


/*TO DO::
-hacer que solo se pueda mover hacia los lados
-arreglar el salto para que no caiga más de lo necesario


*/
void GameCharacter::keyPressEvent(QKeyEvent *event)
{
    // Mover el personaje según la tecla presionada
    switch(event->key()) {
    case Qt::Key_Left:
        setPos(x() - speed, y());
        break;
    case Qt::Key_Right:
        setPos(x() + speed, y());
        break;
    case Qt::Key_Up:
        //NO SE VA A USAR
        //setPos(x(), y() - speed);
        break;
    case Qt::Key_Down:
        //TODO:: Crear funcion que haga que bart se agache, cambiando el sprite.
        //setPos(x(), y() + speed);

        break;
    //SALTO
    case Qt::Key_Space: // Tecla de salto
        if (!isJumping) {
            isJumping = true;
            verticalVelocity = jumpForce;
            initialY = y();

        }
        break;
    }
}


//SALTO UPDATE
void GameCharacter::updateJump()
{



    if (isJumping) {
        // Aplicar gravedad
        verticalVelocity += gravity;
        // Actualizar posición
        setPos(x(), y() + verticalVelocity);

        // Verificar si el personaje ha vuelto a la posición inicial
        if (y() >= initialY) {
            setPos(x(), initialY);
            isJumping = false;
            verticalVelocity = 0;
        }
    }
}
