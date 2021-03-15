#include "header.hpp"

#include "game.hpp"

namespace QWarhammerSimulator::Gui
{

Header::Header(const LibWarhammerEngine::Game& game, QWidget* parent)
    : QWidget(parent)
    , m_game(game)
{
}

} // namespace QWarhammerSimulator::Gui
