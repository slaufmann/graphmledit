#pragma once

#include <QGraphicsView>
#include <QKeyEvent>
#include <QWheelEvent>

class NodeView;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GraphWidget();
    GraphWidget(QWidget* parent);

    void scaleView(qreal scaleFactor);
    void keyPressEvent(QKeyEvent* event);
    void wheelEvent(QWheelEvent* event);

private:
    void zoomReset();
};
