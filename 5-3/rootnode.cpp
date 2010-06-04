#include "rootnode.h"



/******************************************************************************/
RootNode::RootNode(std::string name, CameraNode *camera)
{
    name = name;
    type = "RootNode";

    camera = camera;
}


/******************************************************************************/

void RootNode::setCamera(CameraNode *camera)
{
    camera = camera;
}

/******************************************************************************/

void RootNode::applySelf()
{

    camera->bing();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
