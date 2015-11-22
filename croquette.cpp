#include "croquette.h"

Croquette::Croquette(QPointF position)
{
QPixmap imageCroquette;
imageCroquette.load(":/Sprites/sprites.qrc/res/croquette.png");
modeleGraphique=new ModeleG(position,imageCroquette);
nbPoint=10;
}

