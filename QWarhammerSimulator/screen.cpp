#include "screen.hpp"

#include "game.hpp"

namespace QWarhammerSimulator::Gui
{

Screen::Screen(const LibWarhammerEngine::Game& game, QWidget* parent)
    : QWidget(parent)
    , m_game(game)
{
}

} // namespace QWarhammerSimulator::Gui
