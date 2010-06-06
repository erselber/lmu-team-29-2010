#ifndef ROTATENODE_H
#define ROTATENODE_H

#include "transformnode.h"

class RotateNode : public TransformNode
{
public:
    RotateNode(float grad_t = 0, int xx = 0, int yy = 0, int zz = 0,std::string name_t = "RotateNode" )
    {
        this->name = name_t;
        this->type = "RotateNode";

        grad = grad_t;
        x = xx;
        y = yy;
        z = zz;
    };

    void applySelf();

    void inverse();
    void setRotation(float grad_t,int axis);


    GLfloat matrix[16];

protected:
    float grad;
    int x,y,z;

    void RotateInverse(float grad_t,int xx,int yy, int zz);

};

#endif // ROTATENODE_H
