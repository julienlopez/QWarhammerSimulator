#pragma once

#include <QWidget>

namespace QWarhammerSimulator::Gui
{

class CommandPanel : public QWidget
{
    Q_OBJECT

public:
    explicit CommandPanel(QWidget* parent = nullptr);

    virtual ~CommandPanel() = default;

private:
};

} // namespace QWarhammerSimulator::Gui
