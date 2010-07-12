#define PI 3.14159


#include "myglwidget.h"
#include "math.h"
#include <iostream>


/*************************/
/** VARIABLEN  **/
/*************************/

int counter = 0;

GLdouble cubes[100][3];
/**************************************************************************************/
/**************************************************************************************/


void MyGLWidget::initializeGL(){

 glEnable(GL_DEPTH_TEST);
 glEnable(GL_CULL_FACE);

 glShadeModel(GL_FLAT);


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

 gluPerspective(45,1,1,1000);

 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();


 glTranslated(0,0,-1);


 for(int i=0;i<counter;i++)
 {
    glPushMatrix();

    glTranslated(cubes[counter][0],cubes[counter][1],0);

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

    winZ = -1.0;

    gluUnProject(winX,winY,winZ, modelview, projection, viewport, &pos[0], &pos[1], &pos[2]);

    std::cout << "POS[0] POS[1]----------->" << pos[0] << " , " << pos[1] << std::endl;
    return pos;
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
void MyGLWidget::setCube(QMouseEvent *event)
{
    GLdouble *position = (GLdouble*) malloc(3);

    position = picking(event->pos());


    cubes[counter][0] = position[0];
    cubes[counter][1] = position[1];
    cubes[counter][2] = position[2];

    counter++;

    std::cout << "Mouse EVent----------->" << event->pos().x() << " , " << event->pos().y() << std::endl;

    std::cout << "Mouse EVent---------->" << position[0] << " , " << position[1] << std::endl;

   updateGL();
}

/**************************************************************************************/

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{

    setCube(event);
}

void MyGLWidget::keyPressEvent( QKeyEvent* event )
{

 if(event->key() == Qt::Key_Space)
 {

    event->ignore();


 }

}

void MyGLWidget::keyReleaseEvent(QKeyEvent *event) {

 event->ignore();
}
/**************************************************************************************/


