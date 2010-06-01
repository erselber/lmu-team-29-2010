#ifndef TRANSLATENODE_H
#define TRANSLATENODE_H


#include "transformnode.h"

class TranslateNode : public TransformNode
{

public:
    TranslateNode(float xx, float yy, float zz){
        name = "TranslateNode";
        type = "TranslateNode";
        x = xx;
        y = yy;
        z = zz;
    };


    void applySelf();

protected:
    float x,y,z;
};

#endif // TRANSLATENODE_H
