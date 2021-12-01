#pragma once

#include <turnphase.hpp>

#include <map>

#include <QWidget>

class QStackedWidget;

namespace QWarhammerSimulator
{

namespace LibWarhammerEngine
{
    class Game;
    class Unit;
} // namespace LibWarhammerEngine

namespace Gui
{

    class CommandPanel : public QWidget
    {
        Q_OBJECT

    public:
        explicit CommandPanel(const LibWarhammerEngine::Game& game, QWidget* parent = nullptr);

        virtual ~CommandPanel() = default;

    signals:
        void endPhasePressed();

    private:
        const LibWarhammerEngine::Game& m_game;
        std::map<LibWarhammerEngine::TurnPhase, QWidget*> m_turnphase_specific_widgets;
        QStackedWidget* m_turnphase_specific_panel;

        QWidget* createTurnPhaseSpecificPanel();

        void updatePhaseSpecificPanel();
    };

} // namespace Gui

} // namespace QWarhammerSimulator
