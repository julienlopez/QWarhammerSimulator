#pragma once

#include <QWidget>

namespace QWarhammerSimulator::Gui
{

class Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Screen(QWidget* parent = nullptr);

    virtual ~Screen() = default;

private:
};

} // namespace QWarhammerSimulator::Gui
