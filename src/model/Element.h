#ifndef ELEMENT_H
#define ELEMENT_H

#include "../gui/GraphicsItem.h"



class Element : public GraphicsItem
{
public:
    Element();
    virtual ~Element();

    virtual Element* Copy() = 0;

    virtual void Update() = 0;

protected:
    void mousePressEvent( QGraphicsSceneMouseEvent* event ) override;
    void mouseReleaseEvent( QGraphicsSceneMouseEvent* event ) override;
    void mouseMoveEvent( QGraphicsSceneMouseEvent* event ) override;

protected:
};



#endif // ELEMENT_H
