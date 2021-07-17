#include "screeneventhanlderfactory.hpp"

#include "iscreeneventhanlder.hpp"

namespace QWarhammerSimulator::Gui::ScreenEventHandler
{

ScreenEventHandlerFactory::~ScreenEventHandlerFactory() = default;

IScreenEventHandler* ScreenEventHandlerFactory::get(const LibWarhammerEngine::TurnPhase phase)
{
    const auto it = instance().m_handlers.find(phase);
    if(it == end(instance().m_handlers)) return nullptr;
    return it->second.get();
}

bool ScreenEventHandlerFactory::registerHandler(const LibWarhammerEngine::TurnPhase phase,
                                                std::unique_ptr<IScreenEventHandler> handler)
{
    auto it = instance().m_handlers.find(phase);
    if(it != end(instance().m_handlers)) return false;
    instance().m_handlers[phase] = std::move(handler);
    return true;
}

ScreenEventHandlerFactory& ScreenEventHandlerFactory::instance()
{
    static ScreenEventHandlerFactory s_instance;
    return s_instance;
}

} // namespace QWarhammerSimulator::Gui::ScreenEventHandler
