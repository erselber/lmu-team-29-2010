#include "rotatenode.h"


/******************************************************************************/

void RotateNode::applySelf()
{
    glRotated(grad,x,y,z);

}

/******************************************************************************/

void RotateNode::setRotation(float grad,int axis)
{

    switch(axis)
    {

    case 0: glRotated(grad,1,0,0);
              break;

    case 1: glRotated(grad,0,1,0);
              break;

    case 2: glRotated(grad,0,0,1);

          }


}

/******************************************************************************/
/******************************************************************************/
