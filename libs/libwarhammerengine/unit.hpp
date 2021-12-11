#pragma once

#include "model.hpp"

#include "rectangle.hpp"

namespace QWarhammerSimulator::LibWarhammerEngine
{

class Unit
{
public:
    Unit(Model model, std::size_t number_of_models, std::size_t number_of_models_in_a_row, LibGeometry::Point center,
         const double orientation = 0.);

    LibGeometry::Rectangle rectangle() const;

    std::size_t numberOfModels() const;

    /**
     * @pre number_of_models_to_remove <= m_number_of_models
     */
    void removeModels(const std::size_t number_of_models_to_remove);

    /**
     * @pre model_index <= m_number_of_models
     */
    LibGeometry::Rectangle modelRectangle(const std::size_t model_index) const;

private:
    Model m_model;
    std::size_t m_number_of_models;
    std::size_t m_number_of_models_in_a_row;
    LibGeometry::Rectangle m_rectangle;

    LibGeometry::Point rectangleSize() const;
};

} // namespace QWarhammerSimulator::LibWarhammerEngine
