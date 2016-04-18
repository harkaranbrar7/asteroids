#include "rocks.h"
#include <QtCore/qmath.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "mainwindow.h"


extern MainWindow * game; //Global object

//================================== Rocks Constructor =========================================//


rocks::rocks():QObject()
{

//=================Random number for x ========================//

    int random_number = rand () % 700;

//================= set Random Position =======================//

    setPos(random_number,0);

//================== Draw the Rocks ===========================//

    setRect(0,0,50,50);

//============= Create a timer or Connect the rocks============//

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);


}

//================================== Move Function of Rocks =========================================//

void rocks::move()
{

//================== Set the position of rocks===========================//

    setPos(x(), y()+5);

//================== check to remove the rock ==========================//

    if (pos().y() > 600)
        {

            game->health->decrease(); //decrease the health
            scene()->removeItem(this); //remove from the scene
            delete this; //delete the rocks

        }


}

//================================== Spawn and create a rocks=========================================//

void rocks::spawn(){
    rocks * rock = new rocks();//create a rock
    scene()->addItem(rock);//added to scene
}