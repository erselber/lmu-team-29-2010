#ifndef ROTATENODE_H
#define ROTATENODE_H

#include "transformnode.h"

class RotateNode : public TransformNode
{
public:
    RotateNode(float grad_t = 0, int xx = 0, int yy = 0, int zz = 0 ){

        name = "RotateNode";
        type = "RotateNode";

        grad = grad_t;
        x = xx;
        y = yy;
        z = zz;
    };

    void applySelf();

    void inverse();

    void setRotation(float grad,int axis);

private:
    float grad;
    int x,y,z;
};

#endif // ROTATENODE_H
