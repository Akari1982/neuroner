#ifndef ELEMENT_NEURON_H
#define ELEMENT_NEURON_H

#include "Element.h"

class Connect;
class Line;



class ElementNeuron : public Element
{
public:
    ElementNeuron( ElementContainer* parent );
    virtual ~ElementNeuron();

    Element* Copy();

    QRectF boundingRect() const override;
    void paint( QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget ) override;

    void Update();
};



#endif // ELEMENT_NEURON_H
