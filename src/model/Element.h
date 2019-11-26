#ifndef ELEMENT_H
#define ELEMENT_H

#include "../gui/GraphicsItem.h"

class ElementContainer;



class Element : public GraphicsItem
{
public:
    Element( ElementContainer* parent );
    virtual ~Element();

    virtual Element* Copy() = 0;

    virtual void Update() = 0;

    ElementContainer* GetParentContainer();

protected:
    void mousePressEvent( QGraphicsSceneMouseEvent* event ) override;
    void mouseReleaseEvent( QGraphicsSceneMouseEvent* event ) override;
    void mouseMoveEvent( QGraphicsSceneMouseEvent* event ) override;

private:
    ElementContainer* m_Container;
};



#endif // ELEMENT_H
