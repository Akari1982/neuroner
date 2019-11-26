#include "ElementContainer.h"

#include "../gui/GraphicsScene.h"

#include <QtWidgets>



ElementContainer::ElementContainer( ElementContainer* parent ):
    Element( parent ),
    m_Scene( NULL )
{
    m_ItemType = IT_CONTAINER;

    counter = 0;
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
    ElementContainer* element = new ElementContainer( GetParentContainer() );
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

    QFont font( "Times", 10 );
    font.setStyleStrategy( QFont::ForceOutline );
    painter->setFont( font );
    painter->save();
    painter->scale( 1, 1 );
    painter->drawText( 0, 0, QString("Counter: %1").arg( counter) );
    painter->restore();

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
    ++counter;

    for( size_t i = 0; i < m_Elements.size(); ++i )
    {
        m_Elements[ i ]->Update();
    }
}



void
ElementContainer::SetScene( GraphicsScene* scene )
{
    m_Scene = scene;

    for( size_t i = 0; i < m_Elements.size(); ++i )
    {
        m_Scene->addItem( m_Elements[ i ] );
    }
}



void
ElementContainer::UnsetScene()
{
    for( size_t i = 0; i < m_Elements.size(); ++i )
    {
        m_Scene->removeItem( m_Elements[ i ] );
    }

    m_Scene = NULL;
}



void
ElementContainer::InsertContainer()
{
    Element* element = new ElementContainer( this );
    m_Elements.push_back( element );

    if( m_Scene != NULL )
    {
        m_Scene->addItem( element );
    }
}
