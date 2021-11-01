#pragma once

class QPainter;
class QPoint;

namespace QWarhammerSimulator
{

namespace LibGeometry
{
    struct Point;
    struct Rectangle;
}

namespace Gui::Utils
{

    QPoint fromPoint(const LibGeometry::Point& point);

    void drawRectangle(QPainter& p, const LibGeometry::Rectangle& rect);

} // namespace Gui::Utils

} // namespace QWarhammerSimulator
