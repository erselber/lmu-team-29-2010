#ifndef BOXNODE_H
#define BOXNODE_H

#include "geometrynode.h"

class BoxNode : public GeometryNode
{

public:
    BoxNode(std::string name = "BoxNode");

    void applySelf();
};

#endif // BOXNODE_H
