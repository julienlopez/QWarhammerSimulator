#pragma once

#include "model.hpp"

#include "rectangle.hpp"

namespace QWarhammerSimulator::LibWarhammerEngine
{

class Unit
{
public:
    Unit(Model model, std::size_t number_of_models, std::size_t number_of_models_in_a_row);

    LibGeometry::Rectangle rectangle() const;

    std::size_t numberOfModels() const;

    /**
    * @pre number_of_models_to_remove <= m_number_of_models
    */
    void removeModels(const std::size_t number_of_models_to_remove);

private:
    Model m_model;
    std::size_t m_number_of_models;
    std::size_t m_number_of_models_in_a_row;
    LibGeometry::Rectangle m_rectangle;

    LibGeometry::Point rectangleSize() const;
};

} // namespace QWarhammerSimulator::LibWarhammerEngine
