#ifndef CAMERANODE_H
#define CAMERANODE_H

#include "node.h"

class CameraNode : public Node
{
public:
    CameraNode(std::string name = "CameraNode");


    void applySelf();
    void bing();

};

#endif // CAMERANODE_H
