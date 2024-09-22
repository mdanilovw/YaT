#ifndef __QUIT_EVENT_LISTENER_H__
#define __QUIT_EVENT_LISTENER_H__

#include <atomic>

#include "ui/event_processor/ievent_listener.h"

class QuitEventListener: public IEventListener
{
    public:
    QuitEventListener();

    void onEvent(const std::shared_ptr<IEvent>) override;
    void waitQuit() const;

    private:
    std::atomic<bool> quit;
    const int quitStateCheckingTimeoutMs;
};

#endif