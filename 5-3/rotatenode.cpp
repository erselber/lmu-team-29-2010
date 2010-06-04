#include "rotatenode.h"
#include <cmath>
#define PI 3.14159265

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

void RotateNode::inverse(){

    if(x==1)
    {
        GLdouble *matrix = new GLdouble[16];

        matrix[0] = 1;
        matrix[1] = 0;
        matrix[2] = 0;
        matrix[3] = 0;

        matrix[4] = 0;
        matrix[5] = cos(grad*PI/180);
        matrix[6] = sin(grad*PI/180);
        matrix[7] = 0;

        matrix[8] = 0;
        matrix[9] = -sin(grad*PI/180);
        matrix[10] = cos(grad*PI/180);
        matrix[11] = 0;

        matrix[12] = 0;
        matrix[13] = 0;
        matrix[14] = 0;
        matrix[15] = 1;

        glMultMatrixd(matrix);
    }
}

/******************************************************************************/
