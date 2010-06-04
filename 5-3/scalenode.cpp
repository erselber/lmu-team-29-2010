#include "scalenode.h"


void ScaleNode::applySelf(){

    glScaled(x,y,z);

}

void ScaleNode::inverse(){

    glScaled(1/x,1/y,1/z);
}

