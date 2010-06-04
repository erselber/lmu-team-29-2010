#include "boxnode.h"


/******************************************************************************/
BoxNode::BoxNode(std::string name )
{
    name = name;
    type = "BoxNode";
}

/******************************************************************************/


/******************************************************************************/
void BoxNode::applySelf()
{
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
