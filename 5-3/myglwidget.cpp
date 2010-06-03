#define PI 3.14159

#include "myglwidget.h"
#include "scene.h"
#include "rootnode.h"
#include "boxnode.h"
#include "translatenode.h"
#include "rotatenode.h"
#include "scalenode.h"
/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


}

/**************************************************************************************/

void MyGLWidget::resizeGL(int w, int h){

    glViewport(0,0, 800,800);



}

/**************************************************************************************/

void MyGLWidget::paintGL(){

    //

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1);



    RootNode *root = new RootNode();
    TranslateNode *tnode = new TranslateNode(0,0,-10);
    root->addChild(tnode);

    RotateNode *rnode = new RotateNode(-20,1,0,0);
    tnode->addChild(rnode);

    TranslateNode *t2node = new TranslateNode(-5,0,0);
    TranslateNode *t3node = new TranslateNode(0,0,0);
    TranslateNode *t4node = new TranslateNode(5,0,0);

    rnode->addChild(t2node);
    rnode->addChild(t3node);
    rnode->addChild(t4node);

    RotateNode *r2node = new RotateNode(45,0,1,0);
    t2node->addChild(r2node);

    RotateNode *r3node = new RotateNode(45,0,0,1);
    t3node->addChild(r3node);

    ScaleNode *s4node = new ScaleNode(2,2,2);
    t4node->addChild(s4node);


    BoxNode *box1 = new BoxNode();
    box1->setColor(1,1,1);

    r2node->addChild(box1);


    BoxNode *box2 = new BoxNode();
    box2->setColor(1,0,1);
    r3node->addChild(box2);

    BoxNode *box3 = new BoxNode();
    box3->setColor(0,0,1);
    s4node->addChild(box3);

    Scene *scene = new Scene(root);
    scene->render();




}
