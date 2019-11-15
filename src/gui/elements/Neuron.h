#ifndef NEURON_H
#define NEURON_H

#include "../Element.h"

class Connect;
class Line;



class Neuron : public Element
{
public:
    Neuron();
    virtual ~Neuron();

    Element* Copy();

    QRectF boundingRect() const override;
    void paint( QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget ) override;

    void Update();
    void Trace( Line* line, Connect* connect );
    void SetValue( const int value, Connect* connect );
};



#endif // NEURON_H
