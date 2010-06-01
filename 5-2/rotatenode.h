#ifndef ROTATENODE_H
#define ROTATENODE_H

#include "transformnode.h"

class RotateNode : public TransformNode
{
public:
    RotateNode(float grad_t, int xx, int yy, int zz ){

        name = "RotateNode";
        type = "RotateNode";

        grad = grad_t;
        x = xx;
        y = yy;
        z = zz;
    };

    void applySelf();

private:
    float grad;
    int x,y,z;
};

#endif // ROTATENODE_H
