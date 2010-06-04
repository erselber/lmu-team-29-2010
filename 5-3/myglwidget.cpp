#define PI 3.14159

#include "myglwidget.h"
#include "scene.h"
#include "rootnode.h"
#include "boxnode.h"
#include "translatenode.h"
#include "rotatenode.h"
#include "scalenode.h"


//*************/

Scene *scene;
RotateNode *rotate_m;



/*************/

/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    initializeSCENE();
}

/**************************************************************************************/

void MyGLWidget::resizeGL(int w, int h){

    glViewport(0,0,w,h);



}

/**************************************************************************************/

void MyGLWidget::paintGL(){



    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1);


    rotate_m->setRotation(x_axis,0);
    rotate_m->setRotation(y_axis,1);
    rotate_m->setRotation(z_axis,2);


    scene->render();

}


/**************************************************************************************/

void MyGLWidget::rotateX(int value){


        x_axis =  value;
        updateGL();
}

/**************************************************************************************/

void MyGLWidget::rotateY(int value){


        y_axis =  value;
        updateGL();
}

/**************************************************************************************/

void MyGLWidget::rotateZ(int value){


        z_axis = value;
        updateGL();

}

/*************************************************************************************/

void MyGLWidget::initializeSCENE()
{


    /***  WURZEL vom Scenegraph  ***/

        RootNode *root = new RootNode();


    /*** LINKS vom Scenegraph  ***/

        RotateNode *rotate_l = new RotateNode(45,0,1,0);
        TranslateNode *trans_l = new TranslateNode(-2,0,0);

        BoxNode *box_l = new BoxNode();
        box_l->setColor(1,0,0);



    /*** RECHTS vom Scenegraph ***/

        TranslateNode *trans_r = new TranslateNode(2,0,0);
        RotateNode *rotate_r = new RotateNode(45,0,1,0);

        BoxNode *box_r = new BoxNode();
        box_r->setColor(0,0,1);




    /*** MITTE vom Scenegraph ( KAMERA )  ***/

        TranslateNode *trans_m = new TranslateNode(0,0,4);

        //variabel
        RotateNode *rotate_m = new RotateNode();

        CameraNode *camera = new CameraNode();


    /**** Einfügen der Kinder ****/




        root->addChild(trans_r);
        trans_r->addChild(rotate_r);
        rotate_r->addChild(box_r);


        root->addChild(trans_m);
        trans_m->addChild(rotate_m);
        rotate_m->addChild(camera);



        root->addChild(rotate_l);
        rotate_l->addChild(trans_l);
        trans_l->addChild(box_l);



    /*** Render Scenegraph  ***/
        scene = new Scene(root);
}
