#pragma once

#include <QWidget>

class QPainter;

namespace QWarhammerSimulator
{

namespace LibWarhammerEngine
{
    class Game;
    class Unit;
}

namespace Gui
{

    class Screen : public QWidget
    {
        Q_OBJECT

    public:
        explicit Screen(const LibWarhammerEngine::Game& game, QWidget* parent = nullptr);

        virtual ~Screen() = default;

    protected:
        virtual void paintEvent(QPaintEvent* evt) override;

        virtual void resizeEvent(QResizeEvent* evt) override;

        virtual void mouseReleaseEvent(QMouseEvent* evt) override;

    private:
        const LibWarhammerEngine::Game& m_game;
        QPoint m_offset;
        double m_resolution_factor;

        const QSize m_minimum_margin{50,50};

        void drawUnit(QPainter& p, const LibWarhammerEngine::Unit& unit) const;
        
        void drawBoard(QPainter& p) const;

        QPoint screenToBoard(const QPoint& screen_pos) const;
    };

} // namespace Gui

} // namespace QWarhammerSimulator
