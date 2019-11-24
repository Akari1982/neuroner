#include "ElementContainer.h"

#include "../gui/GraphicsScene.h"

#include <QtWidgets>



ElementContainer::ElementContainer():
    m_Scene( NULL )
{
}



ElementContainer::~ElementContainer()
{
    for( size_t i = 0; i < m_Elements.size(); ++i )
    {
        delete m_Elements[ i ];
    }
}



ElementContainer*
ElementContainer::Copy()
{
    ElementContainer* element = new ElementContainer();
    return element;
}



QRectF
ElementContainer::boundingRect() const
{
    return QRectF( -50, -50, 100, 100 );
}



void
ElementContainer::paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget )
{
    Q_UNUSED( widget )
    painter->setPen( QPen( Qt::black, 4, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin ) );
    painter->setBrush( QColor( 219, 214, 121, 255 ) );
    painter->drawRect( QRectF( -45, -45, 90, 90 ) );

    // draw connects
    painter->setPen( QPen( CONNECT_COLOR ) );
    painter->setBrush( CONNECT_COLOR );
    painter->drawEllipse( -18, -48, 6, 6 );
    painter->drawEllipse( 12, -48, 6, 6 );
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
    for( size_t i = 0; i < m_Elements.size(); ++i )
    {
        m_Elements[ i ]->Update();
    }
}



void
ElementContainer::SetToScene( GraphicsScene* scene )
{
    m_Scene = scene;

    for( size_t i = 0; i < m_Elements.size(); ++i )
    {
        m_Scene->addItem( m_Elements[ i ] );
    }
}



void
ElementContainer::InsertContainer()
{
    Element* element = new ElementContainer();
    m_Elements.push_back( element );

    if( m_Scene != NULL )
    {
        m_Scene->addItem( element );
    }
}
