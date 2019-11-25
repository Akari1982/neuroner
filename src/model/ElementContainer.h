#ifndef ELEMENT_CONTAINER_H
#define ELEMENT_CONTAINER_H

#include "Element.h"

#include <vector>

class GraphicsScene;



class ElementContainer : public Element
{
public:
    ElementContainer();
    virtual ~ElementContainer();

    ElementContainer* Copy();

    QRectF boundingRect() const override;
    void paint( QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget ) override;

    void Update();

    void SetToScene( GraphicsScene* scene );

    void InsertContainer();

private:
    std::vector< Element* > m_Elements;

    GraphicsScene* m_Scene;

    int counter;
};



#endif // ELEMENT_CONTAINER_H
