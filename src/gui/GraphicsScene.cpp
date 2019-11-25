#include "GraphicsScene.h"

#include <QGraphicsItem>
#include <QtWidgets>



GraphicsScene::GraphicsScene( QObject* parent ):
    QGraphicsScene( parent )
{
    m_Container = new ElementContainer();
    m_Container->SetToScene( this );
}



GraphicsScene::~GraphicsScene()
{
}



void
GraphicsScene::Update()
{
    m_Container->Update();
}



ElementContainer*
GraphicsScene::GetContainer()
{
    return m_Container;
}



void
GraphicsScene::drawBackground( QPainter* painter, const QRectF& rect )
{
    Q_UNUSED( painter );
    Q_UNUSED( rect );
}



void
GraphicsScene::drawForeground( QPainter* painter, const QRectF& rect )
{
    QGraphicsScene::drawForeground( painter, rect );
}



void
GraphicsScene::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
    QGraphicsScene::mousePressEvent( event );

    Element* item = ( Element* )itemAt( event->scenePos(), ( ( QGraphicsView* )event->widget()->parentWidget() )->viewportTransform() );
    if( item != NULL )
    {
        if( item->GetType() == GraphicsItem::IT_CONTAINER )
        {
            clear();
            m_Container = ( ElementContainer* )item;
            m_Container->SetToScene( this );
        }
    }
}



void
GraphicsScene::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    QGraphicsScene::mouseReleaseEvent( event );
}



void
GraphicsScene::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
    QGraphicsScene::mouseMoveEvent( event );
}



void
GraphicsScene::mouseDoubleClickEvent( QGraphicsSceneMouseEvent* event )
{
    QGraphicsScene::mouseDoubleClickEvent( event );

    Element* item = ( Element* )itemAt( event->scenePos(), ( ( QGraphicsView* )event->widget()->parentWidget() )->viewportTransform() );
    if( item->GetType() == GraphicsItem::IT_CONTAINER )
    {
        m_Container = ( ElementContainer* )item;
        m_Container->SetToScene( this );
    }
}



void
GraphicsScene::keyPressEvent( QKeyEvent* event )
{
    event->accept();
}
