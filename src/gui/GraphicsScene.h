#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H

#include <QGraphicsScene>

#include "../model/ElementContainer.h"



class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene( QObject* parent );
    virtual ~GraphicsScene();

    void Update();

    ElementContainer* GetContainer();

protected:
    void drawBackground( QPainter* painter, const QRectF& rect );
    void drawForeground( QPainter* painter, const QRectF& rect );

    void mousePressEvent( QGraphicsSceneMouseEvent* event );
    void mouseReleaseEvent( QGraphicsSceneMouseEvent* event );
    void mouseMoveEvent( QGraphicsSceneMouseEvent* event );
    void keyPressEvent( QKeyEvent* event );

private:
    ElementContainer* m_Container;
};



extern GraphicsScene* test_circuit;



#endif // GRAPHICS_SCENE_H
