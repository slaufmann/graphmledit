#pragma once

#include "edgeview.h"
#include "graphwidget.h"

#include <QGraphicsItem>
#include <QList>

class NodeView : public QGraphicsItem
{
public:
    NodeView(GraphWidget* parent);

    void addEdge(EdgeView* edge);

    QPointF getCenter() const;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    GraphWidget* parent;
    QList<EdgeView*> edges;
};
