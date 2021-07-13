#pragma once

#include "commandpanel.hpp"

#include <QPushButton>
#include <QVBoxLayout>

namespace QWarhammerSimulator::Gui
{

CommandPanel::CommandPanel(QWidget* parent)
    : QWidget(parent)
{
    setFixedWidth(300);

    auto* lay = new QVBoxLayout;
    lay->addStretch();

    auto* end_phase_button = new QPushButton(tr("End Phase"));
    connect(end_phase_button, &QPushButton::clicked, this, &CommandPanel::endPhasePressed);
    lay->addWidget(end_phase_button);

    setLayout(lay);
}

} // namespace QWarhammerSimulator::Gui
