#pragma once

#include "commandpanel.hpp"

#include "phase_specific_command_panel/shooting_command_panel.hpp"

#include "game.hpp"

#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>

namespace QWarhammerSimulator::Gui
{

CommandPanel::CommandPanel(const LibWarhammerEngine::Game& game, QWidget* parent)
    : QWidget(parent)
    , m_game(game)
{
    setFixedWidth(300);

    auto* lay = new QVBoxLayout;
    lay->addStretch();

    lay->addWidget(createTurnPhaseSpecificPanel());

    auto* end_phase_button = new QPushButton(tr("End Phase"));
    connect(end_phase_button, &QPushButton::clicked, this, &CommandPanel::endPhasePressed);
    connect(end_phase_button, &QPushButton::clicked, this, &CommandPanel::updatePhaseSpecificPanel);
    lay->addWidget(end_phase_button);

    setLayout(lay);
}

QWidget* CommandPanel::createTurnPhaseSpecificPanel()
{
    m_turnphase_specific_widgets[LibWarhammerEngine::TurnPhase::Shooting]
        = new PhaseSpecificCommandPanel::ShootingCommandPanel{};
    m_turnphase_specific_panel = new QStackedWidget;
    for(const auto turn_phase : m_turnphase_specific_widgets)
    {
        m_turnphase_specific_panel->insertWidget(static_cast<int>(turn_phase.first), turn_phase.second);
    }
    return m_turnphase_specific_panel;
}

void CommandPanel::updatePhaseSpecificPanel()
{
    const auto it = m_turnphase_specific_widgets.find(m_game.currentPhase());
    if(it == end(m_turnphase_specific_widgets)) return;
    m_turnphase_specific_panel->setCurrentIndex(static_cast<int>(it->first));
}

} // namespace QWarhammerSimulator::Gui
