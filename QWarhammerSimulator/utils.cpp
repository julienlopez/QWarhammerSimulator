#include "utils.hpp"

#include "rectangle.hpp"

#include <QPainter>

namespace QWarhammerSimulator::Gui::Utils
{

QPoint fromPoint(const LibGeometry::Point& point)
{
    return {(int)(point.x), (int)(point.y)};
}

void drawRectangle(QPainter& p, const LibGeometry::Rectangle& rect)
{
    p.drawPolyline(QPolygon{fromPoint(rect.topLeft()), fromPoint(rect.topRight()), fromPoint(rect.bottomRight()),
                            fromPoint(rect.bottomLeft()), fromPoint(rect.topLeft())});
}

}
