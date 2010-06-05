#ifndef CAMERANODE_H
#define CAMERANODE_H

#include "node.h"
#include "string"

class CameraNode : public Node
{
public:
    CameraNode(std::string name = "CameraNode");


    void applySelf();
    void bing();

};

#endif // CAMERANODE_H
