// gamecharacter.h
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>

class GameCharacter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //PARA MOVIMIENTO Y SLTOS ES LO MISMO
    GameCharacter(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);


private slots:
    //SALTOS
    void updateJump();

private:
    int speed;

    //SALTOS
    bool isJumping;
    double verticalVelocity;
    double gravity;
    double jumpForce;
    double initialY;
    QTimer *jumpTimer;
};









#endif
