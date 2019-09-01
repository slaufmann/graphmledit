#pragma once

#include "graphwidget.h"

#include <QGraphicsItem>

class NodeView : public QGraphicsItem
{
public:
    NodeView(GraphWidget* parent);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    GraphWidget* parent;
};
