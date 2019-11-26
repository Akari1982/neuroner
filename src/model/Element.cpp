#include "Element.h"

#include <QtWidgets>



Element::Element( ElementContainer* parent ):
    m_Container( parent )
{
    setZValue( 2 );

    setPos( qrand() % 1000 - 500, qrand() % 1000 - 500 );
}



Element::~Element()
{
}



ElementContainer*
Element::GetParentContainer()
{
    return m_Container;
}



void
Element::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    if( isSelected() == true )
    {
        QGraphicsItem::mousePressEvent( event );
    }
    else
    {
        event->accept();
    }
}



void
Element::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    if( isSelected() == true )
    {
        QGraphicsItem::mouseReleaseEvent( event );
    }
    else
    {
        event->accept();
    }
}



void
Element::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
    if( isSelected() == true )
    {
        QGraphicsItem::mouseMoveEvent( event );
    }
    else
    {
        event->accept();
    }
}
