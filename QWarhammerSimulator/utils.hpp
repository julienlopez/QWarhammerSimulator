#pragma once

class QColor;
class QPainter;
class QPoint;

namespace QWarhammerSimulator
{

namespace LibGeometry
{
    struct Point;
    struct Rectangle;
} // namespace LibGeometry

namespace LibWarhammerEngine
{
    class Game;
}

namespace Gui
{
    struct Selection;

    namespace Utils
    {

        QPoint fromPoint(const LibGeometry::Point& point);

        void drawRectangle(QPainter& p, const LibGeometry::Rectangle& rect);

        void paintSelection(QPainter& painter, const LibWarhammerEngine::Game& game, const Selection& selection,
                            const QColor& color);

    } // namespace Utils

} // namespace Gui

} // namespace QWarhammerSimulator
