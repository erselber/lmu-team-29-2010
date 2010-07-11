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
GLfloat time_old;

GLfloat laenge;
GLfloat laenge_2;

int switcher = 0;

int schicht = 5;
int sektor = 8;

GLfloat sphere_array[480]; // => schicht * sector * 3 (PUNKT)
GLfloat cube_array[480];

GLfloat tmp_array[480];

GLfloat bing_1[480];
GLfloat bing_2[480];
GLfloat cube[3];




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
    /****************************/

    time_counter = 0; // Aktuelle Zeit t

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


    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);



    drawBOMBOM(true);


    glPushMatrix();

    glTranslated(-2,0,0);

    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);


    glNormalPointer(GL_FLOAT,0,bing_1);
    glVertexPointer(3,GL_FLOAT,0,bing_1);

    glDrawArrays(GL_QUADS,0,480);

    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glPopMatrix();


    glPushMatrix();

    glTranslated(2,0,0);

    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);


    glNormalPointer(GL_FLOAT,0,bing_2);
    glVertexPointer(3,GL_FLOAT,0,bing_2);

    glDrawArrays(GL_QUADS,0,480);

    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glPopMatrix();

}

/**************************************************************************************/
void MyGLWidget::drawBOMBOM(bool form)
{
    if( (switcher%2) == 0)
    {
        for(int i=0;i<480;i+=3)
        {


            /*
            getCube(sphere_array[i],0);
            getCube(sphere_array[i+1],1);
            getCube(sphere_array[i+2],2);
            */


            //GLfloat vector[] = { cube[0]-sphere_array[i], cube[1]-sphere_array[i+1], cube[2]-sphere_array[i+2]};

            GLfloat vector[] = { cube_array[i]-sphere_array[i], cube_array[i+1]-sphere_array[i+1], cube_array[i+2]-sphere_array[i+2]};
            //Laenge des Vectors + time_old (t0) == ist der Zeitpunkt t1
            laenge = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]);


            if( ((round(bing_1[i] * 10) / 10)!= cube_array[i]) |
                ((round(bing_1[i+1] * 10) / 10)!= cube_array[i+1]) |
                ((round(bing_1[i+2] * 10) / 10)!= cube_array[i+2]))
            {
                GLfloat time = (time_counter)/(laenge); //-time_old

                bing_1[i] += time * (cube_array[i]-sphere_array[i]);
                bing_1[i+1] += time * (cube_array[i+1]-sphere_array[i+1]);
                bing_1[i+2] += time * (cube_array[i+2]-sphere_array[i+2]);


            }


            /***************************************************************************/
            GLfloat vector_2[] = {cube_array[i]-sphere_array[i], cube_array[i+1]-sphere_array[i+1], cube_array[i+2]-sphere_array[i+2]};

            laenge_2 = sqrt(vector_2[0]*vector_2[0] + vector_2[1]*vector_2[1] + vector_2[2]*vector_2[2]);

            if( ((round(bing_2[i] * 10) / 10) != sphere_array[i]) |
                ((round(bing_2[i+1] * 10) / 10) != sphere_array[i+1]) |
                ((round(bing_2[i+2] * 10) / 10) != sphere_array[i+2]))
            {

                GLfloat time = (time_counter)/(laenge_2);

                bing_2[i] += time * (sphere_array[i]-cube_array[i]);
                bing_2[i+1] += time * (sphere_array[i+1]-cube_array[i+1]);
                bing_2[i+2] += time * (sphere_array[i+2]-cube_array[i+2]);


            }
        }

    }
    else{


            for(int i=0;i<480;i+=3)
            {

                GLfloat vector[] = {tmp_array[i]-sphere_array[i], tmp_array[i+1]-sphere_array[i+1], tmp_array[i+2]-sphere_array[i+2]};

                laenge = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]);


                /*
                if( (round(bing_1[i]) != sphere_array[i]) |
                    (round(bing_1[i+1])!= sphere_array[i+1]) |
                    (round(bing_1[i+2]) != sphere_array[i+2]))*/
                if(time_old>0)
                {
                    GLfloat time = (time_counter)/(laenge); //-time_old

                    bing_1[i] = tmp_array[i] + time * (sphere_array[i]-tmp_array[i]);
                    bing_1[i+1] = tmp_array[i+1] + time * (sphere_array[i+1]-tmp_array[i+1]);
                    bing_1[i+2] = tmp_array[i+2] + time * (sphere_array[i+2]-tmp_array[i+2]);


                }

            }


    }

    time_counter+=0.00001;

    if(switcher%2!=0)
    {time_old -=0.001;}

}

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

    if(x<=0)
    {
        cube[i] = -1;
    }
    if(x>0)
    {
        cube[i] = 1;
    }


}

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

    std::cout << " X - Achse " << x_axis << std::endl;
}

/**************************************************************************************/

void MyGLWidget::setYRotation(int angle)
{

    if (angle != y_axis) {
        y_axis = angle;
        //emit yRotationChanged(angle);
        updateGL();
    }

    std::cout << " Y - Achse " << y_axis << std::endl;
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

void MyGLWidget::keyPressEvent( QKeyEvent* event )
{

    if(event->key() == Qt::Key_Space)
    {

        std::cout << " KEY PRESSED = " << std::endl;

        switcher++;
        time_old = time_counter;
        time_counter=0;

        if(switcher%2!=0)
        {
            for(int m=0; m < 480 ; m++)
            {
                tmp_array[m] = bing_1[m];
            }
        }

    }

}

void MyGLWidget::keyReleaseEvent(QKeyEvent *event) {

    event->ignore();
}
/**************************************************************************************/



