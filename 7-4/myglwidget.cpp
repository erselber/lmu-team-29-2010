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


GLuint texture_1[4];
/**************************************************************************************/
/**************************************************************************************/


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


    x_axis = 0;
    y_axis = 0;
    z_axis = 0;

    //Licht



    /******************************************************/

    GLfloat LigthDiffuse_0[] = {.9,.9,.9,.9};
    GLfloat LigthAmbient_0[] = {.5,.5,.5};
    GLfloat LigthPosition_0[] = {0,1,2,1}; //Letztes 1 damit Punktlicktquelle


    //Licht aktivieren
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0,GL_AMBIENT,LigthAmbient_0);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,LigthDiffuse_0);
    glLightfv(GL_LIGHT0,GL_POSITION,LigthPosition_0);


    /******************************************************/



}

/**************************************************************************************/

void MyGLWidget::resizeGL(int w, int h){

    glViewport(0,0, w,h);



}

/**************************************************************************************/

void MyGLWidget::initTextures_Cube(){

    QImage buf, qtex;

    buf.load("../Box.png");

    if(buf.isNull())
    {
        qDebug("could not load image");
    }

    qtex = QGLWidget::convertToGLFormat(buf);

    glGenTextures(1,&texture_1[0]);
    glBindTexture(GL_TEXTURE_2D, texture_1[0]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3 , qtex.width(), qtex.height(),0,GL_RGBA, GL_UNSIGNED_BYTE, qtex.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

/**************************************************************************************/

void MyGLWidget::initTextures_Pyramide(){

    QImage buf, qtex;

    buf.load("../Pyramid.png");

    if(buf.isNull())
    {
        qDebug("could not load image");
    }

    qtex = QGLWidget::convertToGLFormat(buf);

    glGenTextures(1,&texture_1[0]);
    glBindTexture(GL_TEXTURE_2D, texture_1[0]);

    glTexImage2D(GL_TEXTURE_2D, 0, 3 , qtex.width(), qtex.height(),0,GL_RGBA, GL_UNSIGNED_BYTE, qtex.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}
/**************************************************************************************/

void MyGLWidget::paintGL(){

    //

    initTextures_Cube();


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


    /*****************************/
    // Pyramide + TEXTUR
    initTextures_Pyramide();

    glPushMatrix();

    glTranslated(0,0.5,0);
    draw_Pyramide();

    glPopMatrix();

    /*****************************/


    initTextures_Cube();
    // BOX 1
    glPushMatrix();
    glTranslated(-2,0,0);


    draw_Cube();
    glPopMatrix();

    /*****************************/
    // BOX 2
    glPushMatrix();
    glTranslated(2,0,0);

    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(1,1,1,.5);
    draw_Cube();

   // glEnable(GL_LIGHTING);
    //glDisable(GL_BLEND);

    glPopMatrix();
    /*****************************/

    /*****************************/
    // Ebene
    glPushMatrix();

    glColor4f(1,1,1,1);
    glTranslated(0,-0.5,0);

    glBegin(GL_QUADS);

    glNormal3f(0,1,0);
    glVertex3f(-3,0,3);
    glVertex3f(3,0,3);
    glVertex3f(3,0,-3);
    glVertex3f(-3,0,-3);

    glNormal3f(0,-1,0);
    glVertex3f(-3,0,3);
    glVertex3f(-3,0,-3);
    glVertex3f(3,0,-3);
    glVertex3f(3,0,3);



    glEnd();

    glPopMatrix();
    /*****************************/

}

/**************************************************************************************/
/**************************************************************************************/

void MyGLWidget::draw_Cube(){


    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);

            //vorne
            glNormal3f(normalen[0],normalen[1],normalen[2]);


            glTexCoord2f(0,0);
            glVertex3f(-0.5,-0.5,0.5);
            glTexCoord2f(1,0);
            glVertex3f(0.5,-0.5,0.5);
            glTexCoord2f(1,1);
            glVertex3f(0.5,0.5,0.5);
            glTexCoord2f(0,1);
            glVertex3f(-0.5,0.5,0.5);

            //hinten
            glNormal3f(normalen[3],normalen[4],normalen[5]);

            glTexCoord2f(0,0);
            glVertex3f(-0.5,-0.5,-0.5);
            glTexCoord2f(0,1);
            glVertex3f(-0.5,0.5,-0.5);
            glTexCoord2f(1,1);
            glVertex3f(0.5,0.5,-0.5);
            glTexCoord2f(1,0);
            glVertex3f(0.5,-0.5,-0.5);

            //rechts
            glNormal3f(normalen[6],normalen[7],normalen[8]);

            glTexCoord2f(0,0);
            glVertex3f(0.5,-0.5,0.5);
            glTexCoord2f(1,0);
            glVertex3f(0.5,-0.5,-0.5);
            glTexCoord2f(1,1);
            glVertex3f(0.5,0.5,-0.5);
            glTexCoord2f(0,1);
            glVertex3f(0.5,0.5,0.5);

            //links
            glNormal3f(normalen[9],normalen[10],normalen[11]);

            glTexCoord2f(0,0);
            glVertex3f(-0.5,-0.5,-0.5);
            glTexCoord2f(0,1);
            glVertex3f(-0.5,-0.5,0.5);
            glTexCoord2f(1,1);
            glVertex3f(-0.5,0.5,0.5);
            glTexCoord2f(1,0);
            glVertex3f(-0.5,0.5,-0.5);

            //oben
            glNormal3f(normalen[12],normalen[13],normalen[14]);

            glTexCoord2f(0,0);
            glVertex3f(-0.5,0.5,0.5);
            glTexCoord2f(1,0);
            glVertex3f(0.5,0.5,0.5);
            glTexCoord2f(1,1);
            glVertex3f(0.5,0.5,-0.5);
            glTexCoord2f(0,1);
            glVertex3f(-0.5,0.5,-0.5);

            //unten
            glNormal3f(normalen[15],normalen[16],normalen[17]);;

            glTexCoord2f(0,0);
            glVertex3f(0.5,-0.5,-0.5);
            glTexCoord2f(1,0);
            glVertex3f(0.5,-0.5,0.5);
            glTexCoord2f(1,1);
            glVertex3f(-0.5,-0.5,0.5);
            glTexCoord2f(0,1);
            glVertex3f(-0.5,-0.5,-0.5);

         glEnd();

}


/**************************************************************************************/

void MyGLWidget::draw_Pyramide(){


    glEnable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);

            // rechts

            glTexCoord2f(0,0);
            glVertex3f(1,-1,1);
            glTexCoord2f(1,0);
            glVertex3f(1,-1,-1);
            glTexCoord2f(0.5,1);
            glVertex3f(0,1,0);

            // vorne

            glTexCoord2f(0,0);
            glVertex3f(-1,-1,1);
            glTexCoord2f(1,0);
            glVertex3f(1,-1,1);
            glTexCoord2f(0.5,1);
            glVertex3f(0,1,0);

            // hinten

            glTexCoord2f(0,0);
            glVertex3f(1,-1,-1);
            glTexCoord2f(1,0);
            glVertex3f(-1,-1,-1);
            glTexCoord2f(0.5,1);
            glVertex3f(0,1,0);

            //links

            glTexCoord2f(0,0);
            glVertex3f(-1,-1,-1);
            glTexCoord2f(1,0);
            glVertex3f(-1,-1,1);
            glTexCoord2f(0.5,1);
            glVertex3f(0,1,0);




        glEnd();

        glBegin(GL_QUADS);

            //boden

            glVertex3f(-1,-1,1);
            glVertex3f(-1,-1,-1);
            glVertex3f(1,-1,-1);
            glVertex3f(1,-1,1);


        glEnd();

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
        //emit zRotationChanged(angle);
        updateGL();
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

