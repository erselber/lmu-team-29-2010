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
    void setLook(Node *node);
    void unLook();

    GLfloat matrix[16];

private:
    int option;
    Node* node;

    bool unsave;

};

#endif // CAMERANODE_H
