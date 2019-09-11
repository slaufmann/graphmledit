#pragma once

#include <graphwidget.h>

#include "nodeview.h"

class EdgeView : public QGraphicsItem
{
public:
    EdgeView(NodeView* source, NodeView* target, GraphWidget* parent);

    NodeView* getSource() const;
    NodeView* getTarget() const;

    void update();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    GraphWidget* parent;
    NodeView* source;
    NodeView* target;
    QPointF startPoint, endPoint;
};
