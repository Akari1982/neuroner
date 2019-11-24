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
}



void
GraphicsScene::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
}



void
GraphicsScene::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
}



void
GraphicsScene::keyPressEvent( QKeyEvent* event )
{
    event->accept();
}
