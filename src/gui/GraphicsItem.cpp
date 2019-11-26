#include "GraphicsItem.h"
#include "GraphicsScene.h"

#include <QtWidgets>



GraphicsItem::GraphicsItem():
    m_Circuit( 0 )
{
}



GraphicsItem::~GraphicsItem()
{
}




void
GraphicsItem::SetCircuit( GraphicsScene* circuit )
{
    m_Circuit = circuit;
}



GraphicsItem::ItemType
GraphicsItem::GetType() const
{
    return m_ItemType;
}
