#include <thread>

#include "ui/event_processor/quit_event_listener.h"

QuitEventListener::QuitEventListener(): quit{false}, quitStateCheckingTimeoutMs{100}
{}

void QuitEventListener::onEvent(const std::shared_ptr<IEvent>)
{
    quit = true;
}

void QuitEventListener::waitQuit() const
{
    while(!quit)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(quitStateCheckingTimeoutMs));
    }
}