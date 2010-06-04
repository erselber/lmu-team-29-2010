#ifndef SCALENODE_H
#define SCALENODE_H

#include "transformnode.h"

class ScaleNode : public TransformNode
{
public:
    ScaleNode(float xx = 1,float yy = 1, float zz = 1){

        name = "ScaleNode";
        type = "ScaleNode";

        x = xx;
        y = yy;
        z = zz;
    };

    void applySelf();

    void inverse();

private:
    float x,y,z;
};

#endif // SCALENODE_H
