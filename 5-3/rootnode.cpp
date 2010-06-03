#include "rootnode.h"



/******************************************************************************/
RootNode::RootNode(std::string name, CameraNode *camera)
{
    name = name;
    type = "RootNode";

    camera = camera;
}

/******************************************************************************/

void RootNode::applySelf()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
