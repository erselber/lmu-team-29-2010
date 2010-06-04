#ifndef ROOTNODE_H
#define ROOTNODE_H


#include "node.h"


class RootNode : public Node
{
public:
    RootNode(std::string name = "RootNode");


    void applySelf();
};

#endif // ROOTNODE_H
