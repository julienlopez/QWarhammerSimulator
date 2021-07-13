#include "screeneventhanlderfactory.hpp"

#include "iscreeneventhanlder.hpp"

namespace QWarhammerSimulator::Gui
{

ScreenEventHandlerFactory::~ScreenEventHandlerFactory() = default;

IScreenEventHandler* ScreenEventHandlerFactory::get(const LibWarhammerEngine::TurnPhase phase) const
{
    const auto it = instance().m_handlers.find(phase);
    if(it == end(instance().m_handlers)) return nullptr;
    return it->second.get();
}

ScreenEventHandlerFactory& ScreenEventHandlerFactory::instance()
{
    static ScreenEventHandlerFactory s_instance;
    return s_instance;
}

}
