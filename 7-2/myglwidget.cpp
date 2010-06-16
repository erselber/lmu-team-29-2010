#define PI 3.14159

#include "myglwidget.h"
#include "math.h"
#include <iostream>
#include "CTransform.h"



/*************************/
  /** VARIABLEN  **/
/*************************/

CTransform *trans = new CTransform();

GLfloat normalen[] = {0,0,1,
                      0,0,-1,
                      1,0,0,
                      -1,0,0,
                      0,0,1,
                      0,0,-1
                     };



/**************************************************************************************/
/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


    y_axis = 0;

    //Licht    

    GLfloat LigthAmbient[] = {0.8,0.0,0.0,1.0};
    GLfloat LigthDiffuse[] = {1.0,1.0,1.0,1.0};

    //Letztes 1 damit Punktlicktquelle
    GLfloat LigthPosition[] = {5.0,0.0,5.0,1};


    //Licht aktivieren
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT1,GL_AMBIENT,LigthAmbient);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,LigthDiffuse);
    glLightfv(GL_LIGHT1,GL_POSITION,LigthPosition);

    glEnable(GL_LIGHT1);

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

    glTranslated(0,0,-5);

    glRotated(20,1,0,0);
    glRotated(45,0,1,0);


    glBegin(GL_QUADS);

            //vorne
            glNormal3f(normalen[0],normalen[1],normalen[2]);
            glColor3f(1,0,0);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(-0.5,0.5,0.5);

            //hinten
            glNormal3f(normalen[3],normalen[4],normalen[5]);
            glColor3f(0,1,0);
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,-0.5,-0.5);

            //rechts
            glNormal3f(normalen[6],normalen[7],normalen[8]);
            glColor3f(0,0,1);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,0.5);

            //links
            glNormal3f(normalen[9],normalen[10],normalen[11]);
            glColor3f(1,0,1);
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,0.5,-0.5);

            //oben
            glNormal3f(normalen[12],normalen[13],normalen[14]);
            glColor3f(1,1,0);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,-0.5);

            //unten
            glNormal3f(normalen[15],normalen[16],normalen[17]);;
            glColor3f(0,1,1);
            glVertex3f(0.5,-0.5,-0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,-0.5,-0.5);

         glEnd();


}

/**************************************************************************************/
               /**  SLOTS SLOTS SLOTS  **/
/**************************************************************************************/
/**************************************************************************************/

void MyGLWidget::setYRotation(int angle)
{

    if (angle != y_axis) {
        y_axis = angle;

        std::cout << "Winkel = " << angle << std::endl;
        trans->print();

        trans->rotate(Y,angle);

        for(int i=0;i<18;i+=3)
        {
            trans->transform(&normalen[i],&normalen[i+1],&normalen[i+2]);
        }

        trans->resetMatrix();

        updateGL();
    }
}
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

