#include "graphwidget.h"
#include "nodeview.h"

#include <math.h>

GraphWidget::GraphWidget()
                : GraphWidget(nullptr)
{}

GraphWidget::GraphWidget(QWidget* parent)
                : QGraphicsView (parent)
{
    QGraphicsScene* scene = new QGraphicsScene(this);

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 400, 400);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(1.0), qreal(1.0));
    setMinimumSize(400, 400);
    setWindowTitle(tr("GraphML Editor"));

    NodeView* node1 = new NodeView(this);
    scene->addItem(node1);
}

void GraphWidget::scaleView(qreal scaleFactor) {
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;
    scale(scaleFactor, scaleFactor);
}

void GraphWidget::keyPressEvent(QKeyEvent* event) {
    // for now we only recognize inputs with the control modifier
    if (event->modifiers() == Qt::ControlModifier) {
        switch (event->key()) {
            case Qt::Key_0:
                zoomReset();
                break;
            default:
                QGraphicsView::keyPressEvent(event);
        }
    } else
        QGraphicsView::keyPressEvent(event);
}

void GraphWidget::wheelEvent(QWheelEvent* event) {
    scaleView(pow(2.0, event->delta() / 240.0));
}

void GraphWidget::zoomReset() {
    setTransform(QTransform());
}
