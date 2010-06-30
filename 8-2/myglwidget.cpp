#define PI 3.14159

#include "myglwidget.h"
#include "math.h"
#include <iostream>

#include <QTime>
#include <QTimer>

/*************************/
  /** VARIABLEN  **/
/*************************/

GLfloat pfad[] = {1,0,1,
                 4,2,4,
                 8,3,1,
                 3,4,-3,
                 5,2,8, //-------------
               };


GLfloat time_counter;
GLfloat time_old;

GLfloat xx;
GLfloat yy;
GLfloat zz;

GLfloat laenge;

int i;

/**************************************************************************************/
/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glShadeModel(GL_FLAT);

    /*** TIMER INITIALISIEREN ***/

    QTimer *internalTimer = new QTimer( this ); // create internal timer
    connect( internalTimer, SIGNAL(timeout()), SLOT(updateGL()) );
    internalTimer->start(10);

    /****************************/

    time_counter = 0; // Aktuelle Zeit t
    time_old = 0; // Zeitpunkt t0
    i = 0;

    /****************************/

    x_axis = 0;
    y_axis = 0;
    z_axis = 0;


    /*************************************/
    //Licht

    GLfloat LigthDiffuse_0[] = {.9,.9,.9,.9};
    GLfloat LigthAmbient_0[] = {.2,.2,.2};
    GLfloat LigthPosition_0[] = {-4,4,0,1}; //Letztes 1 damit Punktlicktquelle


    //Licht aktivieren
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0,GL_AMBIENT,LigthAmbient_0);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,LigthDiffuse_0);
    glLightfv(GL_LIGHT0,GL_POSITION,LigthPosition_0);


    /****************************************/



}

/**************************************************************************************/

void MyGLWidget::resizeGL(int w, int h){

    glViewport(0,0, w,h);



}

/**************************************************************************************/
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


    glTranslated(0,0,-20);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);





        GLfloat vector[] = { pfad[i+3]-pfad[i], pfad[i+4]-pfad[i+1], pfad[i+5]-pfad[i+2]};

        //Laenge des Vectors + time_old (t0) == ist der Zeitpunkt t1
        laenge = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]) + time_old;



        if( ((round(xx * 10) / 10)!=pfad[i+3]) | ((round(yy * 10) / 10)!=pfad[i+4]) | ((round(zz * 10) / 10)!=pfad[i+5]))
        {
            GLfloat time = (time_counter-time_old)/(laenge-time_old);



            xx = pfad[i] + time * (pfad[i+3]-pfad[i]);
            yy = pfad[i+1] + time * (pfad[i+4]-pfad[i+1]);
            zz = pfad[i+2] + time * (pfad[i+5]-pfad[i+2]);

           //std::cout << " x: " << xx << " y: " << yy << " z: " << zz << " Laenge: " << laenge << " Counter: "<< i<< std::endl;


            glPushMatrix();
            glTranslated(xx,yy,zz);

            GLUquadricObj *quad = gluNewQuadric();
            gluSphere(quad,1.0,40,20);

            glPopMatrix();

        }
        else
        {
            glTranslated(round(xx),round(yy),round(zz));

            std::cout << " x y z = " << round(xx) << " " << round(yy) << " "<< round(zz)<< std::endl;

            GLUquadricObj *quad = gluNewQuadric();
            gluSphere(quad,1.0,40,20);



            if(i < (sizeof(pfad)/4)-3)
            {
             i+=3;
             time_old = time_counter;
            }

        }


        time_counter+=0.1;

        // Rheienfolge des Arrays tauschen und i=0
        if(i==(sizeof(pfad)/4)-3)
        {
           swap_pfad();
           i=0;
        }

}

/**************************************************************************************/

void MyGLWidget::swap_pfad()
{


    int length = sizeof(pfad)/4;

    GLfloat tmp_pfad[length];

    for(int i=0;i<length;i++)
    {
        tmp_pfad[i] = pfad[i];
    }

    int k=0;
    for(int j=length-1;j>0;j-=3)
    {
        pfad[k] = tmp_pfad[j-2];
        pfad[k+1] = tmp_pfad[j-1];
        pfad[k+2] = tmp_pfad[j];

        k+=3;
    }


}

/**************************************************************************************/


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
        //emit zRotationChanged(angle);        updateGL();
    }
}

/**************************************************************************************/
/**************************************************************************************/

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();


    if (event->buttons() & Qt::LeftButton) {
        setXRotation(x_axis + 8 * dy);
        setYRotation(y_axis + 8 * dx);
    }
    lastPos = event->pos();
}


/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

