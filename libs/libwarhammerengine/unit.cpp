#include "unit.hpp"

namespace QWarhammerSimulator::LibWarhammerEngine
{

Unit::Unit(Model model, std::size_t number_of_models, std::size_t number_of_models_in_a_row)
    : m_model(std::move(model))
    , m_number_of_models(number_of_models)
    , m_number_of_models_in_a_row(number_of_models_in_a_row)
    , m_rectangle(LibGeometry::Point{0, 0}, 0., rectangleSize())
{
}

LibGeometry::Rectangle Unit::rectangle() const
{
    return m_rectangle;
}

LibGeometry::Point Unit::rectangleSize() const
{
    return {
        m_number_of_models_in_a_row * m_model.base_size.x,
        m_number_of_models / m_number_of_models_in_a_row * m_model.base_size.y,
    };
}

} // namespace QWarhammerSimulator::LibWarhammerEngine
