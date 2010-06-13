#define PI 3.14159

#include "myglwidget.h"
#include "QMouseEvent"
#include "math.h"
#include <iostream>



/*************************/
  /** VARIABLEN  **/
/*************************/


/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

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



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45,1,1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslated(0,-2,-10);
    glScaled(0.5,0.5,0.5);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);



}




/**************************************************************************************/
               /**  SLOTS SLOTS SLOTS  **/
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

