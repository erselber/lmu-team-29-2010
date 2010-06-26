#define PI 3.14159

#include "myglwidget.h"
#include "math.h"
#include <iostream>



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



/**************************************************************************************/
/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


    dimm_grad = 50;

    //Licht



    /******************************************************/

    // DIMMGRAD initialisieren ---> LIGTHDIFFUSE mit 1 //
    GLfloat LigthDiffuse_0[] = {0.5,0.5,0.5,0.5};
    GLfloat LigthAmbient_0[] = {0.2,0.2,0.2};
    GLfloat LigthPosition_0[] = {0,1,2,1}; //Letztes 1 damit Punktlicktquelle


    //Licht aktivieren
    glEnable(GL_LIGHTING);


    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_AMBIENT,LigthAmbient_0);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,LigthDiffuse_0);
    glLightfv(GL_LIGHT0,GL_POSITION,LigthPosition_0);


    /******************************************************/

    GLfloat LigthDiffuse_1[] = {0,0,1,1};
    GLfloat LigthAmbient_1[] = {1,1,1};
    GLfloat LigthPosition_1[] = {2,9,-3,1};

    GLfloat spotDirection_1[] = {0,-1,-1};

    glEnable(GL_LIGHT1);

    glLightfv(GL_LIGHT1,GL_AMBIENT,LigthAmbient_1);
    glLightfv(GL_LIGHT1,GL_DIFFUSE,LigthDiffuse_1);
    glLightfv(GL_LIGHT1,GL_POSITION,LigthPosition_1);

    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spotDirection_1);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF,13.);    	// set cutoff angle
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT,2.0);   	// set focusing strength




    /******************************************************/

    GLfloat LigthDiffuse_2[] = {1,0,0,1};
    GLfloat LigthAmbient_2[] = {1,1,1};
    GLfloat LigthPosition_2[] = {-2,10,-3,1};



    GLfloat spotDirection_2[] = {0,-1,-1};


    glLightfv(GL_LIGHT2,GL_AMBIENT,LigthAmbient_2);
    glLightfv(GL_LIGHT2,GL_DIFFUSE,LigthDiffuse_2);
    glLightfv(GL_LIGHT2,GL_POSITION,LigthPosition_2);

    glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,spotDirection_2);

    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF,13.0);    	// set cutoff angle
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT,2.0);   	// set focusing strength


    glEnable(GL_LIGHT2);




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

    glTranslated(0,0,-15);

    glRotated(20,1,0,0);
    //glRotated(45,0,1,0);


    // Zeichnung Kubus
    glPushMatrix();

    glTranslated(-2,0.5,0);
    draw_Cube();

    glPopMatrix();


    // Zeichnung Kugel
    GLUquadricObj *quad = gluNewQuadric();

    glPushMatrix();

    glTranslated(2,0.9,0);
    gluSphere(quad,1.0,20,20);

    glPopMatrix();


    // Zeichnung Ebene
    glPushMatrix();

    glBegin(GL_QUADS);
    //glColor3f(1,0,0);
    glNormal3f(0,1,0);

    glVertex3f(-3,0,3);
    glVertex3f(3,0,3);
    glVertex3f(3,0,-3);
    glVertex3f(-3,0,-3);

    glEnd();


    glPopMatrix();
}

/**************************************************************************************/
/**************************************************************************************/

void MyGLWidget::draw_Cube(){

    glBegin(GL_QUADS);

            //vorne
            glNormal3f(normalen[0],normalen[1],normalen[2]);
            //glColor3f(1,0,0);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(-0.5,0.5,0.5);

            //hinten
            glNormal3f(normalen[3],normalen[4],normalen[5]);
            //glColor3f(0,1,0);
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,-0.5,-0.5);

            //rechts
            glNormal3f(normalen[6],normalen[7],normalen[8]);
            //glColor3f(0,0,1);
            glVertex3f(0.5,-0.5,0.5);
            glVertex3f(0.5,-0.5,-0.5);
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,0.5,0.5);

            //links
            glNormal3f(normalen[9],normalen[10],normalen[11]);
            //glColor3f(1,0,1);
            glVertex3f(-0.5,-0.5,-0.5);
            glVertex3f(-0.5,-0.5,0.5);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(-0.5,0.5,-0.5);

            //oben
            glNormal3f(normalen[12],normalen[13],normalen[14]);
            //glColor3f(1,1,0);
            glVertex3f(-0.5,0.5,0.5);
            glVertex3f(0.5,0.5,0.5);
            glVertex3f(0.5,0.5,-0.5);
            glVertex3f(-0.5,0.5,-0.5);

            //unten
            glNormal3f(normalen[15],normalen[16],normalen[17]);;
            //glColor3f(0,1,1);
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

void MyGLWidget::dimmen(int value)
{

    if (value != dimm_grad) {
        dimm_grad = ( (GLfloat)value / 100 );


        GLfloat LigthDiffuse[] = {dimm_grad,dimm_grad,dimm_grad,dimm_grad};

        std::cout << "Wert DIMMGRAD ---------> " << dimm_grad << std::endl;
        glLightfv(GL_LIGHT0,GL_DIFFUSE,LigthDiffuse);


        updateGL();
    }
}
/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

