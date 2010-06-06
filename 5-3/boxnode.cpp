#include "boxnode.h"


/******************************************************************************/
BoxNode::BoxNode(std::string name)
{
    this->name = name;
    this->type = "BoxNode";

    unsave = true;

}

/******************************************************************************/
/******************************************************************************/

void BoxNode::applySelf()
{

    /******** AUSGABE DES TYPS IN DER KONSOLE ********/
    std::string na = this->getName();
    std::cout << "Node---------->: " << na << std::endl;
    /*************************************************/

    if(unsave)
    {
        glGetFloatv(GL_MODELVIEW_MATRIX,matrix);
        unsave = false;
    }
    glBegin(GL_QUADS);

            //vorne
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(-0.5,0.5,0.5);

            //hinten
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,-0.5,-0.5);

            //rechts
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,0.5);

            //links
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,0.5,-0.5);

            //oben
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,-0.5);

            //unten
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(0.5,-0.5,-0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,-0.5,-0.5);

         glEnd();

};

/******************************************************************************/
