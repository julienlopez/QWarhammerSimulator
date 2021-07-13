#include "playerheader.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

using QWarhammerSimulator::LibWarhammerEngine::TurnPhase;

namespace QWarhammerSimulator::Gui
{

PlayerHeader::PlayerHeader(const QString& label, QWidget* parent)
    : QFrame(parent)
{
    auto* hl = new QVBoxLayout;
    hl->addWidget(new QLabel(label), 0, Qt::AlignCenter);
    auto* lay = new QHBoxLayout;
    lay->addWidget(createPhaseWidget(TurnPhase::Movement, tr("Mo")));
    lay->addWidget(createPhaseWidget(TurnPhase::Magic, tr("Ma")));
    lay->addWidget(createPhaseWidget(TurnPhase::Shooting, tr("Sh")));
    lay->addWidget(createPhaseWidget(TurnPhase::CloseCombat, tr("CC")));
    hl->addLayout(lay);
    setLayout(hl);
    setFrameStyle(QFrame::Box);
}

void PlayerHeader::setIsHighlighted(bool is_highlighted)
{
    setFrameStyle(QFrame::Box | (is_highlighted ? QFrame::Raised : 0));
}

void PlayerHeader::setCurrentPhase(TurnPhase turn_phase)
{
    for(const auto& p : m_phase_widgets)
        p.second->setChecked(p.first == turn_phase);
}

QPushButton* PlayerHeader::createPhaseWidget(TurnPhase turn_phase, const QString& label)
{
    auto* res = new QPushButton(label);
    res->setCheckable(true);
    res->setChecked(false);
    m_phase_widgets[turn_phase] = res;
    return res;
}

} // namespace QWarhammerSimulator::Gui
