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
    QGraphicsItem::mousePressEvent( event );
}



void
Element::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    QGraphicsItem::mouseReleaseEvent( event );
}



void
Element::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
    QGraphicsItem::mouseMoveEvent( event );
}
