#define PI 3.14159

#include "myglwidget.h"
#include <iostream>
#include <cmath>
#include <QTime>
#include <QTimer>



/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    QTimer *internalTimer = new QTimer( this ); // create internal timer
    connect( internalTimer, SIGNAL(timeout()), SLOT(updateGL()) );
    internalTimer->start(1000);

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

    paint_zeiger();
    paint_ziffernblatt();



}

/**************************************************************************************/
void MyGLWidget::paint_ziffernblatt()
{

    // Ziffernblatt

    float centerX = 0;
    float centerY = 0;
    float radius = 30;

    float a = PI * 2;

    // Markierungen der Ziffern
    float grad = 0;
    int ziffMakierung = 0;
    while(ziffMakierung<12)
    {

        glBegin(GL_QUADS);

            glColor3f(0,0,1);
            glVertex3f(sin((grad+3)*PI/180) * radius / 10 + centerX / 10, cos((grad+3)*PI/180)*radius / 10 + centerY / 10, 0);
            glVertex3f(sin((grad-3)*PI/180) * radius / 10 + centerX / 10, cos((grad-3)*PI/180)*radius / 10 + centerY / 10, 0);


            glVertex3f(sin((grad-3)*PI/180) * (radius-4) / 10 + centerX / 10, cos((grad-3)*PI/180)*(radius-4) / 10 + centerY / 10, 0);
            glVertex3f(sin((grad+3)*PI/180) * (radius-4) / 10 + centerX / 10, cos((grad+3)*PI/180)*(radius-4) / 10 + centerY / 10, 0);
        glEnd();

        grad +=30;
        ziffMakierung++;
    }


    glBegin(GL_POLYGON);

    glColor3f(1,0,0);
    while(a > 0)
    {

        glVertex3f(sin(a) * radius / 10 + centerX / 10, cos(a)*radius / 10 + centerY / 10, 0);
        a -= PI / 180.0;
    }
    glEnd ();







}
/**************************************************************************************/
void MyGLWidget::paint_zeiger()
{
    float centerX = 0;
    float centerY = 0;
    float radius = 30;

    QTime *time = new QTime(QTime::currentTime());


    float grad1 = time->hour() *30; //Stunden
    float grad2 = time->minute()*6; //Minuten
    float grad3 = time->second()*6; //Sekunden

    //Stunden
    glBegin(GL_TRIANGLES);

        glColor3f(1,1,0);
        glVertex3f(0,0, 0);
        glVertex3f(sin((grad1+4)*PI/180) * (radius/2) / 10 + centerX / 10 , cos((grad1+4)*PI/180)*(radius/2) / 10 + centerY / 10, 0);
        glVertex3f(sin((grad1-4)*PI/180) * (radius/2) / 10 + centerX / 10 , cos((grad1-4)*PI/180)*(radius/2) / 10 + centerY / 10, 0);

    glEnd();

    //Minuten
    glBegin(GL_TRIANGLES);

        glColor3f(0,1,0);
        glVertex3f(0,0, 0);
        glVertex3f(sin((grad2+2)*PI/180) * (radius-2) / 10 + centerX / 10, cos((grad2+2)*PI/180)*(radius-2) / 10 + centerY / 10, 0);
        glVertex3f(sin((grad2-2)*PI/180) * (radius-2) / 10 + centerX / 10, cos((grad2-2)*PI/180)*(radius-2) / 10 + centerY / 10, 0);
    glEnd();

    //Sekunden
    glBegin(GL_TRIANGLES);

        glColor3f(1,0,1);
        glVertex3f(0,0,0);
        glVertex3f(sin((grad3+3)*PI/180) * (radius-2) / 10 + centerX / 10, cos((grad3+3)*PI/180)*(radius-2) / 10 + centerY / 10, 0);
        glVertex3f(sin((grad3-3)*PI/180) * (radius-2) / 10 + centerX / 10, cos((grad3-3)*PI/180)*(radius-2) / 10 + centerY / 10, 0);
    glEnd();
}

/**************************************************************************************/

/**************************************************************************************/

