#include "translatenode.h"

/******************************************************************************/

void TranslateNode::applySelf(){

    std::string na = this->getName();
    std::cout << "Node---------->: " << na << std::endl;

    glTranslated(x,y,z);

}

/******************************************************************************/

void TranslateNode::inverse()
{

    std::cout << "TranslateNode inverse : " << std::endl;
    glTranslated(-x,-y,-z);


    if(this->getParent()->getType()!="RootNode")
    {
        ((TransformNode*) this->getParent())->inverse();
    }


}

/******************************************************************************/
void TranslateNode::setTranslation(int xx,int yy, int zz)
{
    x = xx;
    y = yy;
    z = zz;
}
