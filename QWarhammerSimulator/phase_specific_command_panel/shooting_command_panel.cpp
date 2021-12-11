#include "shooting_command_panel.hpp"

#include "turnphase.hpp"

#include "../screen_event_handler/iscreeneventhanlder.hpp"
#include "../screen_event_handler/screeneventhanlderfactory.hpp"

#include <QLabel>
#include <QVBoxLayout>

#include <QDebug>

namespace QWarhammerSimulator::Gui::PhaseSpecificCommandPanel
{

ShootingCommandPanel::ShootingCommandPanel(QWidget* parent)
    : QWidget(parent)
{
    auto* lay = new QVBoxLayout;
    lay->addWidget(new QLabel(tr("Shooter:")));
    lay->addWidget(new QLabel(tr("Target")));
    setLayout(lay);

    ScreenEventHandler::ScreenEventHandlerFactory::get(LibWarhammerEngine::TurnPhase::Shooting)
        .map([this](ScreenEventHandler::IScreenEventHandler* event_handler)
            { 
                event_handler->onUpdate([this]() { updateValues(); });
                return true;
            });
}

void ShootingCommandPanel::updateValues()
{
    qDebug() << "ShootingCommandPanel::updateValues()";
}

} // namespace QWarhammerSimulator::Gui::PhaseSpecificCommandPanel
