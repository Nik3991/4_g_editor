#ifndef GPAGE_H
#define GPAGE_H

#include "GSubscriber.h"
#include "GModel.h"
#include "GEntity.h"

/*!
 * \brief The GPage class show graphics data
 */
class GPage : GSubscriber
{
public:
    GPage(size_t _width, size_t _height, GModel* _model_ptr):
        m_model_ptr(_model_ptr),
        m_width(_width),
        m_height(_height)
    {
        // ...
        redraw();
    }

    /*!
     * Used to catch notification when GModel changed.
     * Calls redraw()
     */
    virtual void notify() override;

    /*!
     * Used when current model was modified.
     */
    void redraw();

    /*!
     * Returns reference to point on canvas.
     */
    GColor& operator()(int _x, int _y);

    /*!
     * Shows/hides GPage.
     * Argument:
     * bool _show is used to show or hide GPage.
     */
    void show(bool _show);

    /*!
     * Returns pointer to GModel.
     */
    GModel* model();

private:
    const size_t m_width;
    const size_t m_height;
    GColor* m_Canvas = nullptr;
    GModel* m_model_ptr = nullptr;
};

#endif // GPAGE_H
