#ifndef GSUBSCRIBER_H
#define GSUBSCRIBER_H

class GSubscriber
{
public:
    /*!
     * \brief notify()
     * Receives notifications from other program modules.
     */
    virtual void notify() = 0;
    virtual ~GSubscriber();
};

#endif // GSUBSCRIBER_H
