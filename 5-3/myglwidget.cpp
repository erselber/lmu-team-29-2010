#define PI 3.14159

#include "myglwidget.h"
#include "scene.h"
#include "rootnode.h"
#include "boxnode.h"
#include "translatenode.h"
#include "rotatenode.h"
#include "scalenode.h"

#include "qmenu.h"
#include "QContextMenuEvent"
#include "qlabel.h"

//*************/

Scene *scene;
RotateNode *rotate_m;
TranslateNode *trans_m;

/*************/

/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    initializeSCENE();

    this->setContextMenuPolicy(Qt::DefaultContextMenu);
}

/**************************************************************************************/

void MyGLWidget::resizeGL(int w, int h){

    glViewport(0,0,w,h);



}

/**************************************************************************************/

void MyGLWidget::paintGL(){



    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1);


    //rotate_m->setRotation(x_axis,1,0,0);

    //trans_m->setTranslation(0,0,x_axis);

    scene->render();

}


/**************************************************************************************/

void MyGLWidget::rotateX(int value){


        x_grad =  value;
        // Achse X = 1
        rotate_m->setRotation(x_grad,0);;
        updateGL();
}

/**************************************************************************************/

void MyGLWidget::rotateY(int value){


        y_grad =  value;
        // Achse Y = 1
        rotate_m->setRotation(y_grad,1);
        updateGL();
}

/**************************************************************************************/

void MyGLWidget::rotateZ(int value){

        z_grad = value;

        // Achse Z = 2
        rotate_m->setRotation(z_grad,2);
        updateGL();

}

/*************************************************************************************/

void MyGLWidget::initializeSCENE()
{


    /***  WURZEL vom Scenegraph  ***/

        RootNode *root = new RootNode();


    /*** LINKS vom Scenegraph  ***/

        RotateNode *rotate_l = new RotateNode(45,0,1,0,"Rotation Links");
        TranslateNode *trans_l = new TranslateNode(-2,0,0, "Traslation Links");

        BoxNode *box_l = new BoxNode("Box Links");
        box_l->setColor(1,0,0);



    /*** RECHTS vom Scenegraph ***/

        TranslateNode *trans_r = new TranslateNode(2,0,0,"Translation Rechts");
        RotateNode *rotate_r = new RotateNode(45,0,1,0,"Rotation Rechts");

        BoxNode *box_r = new BoxNode("Box Rechts");
        box_r->setColor(0,0,1);




    /*** MITTE vom Scenegraph ( KAMERA )  ***/

        trans_m = new TranslateNode(0,0,8,"Translation MITTE");

        //variabel
        rotate_m = new RotateNode(0,0,0,0,"Rotation MITTE");

        CameraNode *camera = new CameraNode();

        root->setCamera(camera);



    /**** Einfügen der Kinder ****/

        root->addChild(rotate_l);
        rotate_l->addChild(trans_l);
        trans_l->addChild(box_l);


        root->addChild(trans_m);
        trans_m->addChild(rotate_m);
        rotate_m->addChild(camera);


        root->addChild(trans_r);
        trans_r->addChild(rotate_r);
        rotate_r->addChild(box_r);




    /*** Render Scenegraph  ***/
        scene = new Scene(root);
}

/**************************************************************************************/


void MyGLWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu* contextMenu = new QMenu( this );

    contextMenu->addAction("&Blaue BOX",this,SLOT(setBlue(void)));
    contextMenu->addAction("&Rote BOX",this,SLOT(setRed(void)));

    contextMenu->exec( QCursor::pos() );
    delete contextMenu;

}

/**************************************************************************************/
void MyGLWidget::setBlue(){

    rotate_m->setRotation(80,2);
    updateGL();
}

/**************************************************************************************/
void MyGLWidget::setRed(){

    //rotate_m->setRotation(40,1);
    gluLookAt(0,0,4,0,0,0,0,1,0);
    updateGL();
}
