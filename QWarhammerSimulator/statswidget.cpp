#include "statswidget.hpp"

#include "functional.hpp"

#include <QGridLayout>
#include <QLabel>

namespace QWarhammerSimulator::Gui
{

namespace
{
    /**
     * @pre index < LibWarhammerEngine::Characteristics::number_of_stats()
     */
    QString statLabel(const std::size_t index)
    {
        Expects(index < LibWarhammerEngine::Characteristics::number_of_stats());
        static const QStringList values{QObject::tr("M", "Movement Allowance"), QObject::tr("Ws", "Weapon Skill"),
                                        QObject::tr("Bs", "Ballistic Skill"),   QObject::tr("S", "Strength"),
                                        QObject::tr("T", "Toughness"),          QObject::tr("W", "Wounds"),
                                        QObject::tr("I", "Initiative"),         QObject::tr("A", "Attacks"),
                                        QObject::tr("Ld", "Leadership")};
        return values[index];
    }

} // namespace

StatsWidget::StatsWidget(QWidget* parent)
    : QWidget(parent)
{
    auto* lay = new QGridLayout();
    constexpr auto nb_stats = LibWarhammerEngine::Characteristics::number_of_stats();
    lay->addWidget(m_name_label, 0, 0, 0, nb_stats);
    for(int i = 0; i < nb_stats; i++)
    {
        m_stat_label.push_back(new QLabel{});
        lay->addWidget(new QLabel{statLabel(i)}, 1, i);
        lay->addWidget(m_stat_label.back(), 2, i);
    }
    setLayout(lay);
}

void StatsWidget::setModel(const OptionalModel& model)
{
    m_model = model;
    updateValues();
}

void StatsWidget::updateValues()
{
}

} // namespace QWarhammerSimulator::Gui
