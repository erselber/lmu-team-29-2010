#ifndef TRANSFORMNODE_H
#define TRANSFORMNODE_H


#include "node.h"

class TransformNode : public Node
{
public:
    TransformNode();

    virtual void inverse();
};

#endif // TRANSFORMNODE_H
