#pragma once

#include <QWidget>

namespace QWarhammerSimulator
{

namespace LibWarhammerEngine
{
    class Game;
}

namespace Gui::PhaseSpecificCommandPanel
{

    class ShootingCommandPanel : public QWidget
    {
    public:
        explicit ShootingCommandPanel(QWidget* parent = nullptr);

        virtual ~ShootingCommandPanel() = default;

    private:
        void updateValues();
    };

} // namespace Gui::PhaseSpecificCommandPanel

} // namespace QWarhammerSimulator
