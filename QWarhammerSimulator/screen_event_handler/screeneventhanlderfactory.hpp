#pragma once

#include "monadicpointer.hpp"

#include "turnphasemanager.hpp"

#include <map>
#include <memory>

namespace QWarhammerSimulator::Gui::ScreenEventHandler
{

class IScreenEventHandler;

class ScreenEventHandlerFactory
{
public:
    ~ScreenEventHandlerFactory();

    /**
     * @brief returns the screen event handler if there is one for the given phase
     *
     * Returns a null pointer if there is no handler for the given phase
     */
    static LibUtils::MonadicPointer<IScreenEventHandler> get(const LibWarhammerEngine::TurnPhase phase);

    static bool registerHandler(const LibWarhammerEngine::TurnPhase phase,
                                std::unique_ptr<IScreenEventHandler> handler);

private:
    explicit ScreenEventHandlerFactory() = default;

    static ScreenEventHandlerFactory& instance();

    std::map<LibWarhammerEngine::TurnPhase, std::unique_ptr<IScreenEventHandler>> m_handlers;
};

} // namespace QWarhammerSimulator::Gui::ScreenEventHandler
