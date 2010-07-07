#define PI 3.14159

#include "myglwidget.h"
#include "math.h"
#include <iostream>
#include "quaternion.h"

#include <QTime>
#include <QTimer>

/*************************/
/** VARIABLEN  **/
/*************************/

GLfloat normalen[] = {0,0,1,
                      0,0,-1,
                      1,0,0,
                      -1,0,0,
                      0,0,1,
                      0,0,-1
                     };

float x_vector[] = {1,0,0};
float z_vector[] = {0,0,1};
Quaternion *q1;
Quaternion *q2;

/**************************************************************************************/
/**************************************************************************************/


void MyGLWidget::initializeGL(){

 glEnable(GL_DEPTH_TEST);
 glEnable(GL_CULL_FACE);

 glShadeModel(GL_FLAT);

 /*** TIMER INITIALISIEREN ***/

 QTimer *internalTimer = new QTimer( this ); // create internal timer
 connect( internalTimer, SIGNAL(timeout()), SLOT(updateGL()) );
 internalTimer->start(100);

 /****************************/

 /****************************/

 x_axis = 0;
 y_axis = 0;
 z_axis = 0;


 /*************************************/
 //Licht

 GLfloat LigthDiffuse_0[] = {.9,.9,.9,.9};
 GLfloat LigthAmbient_0[] = {.8,.8,.8};
 GLfloat LigthPosition_0[] = {0,1,0,1}; //Letztes 1 damit Punktlicktquelle


 //Licht aktivieren
 //glEnable(GL_LIGHTING);

 //glEnable(GL_LIGHT0);

 glLightfv(GL_LIGHT0,GL_AMBIENT,LigthAmbient_0);
 glLightfv(GL_LIGHT0,GL_DIFFUSE,LigthDiffuse_0);
 glLightfv(GL_LIGHT0,GL_POSITION,LigthPosition_0);



 /****************************************/


 q1 = new Quaternion(10, x_vector);
 q2 = new Quaternion(10, x_vector);


}

/**************************************************************************************/

void MyGLWidget::resizeGL(int w, int h){

 glViewport(0,0, w,h);



}

/**************************************************************************************/
/**************************************************************************************/

void MyGLWidget::paintGL(){

 /*****************************/



 /*******************************/

 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glClearColor(0,0,0,1);



 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();

 gluPerspective(45,1,1,1000);

 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();



 glTranslated(0,0,-5);

 GLfloat matrix[16];
 glGetFloatv(GL_MODELVIEW_MATRIX,matrix);
 q1->quatToMatrix(matrix);

 glMultMatrixf(matrix);

 draw_Cube();

 q1->multiply(q1,q2);


}
/**************************************************************************************/

void MyGLWidget::draw_Cube(){

    glBegin(GL_QUADS);
                //glNormal3f(normalen[0],normalen[1],normalen[2]);

                glColor3f(1,0,0);

                glVertex3f(-0.5,-0.5,0.5);
                glVertex3f(0.5,-0.5,0.5);
                glVertex3f(0.5,0.5,0.5);
                glVertex3f(-0.5,0.5,0.5);

                //hinten
                //glNormal3f(normalen[3],normalen[4],normalen[5]);
                glColor3f(0,0,1);

                glVertex3f(-0.5,-0.5,-0.5);
                glVertex3f(-0.5,0.5,-0.5);
                glVertex3f(0.5,0.5,-0.5);
                glVertex3f(0.5,-0.5,-0.5);

                //rechts
                //glNormal3f(normalen[6],normalen[7],normalen[8]);
                glColor3f(0,1,0);

                glVertex3f(0.5,-0.5,0.5);
                glVertex3f(0.5,-0.5,-0.5);
                glVertex3f(0.5,0.5,-0.5);
                glVertex3f(0.5,0.5,0.5);

                //links
                //glNormal3f(normalen[9],normalen[10],normalen[11]);
                glColor3f(1,0,1);

                glVertex3f(-0.5,-0.5,-0.5);
                glVertex3f(-0.5,-0.5,0.5);
                glVertex3f(-0.5,0.5,0.5);
                glVertex3f(-0.5,0.5,-0.5);

                //oben
                //glNormal3f(normalen[12],normalen[13],normalen[14]);
                glColor3f(1,1,0);

                glVertex3f(-0.5,0.5,0.5);
                glVertex3f(0.5,0.5,0.5);
                glVertex3f(0.5,0.5,-0.5);
                glVertex3f(-0.5,0.5,-0.5);

                //unten
                //glNormal3f(normalen[15],normalen[16],normalen[17]);;
                glColor3f(0,1,1);

                glVertex3f(0.5,-0.5,-0.5);
                glVertex3f(0.5,-0.5,0.5);
                glVertex3f(-0.5,-0.5,0.5);
                glVertex3f(-0.5,-0.5,-0.5);

             glEnd();

}

/**************************************************************************************/
/**************************************************************************************/
            /**  SLOTS SLOTS SLOTS  **/
/**************************************************************************************/
/**************************************************************************************/

void MyGLWidget::setXRotation(int angle)
{

 if (angle != x_axis) {
     x_axis = angle;
     //emit xRotationChanged(angle);

     q1 = new Quaternion(x_axis, x_vector);
     updateGL();
 }
}

/**************************************************************************************/

void MyGLWidget::setYRotation(int angle)
{

 if (angle != y_axis) {
     y_axis = angle;
     //emit yRotationChanged(angle);
     updateGL();
 }
}
/**************************************************************************************/

void MyGLWidget::setZRotation(int angle)
{

 if (angle != z_axis) {
     z_axis = angle;
     //emit zRotationChanged(angle);


     q2 = new Quaternion(z_axis, z_vector);
     updateGL();
 }
}

/**************************************************************************************/
