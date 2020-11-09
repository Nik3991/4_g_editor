#ifndef GLINE_H
#define GLINE_H

#include "../gcore/GEntity.h"

class GLine : public GEntity
{
public:
    GLine(GVertex _pos) : GEntity(_pos) {}
    virtual void draw(GPage* _page) override;
};

#endif // GLINE_H
