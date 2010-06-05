#include "rootnode.h"
#include "transformnode.h"



/******************************************************************************/
RootNode::RootNode(std::string name)
{
    this->name = name;
    this->type = "RootNode";

    //this->camera = NULL;
}


/******************************************************************************/

void RootNode::setCamera(CameraNode *camera)
{
   this->camera = camera;
}

/******************************************************************************/

void RootNode::applySelf()
{

    std::string na = this->getName();
    std::cout << "Node---------->: " << na << std::endl;

    camera->bing();

}
