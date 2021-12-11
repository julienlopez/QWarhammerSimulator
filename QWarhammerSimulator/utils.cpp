#include "utils.hpp"

#include "rectangle.hpp"

#include "game.hpp"

#include "selection.hpp"

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

void paintSelection(QPainter& painter, const LibWarhammerEngine::Game& game, const SelectionWithColor& selection)
{
    const auto& unit = getUnit(game, selection.selection);
    painter.save();
    auto pen = painter.pen();
    pen.setColor(selection.color);
    pen.setWidthF(selection.width);
    painter.setPen(pen);
    Utils::drawRectangle(painter, unit.rectangle());
    for(const auto& model_index : selection.selection.models)
    {
        pen.setWidthF(0.1);
        painter.setPen(pen);
        Utils::drawRectangle(painter, unit.modelRectangle(model_index));
    }
    painter.restore();
}

const LibWarhammerEngine::Unit& getUnit(const LibWarhammerEngine::Game& game, const Selection& selection)
{
    return game.army(selection.unit_index.player_index).m_units[selection.unit_index.unit_index];
}

} // namespace QWarhammerSimulator::Gui::Utils
