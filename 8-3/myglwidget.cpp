   #define PI 3.14159

#include "myglwidget.h"
#include "math.h"
#include <iostream>

#include <QTime>
#include <QTimer>

/*************************/
  /** VARIABLEN  **/
/*************************/

GLfloat time_counter;



GLfloat xx;
GLfloat yy;
GLfloat zz;

GLfloat laenge;

int i;

int schicht = 5;
int sektor = 8;
GLfloat vertex_array[648]; // => schicht * sector * 3 (PUNKT)
GLfloat cube[648];
GLfloat bing[648];


GLfloat vertices[] = {
            -1,-1,1,
            1,-1,1,
            1,1,1,
            -1,1,1,
            1,-1,-1,
            -1,-1,-1,
            -1,1,-1,
            1,1,-1

     };


/**************************************************************************************/
/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);

    glShadeModel(GL_FLAT);

    /*** TIMER INITIALISIEREN ***/

    QTimer *internalTimer = new QTimer( this ); // create internal timer
    connect( internalTimer, SIGNAL(timeout()), SLOT(updateGL()) );
    internalTimer->start(1000);

    /****************************/

    time_counter = 0; // Aktuelle Zeit t

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
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0,GL_AMBIENT,LigthAmbient_0);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,LigthDiffuse_0);
    glLightfv(GL_LIGHT0,GL_POSITION,LigthPosition_0);


    /****************************************/


    drawSphere(1,schicht,sektor);


    /*
    for(int i=0;i<(sizeof(vertex_array)/4);i++)
    {
        std::cout << " Array[" << i << "] = " << cube[i] << std::endl;

        bing[i] = vertex_array[i];
    }

    */
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



    for(int i=0;i<(sizeof(vertex_array)/4);i+=3)
    {

        GLfloat vector[] = { cube[i]-vertex_array[i], cube[i+1]-vertex_array[i+1], cube[i+2]-vertex_array[i+2]};

        //Laenge des Vectors + time_old (t0) == ist der Zeitpunkt t1
        laenge = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]);


        if( ((round(bing[i] * 10) / 10)!= cube[i]) |
            ((round(bing[i+1] * 10) / 10)!= cube[i+1]) |
            ((round(bing[i+2] * 10) / 10)!= cube[i+2]))
        /*if( (round(bing[i])!=cube[i]) |
            (round(bing[i+1])!=cube[i+1]) |
                    (round(bing[i+2])!=cube[i+2]))*/
        {
            GLfloat time = (time_counter)/(laenge); //-time_old



            bing[i] = vertex_array[i] + time * (cube[i]-vertex_array[i]);
            bing[i+1] = vertex_array[i+1] + time * (cube[i+1]-vertex_array[i+1]);
            bing[i+2] = vertex_array[i+2] + time * (cube[i+2]-vertex_array[i+2]);

           /* std::cout << " x: " << bing[i] << " y: " <<
                    bing[i+1] << " z: " << bing[i+2]
                    << " Laenge: " << laenge << " Counter: "<< i<< std::endl;*/


        }
    }




    time_counter+=0.1;



    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);


    glNormalPointer(GL_FLOAT,0,cube);
    glVertexPointer(3,GL_FLOAT,0,cube);

    //192
    glDrawArrays(GL_QUADS,0,648);

    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);





}

/**************************************************************************************/
void MyGLWidget::drawSphere(double r, int lats, int longs) {
      int i, j;

      int k = 0;
      for(i = 0; i <= lats; i++) {
          double lat0 = PI * (-0.5 + (double) (i - 1) / lats);
          double z0  = sin(lat0);
          double zr0 =  cos(lat0);


          double lat1 = PI * (-0.5 + (double) i / lats);
          double z1 = sin(lat1);
          double zr1 = cos(lat1);


          for(j = 0; j <= longs; j++) {
              double lng = 2 * PI * (double) (j - 1) / longs;
              double x = cos(lng);
              double y = sin(lng);

              double lng_2 = 2 * PI * (double) j / longs;
              double x_2 = cos(lng_2);
              double y_2 = sin(lng_2);


              vertex_array[k] = x*zr0;
              vertex_array[k+1] = y*zr0;
              vertex_array[k+2] = z0;

              vertex_array[k+3] = x*zr1;
              vertex_array[k+4] = y*zr1;
              vertex_array[k+5] = z1;

              vertex_array[k+6] = x_2*zr1;
              vertex_array[k+7] = y_2*zr1;
              vertex_array[k+8] = z1;

              vertex_array[k+9] = x_2*zr0;
              vertex_array[k+10] = y_2*zr0;
              vertex_array[k+11] = z0;

              std::cout << " Ausgabe: z0 = " << z0 << " || zr0 = " << zr0 << " || x = "
                      << x << " || y = " << y << std::endl;



                /*
              cube[k] = x*zr0;
              cube[k+1] = y*zr0;
              cube[k+2] = z0;

              cube[k+3] = x*zr1;
              cube[k+4] = y*zr1;
              cube[k+5] = z1;

              cube[k+6] = x_2*zr1;
              cube[k+7] = y_2*zr1;
              cube[k+8] = z1;

              cube[k+9] = x_2*zr0;
              cube[k+10] = y_2*zr0;
              cube[k+11] = z0;
              */

              cube[k] = x;
              cube[k+1] = y;
              cube[k+2] = z0;

              cube[k+3] = x;
              cube[k+4] = y;
              cube[k+5] = z1;

              cube[k+6] = x_2;
              cube[k+7] = y_2;
              cube[k+8] = z1;

              cube[k+9] = x_2;
              cube[k+10] = y_2;
              cube[k+11] = z0;

              k+=12;


          }
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

