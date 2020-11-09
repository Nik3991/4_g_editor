#include "GTools.h"
#include "GLoop.h"

void handler(GEvent _event)
{
    switch (_event.m_EventCode)
    {
        case 1:
        {
            string path = "C:/";

            // show dialog to set file path.
            // ...

            // GTools::load(path);

        } break;

        case 2:
        {
            string path = "C:/";

            // show dialog to set file path.
            // ...

            // GTools::save_as(path);

        } break;

        case 3:
        {
            size_t x1, y1, x2, y2;

            // show dialog to set coordinates.
            // ...

            GTools::add_line(x1, y1, x2, y2);

        } break;

        // ...

        default: break;
    }
}

int main()
{
    GLoop loop(handler);
/*  return loop.execute();  */
}
