#ifndef BOXNODE_H
#define BOXNODE_H

#include "geometrynode.h"

class BoxNode : public GeometryNode
{

public:
    BoxNode();

    void applySelf();
};

#endif // BOXNODE_H
