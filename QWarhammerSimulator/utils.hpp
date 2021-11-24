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
    class Unit;
} // namespace LibWarhammerEngine

namespace Gui
{
    struct Selection;
    struct SelectionWithColor;

    namespace Utils
    {

        QPoint fromPoint(const LibGeometry::Point& point);

        void drawRectangle(QPainter& p, const LibGeometry::Rectangle& rect);

        void paintSelection(QPainter& painter, const LibWarhammerEngine::Game& game,
                            const SelectionWithColor& selection);

        const LibWarhammerEngine::Unit& getUnit(const LibWarhammerEngine::Game& game, const Selection& selection);

    } // namespace Utils

} // namespace Gui

} // namespace QWarhammerSimulator
