#include "cameranode.h"
#include "transformnode.h"

/**************************************************************************************/

CameraNode::CameraNode(std::string name)
{
    this->name = name;
    this->type = "CameraNode";

    option = 0;


}

/**************************************************************************************/

void CameraNode::applySelf()
{

    /******** AUSGABE DES TYPS IN DER KONSOLE ********/
    std::string na = this->getName();
    std::cout << "Node---------->: " << na << std::endl;
    /*************************************************/

}

/**************************************************************************************/

void CameraNode::bing(){

    /******** AUSGABE DES TYPS IN DER KONSOLE ********/
    std::string na = this->getName();
    std::cout << "Node---------->: " << na << std::endl;
    /*************************************************/



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    // AUSWAHL zwischen LOOKAT oder INVERSE Berechnung der Kamera
    switch(option)
    {
        case 1: gluLookAt ( 0., 0., 4., 2., 0., 0., 0., 1., 0.);
                break;

        case 2: gluLookAt ( 0., 0., 4., -2., 0., 0., 0., 1., 0.);
                break;

        default:
                if(this->getParent()->getType()!="RootNode")
                {

                    ((TransformNode*) this->getParent())->inverse();


                }
     }

}

/**************************************************************************************/

void CameraNode::setLook(int op)
{
    option = op;
}

/**************************************************************************************/
