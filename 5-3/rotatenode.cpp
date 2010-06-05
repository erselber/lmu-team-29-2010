#include "rotatenode.h"
#include <cmath>
#define PI 3.14159265


/******************************************************************************/
/******************************************************************************/

void RotateNode::applySelf()
{
    std::string na = this->getName();
    std::cout << "Node---------->: " << na << std::endl;

    glRotated(grad,x,y,z);

}


/******************************************************************************/

void RotateNode::inverse(){


    std::cout << "RotateNode inverse : " << std::endl;


    RotateInverse(this->grad,this->x,this->y,this->z);

    if(this->getParent()->getType()!="RootNode")
    {
        ((TransformNode*) this->getParent())->inverse();
    }

}

/******************************************************************************/
void RotateNode::RotateInverse(float grad_t, int xx,int yy, int zz){

    GLdouble *matrix = new GLdouble[16];

    if(xx==1)
    {
        matrix[0] = 1;
        matrix[1] = 0;
        matrix[2] = 0;
        matrix[3] = 0;

        matrix[4] = 0;
        matrix[5] = cos(grad_t*PI/180);
        matrix[6] = -sin(grad_t*PI/180);
        matrix[7] = 0;

        matrix[8] = 0;
        matrix[9] = sin(grad_t*PI/180);
        matrix[10] = cos(grad_t*PI/180);
        matrix[11] = 0;

        matrix[12] = 0;
        matrix[13] = 0;
        matrix[14] = 0;
        matrix[15] = 1;

        glMultMatrixd(matrix);
    }

    if(yy==1)
    {
            matrix[0] = cos(grad_t*PI/180);
            matrix[1] = 0;
            matrix[2] = sin(grad_t*PI/180);
            matrix[3] = 0;

            matrix[4] = 0;
            matrix[5] = 1;
            matrix[6] = 0;
            matrix[7] = 0;

            matrix[8] = -sin(grad_t*PI/180);
            matrix[9] = 0;
            matrix[10] = cos(grad_t*PI/180);
            matrix[11] = 0;

            matrix[12] = 0;
            matrix[13] = 0;
            matrix[14] = 0;
            matrix[15] = 1;

            glMultMatrixd(matrix);
      }


     if(zz==1)
     {
           matrix[0] = cos(grad_t*PI/180);
           matrix[1] = -sin(grad_t*PI/180);
           matrix[2] = 0;
           matrix[3] = 0;

           matrix[4] = sin(grad_t*PI/180);
           matrix[5] = cos(grad_t*PI/180);
           matrix[6] = 0;
           matrix[7] = 0;

           matrix[8] = 0;
           matrix[9] = 0;
           matrix[10] = 1;
           matrix[11] = 0;

           matrix[12] = 0;
           matrix[13] = 0;
           matrix[14] = 0;
           matrix[15] = 1;

           glMultMatrixd(matrix);
    }


    std::cout << "ICH BIN IN DER MULTIPLIKATION x = " << xx << "y = " << yy << "z = " << zz << " grad =" << grad_t << std::endl;
}

/******************************************************************************/

void RotateNode::setRotation(float grad_t,int axis)
{
    switch(axis)
    {
        case 0: x=1;y=0;z=0;
                break;
        case 1: x=0;y=1;z=0;
                break;
        case 2: x=0;y=0;z=1;

    }

    grad = grad_t;

}
