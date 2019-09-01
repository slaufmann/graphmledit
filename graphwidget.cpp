#include "graphwidget.h"
#include "nodeview.h"

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
