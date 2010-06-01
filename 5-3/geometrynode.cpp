#include "geometrynode.h"


/**************************************************************************************/

GeometryNode::GeometryNode()
{
    red = 1;
    green = 255;
    blue = 255;
}

/**************************************************************************************/

void GeometryNode::setColor(int red, int green, int blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;

    if(red==0)
    {this->red = 255;}
    if(green==0)
    {this->green= 255;}
    if(blue==0)
    {this->blue=255;}


}
