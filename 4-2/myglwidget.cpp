#define GL_GLEXT_PROTOTYPES

#include "myglwidget.h"
#include "glext.h"
#include <iostream>


/****   Vertices Array  ****/

// Wuerfel / Cube (vertices1)
GLfloat vertices1[] = {
                        -1,-1,1, //vorne
                         1,-1,1,
                         1,1,1,
                        -1,1,1,
                        1,-1,1,  //rechts
                        1,-1,-1,
                        1,1,-1,
                        1,1,1,
                        -1,1,1,  //oben
                         1,1,1,
                         1,1,-1,
                        -1,1,-1,
                        -1,-1,-1, //links
                        -1,-1,1,
                        -1,1,1,
                         -1,1,-1,
                         1,-1,-1, //unten
                          1,-1,1,
                         -1,-1,1,
                         -1,-1,-1,
                         -1,-1,-1, //hinten
                         -1,1,-1,
                         1,1,-1,
                          1,-1,-1
 };

//Pyramide (vertices2) + Boden (vertices3)
GLfloat vertices2[] = {
                        1,-1,1, //eins
                        1,-1,-1,
                        0,1,0,
                       -1,-1,1, //zwei
                        1,-1,1,
                        0,1,0,
                        1,-1,-1, //drei
                       -1,-1,-1,
                        0,1,0,
                       -1,-1,-1, //vier
                       -1,-1,1,
                        0,1,0
                    };

GLfloat vertices3[] = {
                        -1,-1,1, //Boden
                        -1,-1,-1,
                        1,-1,-1,
                        1,-1,1
};



/**************************************************************************************/

extern "C" {
PFNGLGENBUFFERSPROC m_glGenBuffers = NULL;
PFNGLBINDBUFFERPROC m_glBindBuffer = NULL;
PFNGLBUFFERDATAPROC m_glBufferData = NULL;
PFNGLDELETEBUFFERSPROC m_glDeleteBuffers = NULL;}


void MyGLWidget::initializeGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);



    m_glGenBuffers = (PFNGLGENBUFFERSPROC)this->context()->getProcAddress("glGenBuffers");
    m_glBindBuffer = (PFNGLBINDBUFFERPROC)this->context()->getProcAddress("glBindBuffer");
    m_glBufferData = (PFNGLBUFFERDATAPROC)this->context()->getProcAddress("glBufferData");
    m_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)this->context()->getProcAddress("glDeleteBuffers");

    if (m_glGenBuffers != NULL && m_glBindBuffer != NULL && m_glBufferData != NULL && m_glDeleteBuffers != NULL)
    { std::cout << "Vertex Buffer Objects available :)" << std::endl;}
    else {
        std::cout << "Vertex Buffer Objects not available :(" << std::endl;
    }


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

    glTranslated(0,0,-21);

    paint_one();
    paint_two();
    paint_three();
    paint_four();

}

/**************************************************************************************/
            /****   Vertex Buffer Object    ****/

void MyGLWidget::paint_four()
{

    /********** Wuerfel  *********/
    glPushMatrix();
    glTranslated(-2,-3,0);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);


     GLuint vboID;

     m_glGenBuffers(1,&vboID);
     m_glBindBuffer(GL_ARRAY_BUFFER_ARB,vboID);
     m_glBufferData(GL_ARRAY_BUFFER_ARB,sizeof(vertices1),vertices1,GL_STATIC_DRAW_ARB);

     glEnableClientState(GL_VERTEX_ARRAY);
     glVertexPointer(3,GL_FLOAT,0,0);

     glDrawArrays(GL_QUADS,0,24);

     glDisableClientState(GL_VERTEX_ARRAY);
     m_glBindBuffer(GL_ARRAY_BUFFER_ARB,0);
     m_glDeleteBuffers(1,&vboID);


     glPopMatrix();
    /********** Pyramide  *********/

     glPushMatrix();

    glTranslated(2,-3,0);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);


    GLuint vboID_2,vboID_3;

    //Seiten 1,2,3,4
    m_glGenBuffers(1,&vboID_2);
    m_glBindBuffer(GL_ARRAY_BUFFER_ARB,vboID_2);
    m_glBufferData(GL_ARRAY_BUFFER_ARB,sizeof(vertices2),vertices2,GL_STATIC_DRAW_ARB);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,0);

    glColor3f(1,0,0);
    glDrawArrays(GL_TRIANGLES,0,12);

    glDisableClientState(GL_VERTEX_ARRAY);

    //Loeschen Seite 1,2,3,4
    m_glBindBuffer(GL_ARRAY_BUFFER_ARB,0);
    m_glDeleteBuffers(1,&vboID_2);


    //Boden
    m_glGenBuffers(1,&vboID_3);
    m_glBindBuffer(GL_ARRAY_BUFFER_ARB,vboID_3);
    m_glBufferData(GL_ARRAY_BUFFER_ARB,sizeof(vertices3),vertices3,GL_STATIC_DRAW_ARB);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,0);

    glColor3f(0,0,1);
    glDrawArrays(GL_QUADS,0,4);

    glDisableClientState(GL_VERTEX_ARRAY);

    //Loeschen Boden
    m_glBindBuffer(GL_ARRAY_BUFFER_ARB,0);
    m_glDeleteBuffers(1,&vboID_3);

    glPopMatrix();


}


/**************************************************************************************/
            /****   Vertex Arrays   ****/

void MyGLWidget::paint_three()
{

    /********** Wuerfel  *********/
    glPushMatrix();
    glTranslated(-2,0,0);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);


     glEnableClientState(GL_VERTEX_ARRAY);
     glVertexPointer(3,GL_FLOAT,0,vertices1);

     /************************/

       //Farbe fuer jede Seite, geht nicht ?!?! unter Windoof
     /*
     glColor3f(1,0,0);
     glDrawArrays(GL_QUADS,0,4);
     glColor3f(0,1,0);
     glDrawArrays(GL_QUADS,4,8);
     glColor3f(0,0,1);
     glDrawArrays(GL_QUADS,8,12);
     glColor3f(0,1,1);
     glDrawArrays(GL_QUADS,12,16);
     glColor3f(1,0,1);
     glDrawArrays(GL_QUADS,16,20);
     glColor3f(1,1,0);
     glDrawArrays(GL_QUADS,20,24);
    ***********************/

     glDrawArrays(GL_QUADS,0,24);

     glDisableClientState(GL_VERTEX_ARRAY);

     glPopMatrix();

    /********** Pyramide  *********/

     glPushMatrix();

    glTranslated(2,0,0);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);


    //Dreiecke 1,2,3,4
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertices2);

    glColor3f(0,0,1);
    glDrawArrays(GL_TRIANGLES,0,12);
    glDisableClientState(GL_VERTEX_ARRAY);

    //Boden
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertices3);

    glColor3f(1,0,0);
    glDrawArrays(GL_QUADS,0,4);
    glDisableClientState(GL_VERTEX_ARRAY);

    glPopMatrix();


}

/**************************************************************************************/
            /****   Display Lists   ****/

void MyGLWidget::paint_two()
{

    /********** Wuerfel  *********/
    glPushMatrix();
    glTranslated(-2,3,0);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);


    GLuint index1 = glGenLists(1);
    glNewList(index1,GL_COMPILE);

        glBegin(GL_QUADS);

            //vorne (rot)

            glColor3f(1,0,0);
            glVertex3f(-1,-1,1);
            glVertex3f(1,-1,1);
            glVertex3f(1,1,1);
            glVertex3f(-1,1,1);

            //hinten (gruen)

            glColor3f(0,1,0);
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,1,-1);
            glVertex3f(1,1,-1);
            glVertex3f(1,-1,-1);

            //rechts (blau)

            glColor3f(0,0,1);
            glVertex3f(1,-1,1);
            glVertex3f(1,-1,-1);
            glVertex3f(1,1,-1);
            glVertex3f(1,1,1);

            //links (gelb)

            glColor3f(1,1,0);
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,-1,1);
            glVertex3f(-1,1,1);
            glVertex3f(-1,1,-1);

            //oben (hell blau)

            glColor3f(0,1,1);
            glVertex3f(-1,1,1);
            glVertex3f(1,1,1);
            glVertex3f(1,1,-1);
            glVertex3f(-1,1,-1);

            //unten (rosa)

            glColor3f(1,0,1);
            glVertex3f(1,-1,-1);
            glVertex3f(1,-1,1);
            glVertex3f(-1,-1,1);
            glVertex3f(-1,-1,-1);

         glEnd();
     glEndList();
     glCallList(index1);
     glDeleteLists(index1,1);

     glPopMatrix();
    /********** Pyramide  *********/

     glPushMatrix();

    glTranslated(2,3,0);

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);

    GLuint index2 = glGenLists(1);
    glNewList(index2,GL_COMPILE);

        glBegin(GL_TRIANGLES);

            //vorne  (lila)
            glColor3f(1,0,1);
            glVertex3f(1,-1,1);
            glVertex3f(1,-1,-1);
            glVertex3f(0,1,0);

            //rechts  (gruen)
            glColor3f(0,1,0);
            glVertex3f(-1,-1,1);
            glVertex3f(1,-1,1);
            glVertex3f(0,1,0);

            //hinten (blau)
            glColor3f(0,0,1);
            glVertex3f(1,-1,-1);
            glVertex3f(-1,-1,-1);
            glVertex3f(0,1,0);

            //links  (rot)
            glColor3f(1,0,0);
            glVertex3f(-1,-1,-1);
            glVertex3f(-1,-1,1);
            glVertex3f(0,1,0);


        glEnd();

        glBegin(GL_QUADS);

            //boden
            glColor3f(1,1,0);
            glVertex3f(-1,-1,1);
            glVertex3f(-1,-1,-1);
            glVertex3f(1,-1,-1);
            glVertex3f(1,-1,1);


        glEnd();

    glEndList();
    glCallList(index2);
    glDeleteLists(index2,1);

    glPopMatrix();

}
/**************************************************************************************/
                   /****   Immediate Mode ****/

void MyGLWidget::paint_one()
{

    /********** Wuerfel  *********/
    glPushMatrix();
    glTranslated(-2,6,0);


    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);

    glBegin(GL_QUADS);

        //vorne (rot)

        glColor3f(1,0,0);
        glVertex3f(-1,-1,1);
        glVertex3f(1,-1,1);
        glVertex3f(1,1,1);
        glVertex3f(-1,1,1);

        //hinten (gruen)

        glColor3f(0,1,0);
        glVertex3f(-1,-1,-1);
        glVertex3f(-1,1,-1);
        glVertex3f(1,1,-1);
        glVertex3f(1,-1,-1);

        //rechts (blau)

        glColor3f(0,0,1);
        glVertex3f(1,-1,1);
        glVertex3f(1,-1,-1);
        glVertex3f(1,1,-1);
        glVertex3f(1,1,1);

        //links (gelb)

        glColor3f(1,1,0);
        glVertex3f(-1,-1,-1);
        glVertex3f(-1,-1,1);
        glVertex3f(-1,1,1);
        glVertex3f(-1,1,-1);

        //oben (hell blau)

        glColor3f(0,1,1);
        glVertex3f(-1,1,1);
        glVertex3f(1,1,1);
        glVertex3f(1,1,-1);
        glVertex3f(-1,1,-1);

        //unten (rosa)

        glColor3f(1,0,1);
        glVertex3f(1,-1,-1);
        glVertex3f(1,-1,1);
        glVertex3f(-1,-1,1);
        glVertex3f(-1,-1,-1);

     glEnd();

    glPopMatrix();

    /********** Pyramide  *********/

    glPushMatrix();

    glTranslated(2,6,0);


    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);


    glBegin(GL_TRIANGLES);

        //vorne  (lila)
        glColor3f(1,0,1);
        glVertex3f(1,-1,1);
        glVertex3f(1,-1,-1);
        glVertex3f(0,1,0);

        //rechts  (gruen)
        glColor3f(0,1,0);
        glVertex3f(-1,-1,1);
        glVertex3f(1,-1,1);
        glVertex3f(0,1,0);

        //hinten (blau)
        glColor3f(0,0,1);
        glVertex3f(1,-1,-1);
        glVertex3f(-1,-1,-1);
        glVertex3f(0,1,0);

        //links  (rot)
        glColor3f(1,0,0);
        glVertex3f(-1,-1,-1);
        glVertex3f(-1,-1,1);
        glVertex3f(0,1,0);




    glEnd();

    glBegin(GL_QUADS);

        //boden
        glColor3f(1,1,0);
        glVertex3f(-1,-1,1);
        glVertex3f(-1,-1,-1);
        glVertex3f(1,-1,-1);
        glVertex3f(1,-1,1);


    glEnd();

    glPopMatrix();

}
/**************************************************************************************/

void MyGLWidget::rotateX(int value){


        x_axis = value;
        updateGL();;

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

