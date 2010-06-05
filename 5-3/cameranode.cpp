#include "cameranode.h"
#include "transformnode.h"

/**************************************************************************************/
CameraNode::CameraNode(std::string name)
{
    this->name = name;
    this->type = "CameraNode";


}


/**************************************************************************************/

void CameraNode::applySelf()
{
    std::string na = this->getName();
    std::cout << "Node---------->: " << na << std::endl;

   //gluLookAt ( 0., 0., 4., 0., 0., 0., 0., 1., 0.);




}

/**************************************************************************************/
void CameraNode::bing(){

    std::string na = this->getName();
    std::cout << "Node---------->: " << na << std::endl;



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,1,1000);



    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    if(this->getParent()->getType()!="RootNode")
    {

        ((TransformNode*) this->getParent())->inverse();


    }



    Node* sss =this->getParent();

    while(sss->getType()!= "RootNode")
    {
        sss = sss->getParent();
    }

    (sss->getChildren()[0])->apply();


    gluLookAt ( 0., 0., 4., 0., 0., 0., 0., 1., 0.);

}
