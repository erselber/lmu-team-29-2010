#ifndef TRANSLATENODE_H
#define TRANSLATENODE_H


#include "transformnode.h"

class TranslateNode : public TransformNode
{

public:
    TranslateNode(float xx = 0, float yy = 0, float zz = 0){
        name = "TranslateNode";
        type = "TranslateNode";
        x = xx;
        y = yy;
        z = zz;
    };


    void applySelf();

    void inverse();

protected:

    float x,y,z;
};

#endif // TRANSLATENODE_H
