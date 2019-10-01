#pragma once

#include <QGraphicsView>
#include <QKeyEvent>
#include <QList>
#include <QWheelEvent>

class NodeView;
class EdgeView;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GraphWidget();
    GraphWidget(QWidget* parent);

    void itemMoved();
    void scaleView(qreal scaleFactor);
    void keyPressEvent(QKeyEvent* event);
    void wheelEvent(QWheelEvent* event);

private:
    void zoomReset();

    QList<EdgeView*> edges;
};
