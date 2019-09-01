#pragma once

#include <QGraphicsView>

class NodeView;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GraphWidget();
    GraphWidget(QWidget* parent);
};
