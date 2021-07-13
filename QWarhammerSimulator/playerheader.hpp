#pragma once

#include "turnphasemanager.hpp"

#include <QFrame>

class QPushButton;

namespace QWarhammerSimulator::Gui
{

class PlayerHeader : public QFrame
{
public:
    explicit PlayerHeader(const QString& label, QWidget* parent = nullptr);

    virtual ~PlayerHeader() = default;

public slots:
    void setIsHighlighted(const bool is_highlighted);

    void setCurrentPhase(const LibWarhammerEngine::TurnPhase turn_phase);

private:
    std::map<LibWarhammerEngine::TurnPhase, QPushButton*> m_phase_widgets;

    QPushButton* createPhaseWidget(const LibWarhammerEngine::TurnPhase turn_phase, const QString& label);
};

} // namespace QWarhammerSimulator::Gui
