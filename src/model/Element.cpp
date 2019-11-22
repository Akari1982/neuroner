#include "Element.h"

#include <QtWidgets>



Element::Element()
{
    setZValue( 2 );
}



Element::~Element()
{
}



void
Element::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    if( isSelected() == true )
    {
        event->accept();
    }
}



void
Element::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
}



void
Element::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
}
