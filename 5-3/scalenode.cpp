#include "scalenode.h"


void ScaleNode::applySelf(){

    std::string na = this->getName();
    std::cout << "Node---------->: " << na << std::endl;

    glScaled(x,y,z);

}

void ScaleNode::inverse(){

    std::cout << "ScaleNode inverse : " << std::endl;
    glScaled(1/x,1/y,1/z);

    if(this->getParent()->getType()!="RootNode")
    {
        ((TransformNode*) this->getParent())->inverse();
    }


}

