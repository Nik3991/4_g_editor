#ifndef GNOTIFIER_H
#define GNOTIFIER_H

#include "GSubscriber.h"

class GNotifier
{
public:
    /*!
     * \brief subscribe(GSubscriber*)
     * Saves GSubscriber* to notify.
     */
    virtual void subscribe(GSubscriber*) = 0;
    virtual ~GNotifier();
};
#endif // GNOTIFIER_H
