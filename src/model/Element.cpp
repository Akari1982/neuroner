#include "Element.h"

#include <QtWidgets>



Element::Element()
{
    setZValue( 2 );

    setPos( qrand() % 1000 - 500, qrand() % 1000 - 500 );
}



Element::~Element()
{
}



void
Element::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}



void
Element::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    this->setCursor(QCursor(Qt::ArrowCursor));
}



void
Element::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
    this->setPos(mapToScene(event->pos()));
}
