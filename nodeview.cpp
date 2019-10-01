#include "nodeview.h"

NodeView::NodeView(GraphWidget* parent)
            : parent(parent)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}

QVariant NodeView::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
        case ItemPositionHasChanged:
            parent->itemMoved();
            break;
        default:
            break;
    }

    return QGraphicsItem::itemChange(change, value);
}

QPointF NodeView::getCenter() const
{
    return boundingRect().center();
}

/**
 * @brief return the bounding rectangle of this node
 * @return rectangle determining the outer border of this node
 *
 * The outer border of a node is determined by its size and the width of the
 * outer stroke.
 * For now the size is a 20x20 square and the stroke width is treated as 2
 * pixels.
 */
QRectF NodeView::boundingRect() const {
    qreal adjust = 2;   // adjust bounding rectangle by stroke width
    return QRectF(-10-adjust, -10-adjust, 10+adjust, 10+adjust);
}

/**
 * @brief draw this node on the canvas
 * @param painter object that is used to set pen options etc.
 *
 * For now the visual representation of a node is a simple rectengular that
 * is the QRectF as returned by boundingRect(). It is drawn with a black
 * stroke.
 */
void NodeView::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->setPen(QPen(Qt::black, 0));
    painter->drawRect(boundingRect());
}
