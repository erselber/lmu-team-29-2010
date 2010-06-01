#include "boxnode.h"


/******************************************************************************/
BoxNode::BoxNode()
{
    name = "BoxNode";
    type = "BoxNode";
}

/******************************************************************************/


/******************************************************************************/
void BoxNode::applySelf()
{
    glBegin(GL_QUADS);

            //vorne
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(-1,-1,1);
            glVertex3f(1,-1,1);
            glVertex3f(1,1,1);
            glVertex3f(-1,1,1);

            //hinten
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,1,-1);
            glVertex3f(1,1,-1);
            glVertex3f(1,-1,-1);

            //rechts
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(1,-1,1);
            glVertex3f(1,-1,-1);
            glVertex3f(1,1,-1);
            glVertex3f(1,1,1);

            //links
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,-1,1);
            glVertex3f(-1,1,1);
            glVertex3f(-1,1,-1);

            //oben
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(-1,1,1);
            glVertex3f(1,1,1);
            glVertex3f(1,1,-1);
            glVertex3f(-1,1,-1);

            //unten
            glColor3f((1/red),(1/green),(1/blue));
            glVertex3f(1,-1,-1);
            glVertex3f(1,-1,1);
            glVertex3f(-1,-1,1);
            glVertex3f(-1,-1,-1);

         glEnd();
};
