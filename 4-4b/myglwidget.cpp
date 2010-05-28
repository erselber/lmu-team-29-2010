#define PI 3.14159

#include "myglwidget.h"
#include <iostream>
#include <cmath>
#include <qevent.h>



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

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,1,1000);



    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslated(0,0,-10);

    glRotated(y_axis,0,1,0);

    paint_cube();


}


/**************************************************************************************/
void MyGLWidget::paint_cube()
{



        /********** Wuerfel  1*********/
        glPushMatrix();

        glTranslated(-2,0,0);

        glBegin(GL_QUADS);

            //vorne (rot)

            glColor3f(1,0,0);
            glVertex3f(-1,-1,1);
            glVertex3f(1,-1,1);
            glVertex3f(1,1,1);
            glVertex3f(-1,1,1);

            //hinten (gruen)

            glColor3f(0,1,0);
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,1,-1);
            glVertex3f(1,1,-1);
            glVertex3f(1,-1,-1);

            //rechts (blau)

            glColor3f(0,0,1);
            glVertex3f(1,-1,1);
            glVertex3f(1,-1,-1);
            glVertex3f(1,1,-1);
            glVertex3f(1,1,1);

            //links (gelb)

            glColor3f(1,1,0);
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,-1,1);
            glVertex3f(-1,1,1);
            glVertex3f(-1,1,-1);

            //oben (hell blau)

            glColor3f(0,1,1);
            glVertex3f(-1,1,1);
            glVertex3f(1,1,1);
            glVertex3f(1,1,-1);
            glVertex3f(-1,1,-1);

            //unten (rosa)

            glColor3f(1,0,1);
            glVertex3f(1,-1,-1);
            glVertex3f(1,-1,1);
            glVertex3f(-1,-1,1);
            glVertex3f(-1,-1,-1);

         glEnd();

        glPopMatrix();


        /********** Wuerfel  2*********/
        glPushMatrix();

        glTranslated(2,0,0);

        glBegin(GL_QUADS);

            //vorne (rot)

            glColor3f(1,0,0);
            glVertex3f(-1,-1,1);
            glVertex3f(1,-1,1);
            glVertex3f(1,1,1);
            glVertex3f(-1,1,1);

            //hinten (gruen)

            glColor3f(0,1,0);
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,1,-1);
            glVertex3f(1,1,-1);
            glVertex3f(1,-1,-1);

            //rechts (blau)

            glColor3f(0,0,1);
            glVertex3f(1,-1,1);
            glVertex3f(1,-1,-1);
            glVertex3f(1,1,-1);
            glVertex3f(1,1,1);

            //links (gelb)

            glColor3f(1,1,0);
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,-1,1);
            glVertex3f(-1,1,1);
            glVertex3f(-1,1,-1);

            //oben (hell blau)

            glColor3f(0,1,1);
            glVertex3f(-1,1,1);
            glVertex3f(1,1,1);
            glVertex3f(1,1,-1);
            glVertex3f(-1,1,-1);

            //unten (rosa)

            glColor3f(1,0,1);
            glVertex3f(1,-1,-1);
            glVertex3f(1,-1,1);
            glVertex3f(-1,-1,1);
            glVertex3f(-1,-1,-1);

         glEnd();

        glPopMatrix();
}

/**************************************************************************************/


void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();

    if(event->button() == Qt::LeftButton)
    {

    }

}
/**************************************************************************************/

void MyGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    lastPos = event->pos();

}

/*************************************************************************************/
void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();



    lastPos = event->pos();
    updateGL();
}


/*************************************************************************************/
void MyGLWidget::rotate_Y_axis(QMouseEvent *event)
{
    while(event->MouseButtonPress)
    {   y_axis +=10;
        updateGL();

    }
}
