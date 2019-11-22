#include "ElementContainer.h"

#include "../gui/Connect.h"
#include "../gui/Line.h"

#include <QtWidgets>



ElementContainer::ElementContainer()
{
}



ElementContainer::~ElementContainer()
{
}



ElementContainer*
ElementContainer::Copy()
{
    ElementContainer* element = new ElementContainer();
}



QRectF
ElementContainer::boundingRect() const
{
    return QRectF( -18, -3, 36, 21 );
}



void
ElementContainer::paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget )
{
    Q_UNUSED( widget );
    painter->setPen( QPen( Qt::black, 4, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin ) );
    painter->setBrush( Qt::NoBrush );
    painter->drawEllipse( -15, -15, 30, 30 );
    painter->setPen( QPen( Qt::black, 2, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin ) );
    // draw dendritic tree
    painter->drawLine( 0, -15, 0, -20 );
    painter->drawLine( 0, -20, -15, -25 );
    painter->drawLine( 0, -20, 15, -25 );
    painter->drawLine( -15, -25, -15, -30 );
    painter->drawLine( 15, -25, 15, -30 );
    // draw axon
    painter->drawLine( 0, 15, 0, 45 );

    // draw connects
    painter->setPen( QPen( CONNECT_COLOR ) );
    painter->setBrush( CONNECT_COLOR );
    painter->drawEllipse( -18, -33, 6, 6 );
    painter->drawEllipse( 12, -33, 6, 6 );
    painter->drawEllipse( -3, 42, 6, 6 );

    if( option->state & QStyle::State_Selected )
    {
        painter->setPen( QPen( Qt::black, 0, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin ) );
        painter->setBrush( QColor( 0, 0, 255, 100 ) );
        painter->drawRect( boundingRect() );
    }
}



void
ElementContainer::Update()
{
}
