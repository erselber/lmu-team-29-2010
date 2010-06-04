#include "cameranode.h"
#include "transformnode.h"

#include <iostream>

/**************************************************************************************/
CameraNode::CameraNode(std::string name)
{
    name = name;
    type = "CameraNode";

}

/**************************************************************************************/

void CameraNode::applySelf()
{

    /*
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,1,1000);
*/


   //gluLookAt ( 0., 0., 4., 0., 0., 0., 0., 1., 0.);




}

/**************************************************************************************/

void CameraNode::bing()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,1,1000);

    //glTranslated(0,0,-4);

    //parent->inverse();

    std::cout << "Ausgabe Parent : " << parent->getName() << std::endl;
    /*
    Node *pointer;
    pointer = parent->getParent();
    pointer->inverse();

    */


}
