#pragma once

#include <QPoint>

namespace QWarhammerSimulator::Gui
{

class IScreenEventHandler
{
protected:
    explicit IScreenEventHandler() = default;

public:
    virtual ~IScreenEventHandler() = default;

    virtual bool onClick(const QPoint& pos) = 0;
};

} // namespace QWarhammerSimulator::Gui
