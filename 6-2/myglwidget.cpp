#define PI 3.14159

#include "myglwidget.h"
#include "QMouseEvent"
#include "CTransform.h"
#include "math.h"
#include <iostream>



/*************************/
  /** VARIABLEN  **/
/*************************/

GLfloat winkel = 0;

GLfloat loftShape[] = {
0.5, 0, 0,
0.25, 0, -0.5,
-0.25, 0, -0.5,
-0.5, 0, 0,
-0.25, 0, 0.5,
0.25, 0, 0.5
};

GLfloat O[] = {
0.5, 0, 0,
0.25, 0, -0.5,
-0.25, 0, -0.5,
-0.5, 0, 0,
-0.25, 0, 0.5,
0.25, 0, 0.5
};
GLfloat N[] = {
0.5, 0, 0,
0.25, 0, -0.5,
-0.25, 0, -0.5,
-0.5, 0, 0,
-0.25, 0, 0.5,
0.25, 0, 0.5
};

GLfloat loftPath[] = {
0, 0, 0,
0, 2, 0,
-2, 6, 0,
-2, 8, 0,
2, 8, 0
};

/*************/

CTransform *ct;

/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

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

    glTranslated(0,-2,-10);
    glScaled(0.5,0.5,0.5);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);


    // PFAD "den man nicht mehr sieht"
    glBegin(GL_LINE_STRIP);

        for(int i=0;i<15;)
        {
            glColor3f(0,0,1);
            glVertex3d(loftPath[i],loftPath[i+1],loftPath[i+2]);
            i+=3;
        }

    glEnd();


    // Deckel Unten
    glBegin(GL_TRIANGLE_FAN);

         glColor3f(0,1,0);
         for(int i=15; i >=0; i-=3)
         {
            glVertex3f(loftShape[i],loftShape[i+1],loftShape[i+2]);
         }
         glVertex3f(loftShape[15],loftShape[16],loftShape[17]);
    glEnd();

    // Rohr
    winkel = 0;
    glBegin(GL_TRIANGLE_STRIP);

        glColor3f(1,0,0);


        for(int i=0;i<15;i+=3)
        {
            swap(i);

            for(int j=17;j>=0;j-=3)
            {
                    glVertex3d(O[j-2],O[j-1],O[j]);
                    glVertex3d(N[j-2],N[j-1],N[j]);
            }

            glVertex3d(O[15],O[16],O[17]);
            glVertex3d(N[15],N[16],N[17]);
        }

    glEnd();

    // Deckel Oben
    glBegin(GL_TRIANGLE_FAN);

         glColor3f(0,1,0);
         for(int i=0; i <18; i+=3)
         {
            glVertex3f(N[i],N[i+1],N[i+2]);
         }
         glVertex3f(N[0],N[1],N[2]);
    glEnd();



}

/*************************************************************************************/

void MyGLWidget::swap(int i)
{
    ct = new CTransform();

    GLfloat v_old[3];
    GLfloat v_new[3];
    GLfloat zaehler,nenner = 0;

    /***************************************/

    switch(i)
    {

    /**** Anfang ****/
    case 0:

            for(int j=0;j<18;j++)
            {
                N[j] = loftShape[j];
                O[j] = loftShape[j];
            }


            v_old[0] = 0;
            v_old[1] = 1;
            v_old[2] = 0;

            v_new[0] = loftPath[6] - loftPath[3];
            v_new[1] = loftPath[7] - loftPath[4];
            v_new[2] = loftPath[8] - loftPath[5];

            nenner = sqrt(v_old[0]*v_old[0] + v_old[1]*v_old[1] + v_old[2]*v_old[2])
                     * sqrt(v_new[0]*v_new[0] + v_new[1]*v_new[1] + v_new[2]*v_new[2]);

            zaehler = v_old[0]*v_new[0] + v_old[1]*v_new[1] + v_old[2]*v_new[2];

            winkel += acos(zaehler/nenner)/2*180/PI;
            std::cout << "-------------------------------> WINKEL " << winkel << std::endl;

            ct = new CTransform();

            ct->rotate(Z,winkel);
            ct->translate(X,loftPath[3]);
            ct->translate(Y,loftPath[4]);
            ct->translate(Z,loftPath[5]);


            for(int j=0;j<18;j+=3)
            {
                ct->transform(&N[j],&N[j+1],&N[j+2]);
            }

            ct->print();

            v_old[0] = v_new[0];
            v_old[1] = v_new[1];
            v_old[2] = v_new[2];

            break;

    /**** ENDE ****/
    case 12:

            /*
            v_new[0] = 0 - loftPath[i];
            v_new[1] = 0 - loftPath[i+1];
            v_new[2] = 0 - loftPath[i+2];
            */

            v_new[0] = 0;
            v_new[1] = 1;
            v_new[0] = 0;

            nenner = sqrt(v_old[0]*v_old[0] + v_old[1]*v_old[1] + v_old[2]*v_old[2])
                     * sqrt(v_new[0]*v_new[0] + v_new[1]*v_new[1] + v_new[2]*v_new[2]);

            zaehler = v_old[0]*v_new[0] + v_old[1]*v_new[1] + v_old[2]*v_new[2];


            if((v_old[0]*v_new[1] - v_old[1]*v_new[0])>0)
            {    winkel += acos(zaehler/nenner)/2 * 180/PI;}
            else { winkel += (-1)*acos(zaehler/nenner)/2*180/PI;}

            std::cout << "-------------------------------> WINKEL CASE 12 " << winkel << std::endl;

            winkel -= 15;
            ct = new CTransform();

            ct->rotate(Z,winkel);
            ct->translate(X,loftPath[12]);
            ct->translate(Y,loftPath[13]);
            ct->translate(Z,loftPath[14]);


            for(int j=0;j<18;j++)
            {
                O[j] = N[j];
                N[j] = loftShape[j];

            }

            for(int j=0;j<18;j+=3)
            {
                ct->transform(&N[j],&N[j+1],&N[j+2]);
            }

            ct->print();

            break;

    /**** MITTE ****/
    default:

            v_new[0] = loftPath[i+3] - loftPath[i];
            v_new[1] = loftPath[i+4] - loftPath[i+1];
            v_new[2] = loftPath[i+5] - loftPath[i+2];

            nenner = sqrt(v_old[0]*v_old[0] + v_old[1]*v_old[1] + v_old[2]*v_old[2])
                     * sqrt(v_new[0]*v_new[0] + v_new[1]*v_new[1] + v_new[2]*v_new[2]);

            zaehler = v_old[0]*v_new[0] + v_old[1]*v_new[1] + v_old[2]*v_new[2];

            if((v_old[0]*v_new[1] - v_old[1]*v_new[0])>0)
            {    winkel += acos(zaehler/nenner)/2 * 180/PI;}
            else { winkel += (-1)*acos(zaehler/nenner)/2 *180/PI;
                 }

            std::cout<< "WINEKL ----------> " << winkel << "CASE : "<< i << std::endl;
            //Winkel


            ct = new CTransform();


            ct->rotate(Z,winkel);
            ct->translate(X,loftPath[i]);
            ct->translate(Y,loftPath[i+1]);
            ct->translate(Z,loftPath[i+2]);


            for(int j=0;j<18;j++)
            {
                O[j] = N[j];
                N[j] = loftShape[j];

            }

            for(int j=0;j<18;j+=3)
            {
                ct->transform(&N[j],&N[j+1],&N[j+2]);
            }

            ct->print();


    }


}

/**************************************************************************************/
               /**  SLOTS SLOTS SLOTS  **/
/**************************************************************************************/

void MyGLWidget::rotateX(int value){

        x_axis =  value;
        updateGL();
}

/**************************************************************************************/

void MyGLWidget::rotateY(int value){

        y_axis =  value;
        updateGL();
}

/**************************************************************************************/

void MyGLWidget::rotateZ(int value){
        z_axis = value;
        updateGL();

}

/**************************************************************************************/
void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();


    if (event->buttons() & Qt::LeftButton) {
        rotateX(x_axis + 8 * dy);
        rotateY(y_axis + 8 * dx);
    }
    lastPos = event->pos();
}
