#define PI 3.14159


#include "myglwidget.h"
#include "math.h"
#include <iostream>


/*************************/
/** VARIABLEN  **/
/*************************/

int counter = 0;

GLdouble cubes[300];
/**************************************************************************************/
/**************************************************************************************/


void MyGLWidget::initializeGL(){

 glEnable(GL_DEPTH_TEST);
 glEnable(GL_CULL_FACE);

 glShadeModel(GL_FLAT);
/*
 for(int i=0;i<100;i++)
 {
     cubes[i][0] = 0;
     cubes[i][1] = 0;
     cubes[i][2] = 0;
 }
*/

}

/**************************************************************************************/

void MyGLWidget::resizeGL(int w, int h){

 glViewport(0,0, w,h);



}

/**************************************************************************************/

void MyGLWidget::paintGL(){

 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glClearColor(0,0,0,1);




 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();

 gluPerspective(45,1,1,100);

 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();


 for(int i=0;i<counter;i+=3)
 {
    glPushMatrix();

    glTranslated(cubes[i],-cubes[i+1],cubes[i+2]);//

    std::cout << "CUBES --------->" << cubes[i]<< " , " << cubes[i+1] << " , " << cubes[i+2] << std::endl;

    glRotated(-50,0,1,0);
    drawCube();

    glPopMatrix();
 }


}

/**************************************************************************************/
GLdouble* MyGLWidget::picking(QPoint mousepos)
{
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];

    GLfloat winX, winY, winZ;
    GLdouble pos[] = {0,0,0};

    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    winX = (GLfloat) mousepos.x();
    winY = (GLfloat) mousepos.y();

    winZ = 0.95;

    gluUnProject(winX,winY,winZ, modelview, projection, viewport, &pos[0], &pos[1], &pos[2]);

    return pos;
}

/**************************************************************************************/

void MyGLWidget::setCube(QMouseEvent *event)
{
    if(counter<300)
    {
        GLdouble *pos;
        pos = picking(event->pos());

        cubes[counter] = pos[0];
        cubes[counter+1] = pos[1];
        cubes[counter+2] = pos[2];

        counter+=3;

        std::cout << "Mouse EVent----------->" << event->pos().x() << " , " << event->pos().y() << std::endl;


        updateGL();
    }
}

/**************************************************************************************/

void MyGLWidget::drawCube(){

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


void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    setCube(event);
}

void MyGLWidget::keyPressEvent( QKeyEvent* event )
{
    event->ignore();

}

void MyGLWidget::keyReleaseEvent(QKeyEvent *event) {

 event->ignore();
}
/**************************************************************************************/


