#include "Voltmeter.h"

#include "../GraphicsScene.h"
#include "../Connect.h"
#include "../Line.h"

#include <QtWidgets>



Voltmeter::Voltmeter()
{
    m_ItemType = IT_VOLTMETER;

    m_Chart = new QChart();

    m_Series = new QLineSeries();
    for( int i = 0; i < 10; ++i )
    {
        m_Series->append( i, i * i );
    }
    //series->setName( "Test" );
    m_Chart->addSeries( m_Series );
    //m_Chart->setTitle( "QT Charts example" );
    m_Chart->layout()->setContentsMargins( 1, 1, 1, 1 );
    m_Chart->setMargins( QMargins() );
    m_Chart->setBackgroundRoundness( 0 );
    m_Chart->setPlotArea( QRectF( -150, -75, 300, 150 ) );
    //m_Chart->setAnimationOptions( QChart::AllAnimations );
    m_Chart->legend()->hide();

    //add axis to the chart
    QValueAxis* axisX = new QValueAxis();
    //axisX->setTickCount( 20 );
    axisX->setLabelFormat( "%i" );
    axisX->setTitleText( "t [ms]" );
    m_Chart->addAxis( axisX, Qt::AlignBottom );
    m_Series->attachAxis( axisX );

    QValueAxis* axisY = new QValueAxis();
    axisY->setLabelFormat( "%i" );
    axisY->setTitleText( "V [mV]" );
    axisY->setMin( -70 );
    axisY->setMax( 130 );
    m_Chart->addAxis( axisY, Qt::AlignLeft );
    m_Series->attachAxis( axisY );

    m_Chart->setParentItem( this );
}



Voltmeter::~Voltmeter()
{
}



Element*
Voltmeter::Copy()
{
    Element* element = new Voltmeter();
    return element;
}



QRectF
Voltmeter::boundingRect() const
{
    return QRectF( -200, -100, 400, 200 );
}



void
Voltmeter::paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget )
{
    //Q_UNUSED( widget );
    if( option->state & QStyle::State_Selected )
    {
        painter->setPen( QPen( Qt::black, 0, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin ) );
        painter->setBrush( QColor( 0, 0, 255, 100 ) );
        painter->drawRect( boundingRect() );
    }
}



void
Voltmeter::Update()
{
    //m_Series->append( m_Series->at( m_Series->count() - 1 ).x() + 1, 100 );
    //m_Series->remove( 0 );
    //m_Chart->axisX()->setRange( m_Series->at( 0 ).x(), m_Series->count() );
}



void
Voltmeter::Trace( Line* line, Connect* connect )
{
    m_Visited = true;
}



void
Voltmeter::SetValue( const int value, Connect* connect )
{
}
