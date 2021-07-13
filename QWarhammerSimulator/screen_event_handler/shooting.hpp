#pragma once

#include "iscreeneventhanlder.hpp"

namespace QWarhammerSimulator::Gui::ScreenEventHandler
{

class Shooting : public IScreenEventHandler
{
public:
    explicit Shooting() = default;

    virtual ~Shooting() = default;

    virtual bool onClick(const QPoint& pos, const Qt::MouseButtons buttons) override;
};

} // namespace QWarhammerSimulator::Gui::ScreenEventHandler
