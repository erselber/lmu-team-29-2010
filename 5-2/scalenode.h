#ifndef SCALENODE_H
#define SCALENODE_H

#include "transformnode.h"

class ScaleNode : public TransformNode
{
public:
    ScaleNode(float xx,float yy, float zz){

        name = "ScaleNode";
        type = "ScaleNode";

        x = xx;
        y = yy;
        z = zz;
    };

    void applySelf();
private:
    float x,y,z;
};

#endif // SCALENODE_H
