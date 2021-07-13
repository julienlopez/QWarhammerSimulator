#include "header.hpp"

#include "game.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

namespace QWarhammerSimulator::Gui
{

Header::Header(const LibWarhammerEngine::Game& game, QWidget* parent)
    : QWidget(parent)
    , m_game(game)
{
    setFixedHeight(100);

    auto* lay = new QHBoxLayout;
    lay->setSpacing(0);
    lay->setContentsMargins(0, 0, 0, 0);
    for(std::size_t i = 0; i < m_widgets.size(); i++)
    {
        m_widgets[i] = setupPlayerWidget(i);
        lay->addWidget(m_widgets[i]);
    }
    setLayout(lay);
    updateGame();
}

void Header::updateGame()
{

}

QWidget* Header::setupPlayerWidget(const std::size_t player_index)
{
    auto* w = new QFrame;
    auto* hl = new QVBoxLayout;
    auto* army_name = new QLabel(QString::fromStdString(m_game.army(player_index).name));
    hl->addWidget(army_name, 0, Qt::AlignCenter);
    auto* lay = new QHBoxLayout;
    lay->addWidget(new QPushButton(tr("Mo")));
    lay->addWidget(new QPushButton(tr("Ma")));
    lay->addWidget(new QPushButton(tr("Sh")));
    lay->addWidget(new QPushButton(tr("CC")));
    hl->addLayout(lay);
    w->setLayout(hl);
    w->setFrameStyle(QFrame::Box | QFrame::Raised);
    return w;
}

} // namespace QWarhammerSimulator::Gui
