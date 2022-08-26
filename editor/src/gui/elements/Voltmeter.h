#ifndef VOLTMETER_H
#define VOLTMETER_H

#include "../Element.h"
#include <QtCharts/QtCharts>

class Connect;
class Line;



class Voltmeter : public Element
{
public:
    Voltmeter();
    virtual ~Voltmeter();

    Element* Copy();

    QRectF boundingRect() const override;
    void paint( QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget ) override;

    void Update();
    void Trace( Line* line, Connect* connect );
    void SetValue( const int value, Connect* connect );

private:
    QChart* m_Chart;
    QLineSeries* m_Series;
};



#endif // VOLTMETER_H
