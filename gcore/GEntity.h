#ifndef GENTITY_H
#define GENTITY_H

#include <vector>
#include <string>

using namespace std;

class GPage;

/*!
 * Stores x and y coordinates.
 */
struct GVertex
{
    size_t m_x, m_y;
};

/*!
 * Stores RBG color.
 */
struct GColor
{
    char R, G, B;
};

/*!
 * Objects of GEntity used to store graphic information in the GModel.
 */
class GEntity
{
// -------------- Public functions --------------
public:
    /*!
     * Constructs GEntity object with unique id.
     * Argument:
     * - '_pos' used to set x and y coordinates of GEntity.
     */
    GEntity(GVertex _pos);

    /*!
     * Constructs GEntity obgect from '_serialized' argument.
     */
    GEntity(string _serialized);

    /*!
     * \brief virtual destructor.
     */
    virtual ~GEntity(){};

    /*!
     * Returns unique id for graphic entity.
     */
    size_t id();

    /*!
     * Returns object with string type that can be used to restore graphic entity.
     */
    string serialize();

    /*!
     * Use to add vertex '_p' to the structure of graphic entity.
     */
    void add_vertex(GVertex _p);

    /*!
     * Returns true if _x and _y coordinates are inside GEntity.
     * Arguments:
     * - Coordinates of point: _x, _y.
     */
    bool contains_point(size_t _x, size_t _y);

    /*!
     * Use to draw GEntity.
     * Uses GPage* to draw on it.
     */
    virtual void draw(GPage* _page) = 0;

// -------------- Private members --------------
private:
    static size_t s_Id;
    size_t m_Id;
    GVertex m_Pos;
    GColor m_Color;
    vector<GVertex> m_EntityPoints;
};

#endif // GENTITY_H
