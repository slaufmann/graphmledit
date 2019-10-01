#pragma once

#include "graphwidget.h"

#include <QGraphicsItem>

class NodeView : public QGraphicsItem
{
public:
    NodeView(GraphWidget* parent);

    QPointF getCenter() const;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    GraphWidget* parent;
};
