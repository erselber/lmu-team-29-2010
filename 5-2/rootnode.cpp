#include "rootnode.h"



/******************************************************************************/
RootNode::RootNode(std::string name)
{
    name = name;
    type = "RootNode";
}

/******************************************************************************/

void RootNode::applySelf()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(90,1,1,100);


glMatrixMode(GL_MODELVIEW);
glLoadIdentity();


}
