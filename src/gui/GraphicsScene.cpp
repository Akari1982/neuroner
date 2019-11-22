#include "GraphicsScene.h"

#include <QGraphicsItem>
#include <QtWidgets>



GraphicsScene::GraphicsScene( QObject* parent ):
    QGraphicsScene( parent )
{
    m_Container = new ElementContainer();
    addItem( m_Container );
}



GraphicsScene::~GraphicsScene()
{
}



void
GraphicsScene::Update()
{
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
    event->accept();
}



void
GraphicsScene::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    event->accept();
}



void
GraphicsScene::mouseMoveEvent( QGraphicsSceneMouseEvent* event )
{
    event->accept();
}



void
GraphicsScene::keyPressEvent( QKeyEvent* event )
{
    event->accept();
}
