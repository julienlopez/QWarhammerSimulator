#pragma once

#include "model.hpp"

#include <boost/optional.hpp>

#include <QWidget>

class QLabel;

namespace QWarhammerSimulator::Gui
{

class StatsWidget : public QWidget
{
    Q_OBJECT

public:
    using OptionalModel = boost::optional<LibWarhammerEngine::Model>;

    explicit StatsWidget(QWidget* parent = nullptr);

    virtual ~StatsWidget() = default;

    void setModel(const OptionalModel& model);

private:
    OptionalModel m_model = boost::none;
    QLabel* m_name_label = nullptr;
    std::vector<QLabel*> m_stat_label;

    void updateValues();
};

} // namespace QWarhammerSimulator::Gui