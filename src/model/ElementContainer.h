#ifndef ELEMENT_CONTAINER_H
#define ELEMENT_CONTAINER_H

#include "Element.h"



class ElementContainer : public Element
{
public:
    ElementContainer();
    virtual ~ElementContainer();

    ElementContainer* Copy();

    QRectF boundingRect() const override;
    void paint( QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget ) override;

    void Update();
};



#endif // ELEMENT_CONTAINER_H
