#pragma once

#include <QPoint>

namespace QWarhammerSimulator::Gui::ScreenEventHandler
{

class IScreenEventHandler
{
protected:
    explicit IScreenEventHandler() = default;

public:
    virtual ~IScreenEventHandler() = default;

    virtual bool onClick(const QPoint& pos, const Qt::MouseButtons buttons) = 0;
};

} // namespace QWarhammerSimulator::Gui::ScreenEventHandler
