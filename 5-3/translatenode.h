#ifndef TRANSLATENODE_H
#define TRANSLATENODE_H


#include "transformnode.h"

class TranslateNode : public TransformNode
{

public:
    TranslateNode(float xx = 0, float yy = 0, float zz = 0, std::string name_t = "TranslateNode"){

        this->name = name_t;
        this->type = "TranslateNode";
        x = xx;
        y = yy;
        z = zz;
    };


    void applySelf();

    void inverse();
    void setTranslation(int xx,int yy, int zz);


protected:

    float x,y,z;
};

#endif // TRANSLATENODE_H
