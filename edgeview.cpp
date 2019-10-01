#include "edgeview.h"

#include <QDebug>

EdgeView::EdgeView(NodeView* source, NodeView* target, GraphWidget* parent)
            : parent(parent), source(source), target(target)
{
    setAcceptedMouseButtons(nullptr); // do not allow to be clicked for now
    adaptChanges();
}

NodeView* EdgeView::getSource() const
{
    return source;
}

NodeView* EdgeView::getTarget() const
{
    return target;
}

void EdgeView::adaptChanges()
{
    startPoint = QGraphicsItem::mapFromItem(source, source->getCenter());
    endPoint = QGraphicsItem::mapFromItem(target, target->getCenter());
    this->update();
}

QRectF EdgeView::boundingRect() const
{
    return QRectF(startPoint, QSizeF(endPoint.x() - startPoint.x(), endPoint.y() - startPoint.y())).normalized();
}

void EdgeView::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    QLineF line(startPoint, endPoint);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
}
