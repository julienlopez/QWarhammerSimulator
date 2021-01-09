#pragma once

#include <QMainWindow>

namespace QWarhammerSimulator::Gui
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    virtual ~MainWindow() = default;
};

} // namespace QWarhammerSimulator::Gui
