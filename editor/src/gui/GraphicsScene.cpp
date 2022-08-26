#include "GraphicsScene.h"

#include <QGraphicsItem>
#include <QtWidgets>



GraphicsScene::GraphicsScene( QObject* parent ):
    QGraphicsScene( parent )
{
    m_RootContainer = new ElementContainer( NULL );
    m_CurrentContainer = m_RootContainer;
    m_RootContainer->SetScene( this );
}



GraphicsScene::~GraphicsScene()
{
}



void
GraphicsScene::Update()
{
    if( m_CurrentContainer != NULL )
    {
        m_CurrentContainer->Update();
    }
}



ElementContainer*
GraphicsScene::GetCurrentContainer()
{
    return m_CurrentContainer;
}



void
GraphicsScene::drawBackground( QPainter* painter, const QRectF& rect )
{
    Q_UNUSED( painter )
    Q_UNUSED( rect )
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
    //QGraphicsScene::mouseDoubleClickEvent( event );

    if( event->buttons() & Qt::RightButton )
    {
        ElementContainer* container = m_CurrentContainer->GetParentContainer();
        if( container != NULL )
        {
            m_CurrentContainer->UnsetScene();
            m_CurrentContainer = container;
            m_CurrentContainer->SetScene( this );
        }
    }
    else if( event->buttons() & Qt::LeftButton )
    {
        Element* item = ( Element* )itemAt( event->scenePos(), ( ( QGraphicsView* )event->widget()->parentWidget() )->viewportTransform() );
        if( item != NULL )
        {
            if( item->GetType() == GraphicsItem::IT_CONTAINER )
            {
                m_CurrentContainer->UnsetScene();
                m_CurrentContainer = ( ElementContainer* )item;
                m_CurrentContainer->SetScene( this );
            }
        }
    }
}



void
GraphicsScene::keyPressEvent( QKeyEvent* event )
{
    event->accept();
}
