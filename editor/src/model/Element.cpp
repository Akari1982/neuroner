#include "Element.h"

#include <QtWidgets>



Element::Element( ElementContainer* parent ):
    m_Container( parent )
{
    setFlags( ItemIsSelectable | ItemIsMovable | ItemIsFocusable | ItemSendsGeometryChanges );

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



QVariant
Element::itemChange( GraphicsItemChange change, const QVariant& value )
{
    if( change == ItemPositionChange )
    {
        QPoint pos = value.toPoint();
        int rem = pos.x() % 15;
        if( rem > 7 )
        {
            pos.rx() += 15 - rem;
        }
        else if( rem < -7 )
        {
            pos.rx() -= 15 + rem;
        }
        else
        {
            pos.rx() -= rem;
        }
        rem = pos.y() % 15;
        if( rem > 7 )
        {
            pos.ry() += 15 - rem;
        }
        else if( rem < -7 )
        {
            pos.ry() -= 15 + rem;
        }
        else
        {
            pos.ry() -= rem;
        }
        return pos;
    }
    return QGraphicsItem::itemChange( change, value );
}
