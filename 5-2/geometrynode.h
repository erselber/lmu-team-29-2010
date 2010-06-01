#ifndef GEOMETRYNODE_H
#define GEOMETRYNODE_H

#include "node.h"

class GeometryNode : public Node
{
public:
    GeometryNode();

    void setColor(int red,int green, int blue);

protected:
    int red;
    int green;
    int blue;
};



#endif // GEOMETRYNODE_H
