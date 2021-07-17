#include "shooting.hpp"

#include "screeneventhanlderfactory.hpp"

#include <QDebug>

namespace QWarhammerSimulator::Gui::ScreenEventHandler
{

bool Shooting::onClick(const QPoint& pos, const Qt::MouseButtons buttons)
{
    qDebug() << "Shooting::onClick(" << pos << ", " << buttons << ")";
    return false;
}

const bool Shooting::c_is_registered
    = ScreenEventHandlerFactory::registerHandler(LibWarhammerEngine::TurnPhase::Shooting, std::make_unique<Shooting>());

} // namespace QWarhammerSimulator::Gui::ScreenEventHandler
