#pragma once

#include "iscreeneventhanlder.hpp"

#include <boost/optional.hpp>

namespace QWarhammerSimulator
{

namespace LibWarhammerEngine
{
    class Army;
}

namespace Gui::ScreenEventHandler
{

    class Shooting : public IScreenEventHandler
    {
    public:
        explicit Shooting() = default;

        virtual ~Shooting() = default;

        virtual bool onClick(const LibWarhammerEngine::Game& game, const QPoint& pos,
                             const Qt::MouseButtons buttons) override;

        virtual bool drawAdditionalStates(const LibWarhammerEngine::Game& game, QPainter& p) const override;

    private:
        boost::optional<std::size_t> unitIndex(const LibWarhammerEngine::Army& army, const QPoint& pos) const;

        static const bool c_is_registered;

        boost::optional<std::size_t> m_current_selection;
    };

} // namespace Gui::ScreenEventHandler

} // namespace QWarhammerSimulator
