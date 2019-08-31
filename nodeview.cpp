#include "nodeview.h"

NodeView::NodeView(GraphWidget* parent)
            : parent(parent)
{}

/**
 * @brief return the bounding rectangle of this node
 * @return rectangle determining the outer border of this node
 *
 * The outer border of a node is determined by its size and the width of the
 * outer stroke.
 * For now the size is a 20x20 square and the stroke width is treated as 2
 * pixels.
 */
QRectF NodeView::boundingRect() const {
    qreal adjust = 2;   // adjust bounding rectangle by stroke width
    return QRectF(-10-adjust, -10-adjust, 10+adjust, 10+adjust);
}
