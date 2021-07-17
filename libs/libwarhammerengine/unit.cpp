#include "unit.hpp"

#include <cmath>

#include <gsl/gsl_util>

namespace QWarhammerSimulator::LibWarhammerEngine
{

Unit::Unit(Model model, std::size_t number_of_models, std::size_t number_of_models_in_a_row, LibGeometry::Point center,
           const double orientation)
    : m_model(std::move(model))
    , m_number_of_models(number_of_models)
    , m_number_of_models_in_a_row(number_of_models_in_a_row)
    , m_rectangle(std::move(center), orientation, rectangleSize())
{
}

LibGeometry::Rectangle Unit::rectangle() const
{
    return m_rectangle;
}

std::size_t Unit::numberOfModels() const
{
    return m_number_of_models;
}

void Unit::removeModels(const std::size_t number_of_models_to_remove)
{
    Expects(number_of_models_to_remove <= m_number_of_models);
    const auto previous_rectangle_size = rectangleSize();
    m_number_of_models -= number_of_models_to_remove;
    const auto width_difference = previous_rectangle_size.y - rectangleSize().y;
    if(width_difference > 0)
    {
        m_rectangle = LibGeometry::Rectangle{m_rectangle.center(), m_rectangle.orientation(), rectangleSize()};
        m_rectangle.moveForward(width_difference / 2);
    }
}

LibGeometry::Point Unit::rectangleSize() const
{
    return {
        m_number_of_models_in_a_row * m_model.base_size.x,
        std::ceil((double)m_number_of_models / m_number_of_models_in_a_row) * m_model.base_size.y,
    };
}

} // namespace QWarhammerSimulator::LibWarhammerEngine
