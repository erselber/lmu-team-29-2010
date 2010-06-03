#include "cameranode.h"


/**************************************************************************************/
CameraNode::CameraNode(std::string name)
{
    name = name;
    type = "CameraNode";

}

/**************************************************************************************/

void CameraNode::applySelf()
{


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,1,1000);



   //gluLookAt ( 0., 0., 4., 0., 0., 0., 0., 1., 0.);




}

/**************************************************************************************/

