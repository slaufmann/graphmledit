#pragma once

#include "graphwidget.h"

#include <QGraphicsItem>

class NodeView : public QGraphicsItem
{
public:
    NodeView(GraphWidget* parent);

private:
    GraphWidget* parent;
};
