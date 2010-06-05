#define PI 3.14159

#include "myglwidget.h"
#include "scene.h"
#include "rootnode.h"
#include "boxnode.h"
#include "translatenode.h"
#include "rotatenode.h"
#include "scalenode.h"


/*************************/
  /** VARIABLEN NODES **/
/*************************/
Scene *scene;
RootNode *root;
ScaleNode *scale_r;
TranslateNode *trans_m, *trans_r, *trans_l, *trans_center;
RotateNode *rotate_l, *rotate_m, *rotate_center;
BoxNode *box_l, *box_r, *box_m;


/*************/

/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


    initializeSCENE();
}

/**************************************************************************************/

void MyGLWidget::resizeGL(int w, int h){

    glViewport(0,0, w,h);



}

/**************************************************************************************/

void MyGLWidget::paintGL(){

    //

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1);


    scene->render();

}

/*************************************************************************************/

void MyGLWidget::initializeSCENE()
{

    root = new RootNode();
    trans_center = new TranslateNode(0,0,-10);
    rotate_center = new RotateNode(-20,1,0,0);

    //Links Baum
    trans_l = new TranslateNode(-5,0,0);
    rotate_l = new RotateNode(45,0,1,0);
    box_l = new BoxNode();
    box_l->setColor(1,0,0);

    //Mitte Baum
    trans_m = new TranslateNode(0,0,0);
    rotate_m = new RotateNode(45,0,0,1);
    box_m = new BoxNode();
    box_m->setColor(0,1,0);

    //Rechts Baum
    trans_r = new TranslateNode(5,0,0);
    scale_r = new ScaleNode(2,2,2);
    box_r = new BoxNode();
    box_r->setColor(0,0,1);


    //Kinder einfuegen

    root->addChild(trans_center);
    trans_center->addChild(rotate_center);

    rotate_center->addChild(trans_l);
    rotate_center->addChild(trans_m);
    rotate_center->addChild(trans_r);

    trans_l->addChild(rotate_l);
    trans_m->addChild(rotate_m);
    trans_r->addChild(scale_r);

    rotate_l->addChild(box_l);
    rotate_m->addChild(box_m);
    scale_r->addChild(box_r);


    scene = new Scene(root);
}
