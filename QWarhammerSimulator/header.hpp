#pragma once

#include <QWidget>

namespace QWarhammerSimulator::Gui
{

class Header : public QWidget
{
    Q_OBJECT

public:
    explicit Header(QWidget* parent = nullptr);

    virtual ~Header() = default;

private:
};

} // namespace QWarhammerSimulator::Gui
