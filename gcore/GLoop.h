#ifndef GLOOP_H
#define GLOOP_H

#include <queue>
using namespace std;

struct GEvent {
    size_t m_EventCode;
};

typedef void (*func_ptr)(GEvent);

class GLoop
{
public:
    GLoop(func_ptr _handler) : m_Handler(_handler) {}

    int execute()
    {
        bool exit = false;
        while (!exit)
        {
            // 1. listens to user input.
            // 2. convers user input to events.
            // 3. put events to m_Events queue.

            while (!m_Events.empty())
            {
                GEvent event = m_Events.front();
                m_Events.pop();

                switch (event.m_EventCode)
                {
                   // calls to m_Handler

                   // ...

                   case 0: exit = true; break;
                   default: break;
                }
            }
        }
        return 0;
    }

private:
    func_ptr m_Handler;
    queue<GEvent> m_Events;
};

#endif // GLOOP_H
