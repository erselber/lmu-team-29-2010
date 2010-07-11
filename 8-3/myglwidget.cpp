#define PI 3.14159


#include "myglwidget.h"
#include "math.h"
#include <iostream>

#include <QTime>
#include <QTimer>

/*************************/
/** VARIABLEN  **/
/*************************/

int schicht = 5;
int sektor = 8;

GLfloat sphere_array[480]; // => schicht * sector * 3 (PUNKT)
GLfloat cube_array[480];

GLfloat bing_1[480];
GLfloat bing_2[480];
GLfloat cube[3];

int switcher=0;

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
 /****************************/


 drawSphere(1,schicht,sektor);

}

/**************************************************************************************/

void MyGLWidget::resizeGL(int w, int h){

 glViewport(0,0, w,h);



}

/**************************************************************************************/
/**************************************************************************************/

void MyGLWidget::paintGL(){

 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glClearColor(0,0,0,1);




 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();

 gluPerspective(45,1,1,1000);

 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();


 glTranslated(0,0,-10);

 glRotated(90,1,0,0);
 //glRotated(-80,0,1,0);


 /****************************************************/


 if(switcher%2==0)
 {
    for(int i=0;i<480;i++)
    {
           if((round(bing_1[i] * 10) / 10)!=cube_array[i])
           {
              bing_1[i] += (cube_array[i]-sphere_array[i])/2000;
              bing_2[i] += (sphere_array[i]-cube_array[i])/2000;
           }
    }
 }
 else
 {
    for(int i=0;i<480;i++)
    {
            if((round(bing_2[i] * 10) / 10)!=cube_array[i])
            {
               bing_2[i] += (cube_array[i]-sphere_array[i])/2000;
               bing_1[i] += (sphere_array[i]-cube_array[i])/2000;
            }
     }

 }


 /****************************************************/


 glPushMatrix();

 glTranslated(-2,0,0);

 glEnableClientState(GL_VERTEX_ARRAY);
 glEnableClientState(GL_NORMAL_ARRAY);



 glNormalPointer(GL_FLOAT,0,bing_1);
 glVertexPointer(3,GL_FLOAT,0,bing_1);

 glDrawArrays(GL_QUADS,0,160);

 glDisableClientState(GL_NORMAL_ARRAY);
 glDisableClientState(GL_VERTEX_ARRAY);

 glPopMatrix();



 glPushMatrix();

 glTranslated(2,0,0);

 glEnableClientState(GL_VERTEX_ARRAY);
 glEnableClientState(GL_VERTEX_ARRAY);

 glEnableClientState(GL_NORMAL_ARRAY);


 glNormalPointer(GL_FLOAT,0,bing_2);
 glVertexPointer(3,GL_FLOAT,0,bing_2);

 glDrawArrays(GL_QUADS,0,160);

 glDisableClientState(GL_NORMAL_ARRAY);
 glDisableClientState(GL_VERTEX_ARRAY);

 glPopMatrix();


}

/**************************************************************************************/


/**************************************************************************************/
void MyGLWidget::drawSphere(double rad, int lats, int longs) {

 int k=0;
 for(int a=0;a!=lats;a++)
 {

     for(int c=0;c!=longs;c++)
     {
         sphere_array[k] = cos(2*PI/lats*a)*cos(PI/longs*c-PI/2)*rad;
         sphere_array[k+1] =  sin(2*PI/lats*a)*cos(PI/longs*c-PI/2)*rad;
         sphere_array[k+2] = sin(PI/longs*c-PI/2)*rad;

         sphere_array[k+3] = cos(2*PI/lats*(a+1))*cos(PI/longs*c-PI/2)*rad;
         sphere_array[k+4] = sin(2*PI/lats*(a+1))*cos(PI/longs*c-PI/2)*rad;
         sphere_array[k+5] = sin(PI/longs*c-PI/2)*rad;

         sphere_array[k+6] = cos(2*PI/lats*(a+1))*cos(PI/longs*(c+1)-PI/2)*rad;
         sphere_array[k+7] = sin(2*PI/lats*(a+1))*cos(PI/longs*(c+1)-PI/2)*rad;
         sphere_array[k+8] = sin(PI/longs*(c+1)-PI/2)*rad;

         sphere_array[k+9] =  cos(2*PI/lats*a)*cos(PI/longs*(c+1)-PI/2)*rad;
         sphere_array[k+10] = sin(2*PI/lats*a)*cos(PI/longs*(c+1)-PI/2)*rad;
         sphere_array[k+11] = sin(PI/longs*(c+1)-PI/2)*rad;


         k +=12;

     }
 }

 for(int m=0; m < 480 ; m+=3)
 {


          getCube(sphere_array[m],0);
          cube_array[m] = cube[0];

          getCube(sphere_array[m+1],1);
          cube_array[m+1] = cube[1];

          getCube(sphere_array[m+2],2);
          cube_array[m+2] = cube[2];

          std::cout << "KOORDINATE = " << m << " x: " << cube_array[m] << " y: " <<
          cube_array[m+1] << " z: " <<cube_array[m+2]
          << std::endl;

          bing_1[m] = sphere_array[m];
          bing_1[m+1] = sphere_array[m+1];
          bing_1[m+2] = sphere_array[m+2];

          bing_2[m] = cube_array[m];
          bing_2[m+1] = cube_array[m+1];
          bing_2[m+2] = cube_array[m+2];

 }

}
/**************************************************************************************/

void MyGLWidget::getCube(GLfloat x, int i)
{

 if(x<=0.0)
 {
     cube[i] = -1;
 }
 else
 {
     cube[i] = 1;
 }


}

/**************************************************************************************/
/**************************************************************************************/
/**************************************************************************************/

void MyGLWidget::keyPressEvent( QKeyEvent* event )
{

 if(event->key() == Qt::Key_Space)
 {

     std::cout << " KEY PRESSED = " << std::endl;
     switcher++;

 }

}

void MyGLWidget::keyReleaseEvent(QKeyEvent *event) {

 event->ignore();
}
/**************************************************************************************/


