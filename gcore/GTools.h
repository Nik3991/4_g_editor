#ifndef GTOOLS_H
#define GTOOLS_H

#include "GEntity.h"
#include "GPage.h"

/*!
 * \brief The GTools class
 */
class GTools
{
// -------------- Public functions --------------
public:

    /*!
     * Creates GPage binded to GModel.
     * Returns pointer to GPage.
     */
    static GPage* create_page(size_t _x, size_t _y);

    /*!
     * Sets current model that will be used to store graphic items.
     * Arguments:
     * - GPage* to store graphics
     */
    static void set_page(GPage* _page);

    /*!
     * Creates and stores GPage with serialized objects from file.
     * Arguments:
     * - string with path to file with serialized objects
     */
    static void load(string _file);

    /*!
     * Saves serialized objects from GPage to file.
     * set_model(GModel*) should be called before save_as(string)
     * Arguments:
     * - string with path to file that will be used to save serialized objects
     */
    static void save_as(string _file);

    /*!
     * Saves serialized objects from currect model to file.
     * set_model() should be called before save().
     * Calls save_as(string) if file path is not specified.
     */
    static void save();

    /*!
     * Delegetes call to GModel from current GPage.
     * Removes GEntity from model.
     * Arguments:
     * - Coordinates inside entity to remove: _x, _y
     */
    static void remove_entity(size_t _x, size_t _y);

    /*!
     * Use to add line to the GModel.
     * Arguments:
     * - First point coordinates: _xp1, _yp1
     * - Second point coordinates: _xp2, _yp2
     */
    static void add_line(size_t _xp1, size_t _yp1, size_t _xp2, size_t _yp2);

    /*!
     * Use to add oval to the GModel.
     * Aguments:
     * - Center coordinates: _xp1, _yp1
     * - Radius: _r
     */
    static void add_oval(size_t _x, size_t _y, size_t _r);

    /*!
     * Use to add triangle to the GModel.
     * Arguments:
     * - First point coordinates: _xp1, _yp1
     * - Second point coordinates: _xp2, _yp2
     * - Third point coordinates: _xp2, _yp2
     */
    static void add_triangle(size_t _xp1, size_t _yp1, size_t _xp2, size_t _yp2, size_t _xp3, size_t _yp3);

    /*!
     * Use to add rectangle to the GModel.
     * Aguments:
     * - Top left point coordinates: _xp, _yp
     * - Width: _width
     * - Hwight: _height
     */
    static void add_rect(size_t _x, size_t _y, size_t _width, size_t _height);

private:
    static GPage* m_CurrentPage;
};

#endif // GTOOLS_H
