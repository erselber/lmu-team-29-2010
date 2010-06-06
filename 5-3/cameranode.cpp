#include "cameranode.h"
#include "transformnode.h"
#include "boxnode.h"
#include "rotatenode.h"

/**************************************************************************************/

CameraNode::CameraNode(std::string name)
{
    this->name = name;
    this->type = "CameraNode";


    option = 0;
    unsave = true;
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
    std::cout << "Node bing---------->: " << na << std::endl;
    /*************************************************/

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,1,100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /*** Einlesen der Position in die eigene MATRIX ***/
    if(unsave)
    {
        Node* node = this->getParent();
        Node* child = this;

        while(node->getType()!="RootNode")
        {
            child = node;
            node = node->getParent();
        }

        glPushMatrix();

        child->apply();
        glGetFloatv(GL_MODELVIEW_MATRIX,this->matrix);
        std::cout << "<------ SCHLEIFE ---------->: " << std::endl;

        glPopMatrix();

        unsave=false;


    }

    // AUSWAHL zwischen LOOKAT oder INVERSE Berechnung der Kamera
    switch(option)
    {

        case 0:
                if(this->getParent()->getType()!="RootNode")
                {
                    ((TransformNode*) this->getParent())->inverse();
                }
                break;

        case 1:

            gluLookAt ( matrix[12], matrix[13], matrix[14],((BoxNode*) node)->matrix[12],((BoxNode*) node)->matrix[13],((BoxNode*) node)->matrix[14], 0., 1., 0.);

            std::cout << "Ausgabe Matrix1 :" <<  matrix[12] <<" , " << matrix[13] << " , " << matrix[14] << std::endl;
            std::cout << "Ausgabe Matrix2 :" <<  ((BoxNode*) node)->matrix[12] <<" , " << ((BoxNode*) node)->matrix[13] << " , " << ((BoxNode*) node)->matrix[14] << std::endl;

     }

}

/**************************************************************************************/
/**************************************************************************************/

void CameraNode::setLook(Node* box)
{
    option = 1;
    node = box;
}

/**************************************************************************************/


void CameraNode::unLook()
{
    option = 0;
}

/**************************************************************************************/
