#ifndef GMODEL_H
#define GMODEL_H

#include <vector>
#include <memory>

using namespace std;

#include "GNotifier.h"
#include "GEntity.h"
#include "GSubscriber.h"

/*!
 * GModel used to store GEntity graphic ojects.
 */
class GModel : GNotifier
{
// -------------- Public functions --------------
public:
    /*!
     * \brief add_entity(GEntity*)
     * Use to add GEntity to the GModel.
     * Calls: updated()
     * Aguments:
     * GEntity pointer: _entity
     */
    void add_entity(GEntity* _entity);

    /*!
     * \brief remove_entity(size_t _x, size_t _y)
     * Use to remove GEntity from the GModel.
     * Agument:
     * Entity cooordinates: _x, _y
     */
    void remove_entity(size_t _x, size_t _y);

    /*!
     * \brief override
     */
    virtual void subscribe(GSubscriber*) override;

    /*!
     * \brief Returns constant entities vector.
     */
    const vector<GEntity*>* entities();

// -------------- Private functions --------------
private:
    /*!
     * \brief updated()
     * Notifies subscribers
     */
    void updated();

// -------------- Private members --------------
private:
    vector<weak_ptr<GSubscriber*>> m_Subscribers;
    vector<GEntity*> m_Entities;
};

#endif // GMODEL_H
