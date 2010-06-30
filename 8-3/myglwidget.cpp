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
    GLfloat LigthPosition_0[] = {0,8,-4,1}; //Letztes 1 damit Punktlicktquelle


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


    glTranslated(0,0,-10);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);





    drawSphere(2,5,8);


}

/**************************************************************************************/
void MyGLWidget::drawSphere(double r, int lats, int longs) {
      int i, j;

      for(i = 0; i <= lats; i++) {
          double lat0 = PI * (-0.5 + (double) (i - 1) / lats);
          double z0  = sin(lat0);
          double zr0 =  cos(lat0);

          //
          double lat1 = PI * (-0.5 + (double) i / lats);
          double z1 = sin(lat1);
          double zr1 = cos(lat1);

          glBegin(GL_QUAD_STRIP);
          for(j = 0; j <= longs; j++) {
              double lng = 2 * PI * (double) (j - 1) / longs;
              double x = cos(lng);
              double y = sin(lng);

              glNormal3f(x * zr0, y * zr0, z0);
              glVertex3f(x * zr0, y * zr0, z0);
              glNormal3f(x * zr1, y * zr1, z1);
              glVertex3f(x * zr1, y * zr1, z1);
          }
          glEnd();
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

