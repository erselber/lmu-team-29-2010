#include "translatenode.h"


void TranslateNode::applySelf(){

    glTranslated(x,y,z);

}


void TranslateNode::inverse()
{

    glTranslated(-x,-y,-z);
}
