#ifndef ROOTNODE_H
#define ROOTNODE_H


#include "node.h"
#include "cameranode.h"

class RootNode : public Node
{
public:
    RootNode(std::string name = "RootNode");


    void applySelf();

    void setCamera(CameraNode *camera);

private:
    CameraNode *camera;
};

#endif // ROOTNODE_H
