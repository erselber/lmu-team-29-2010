#define GL_GLEXT_PROTOTYPES
#include <QApplication>
#include <QGLWidget>
//#define PI 3.14159

#include "myglwidget.h"
#include "QMouseEvent"

#include <lib3ds/file.h>
#include <lib3ds/mesh.h>

#include <iostream>
#include <string>
#include <cstring>
#include <cassert>


/**************************************************************************************/
/**************           CLASS CMODEL3DS                    **************************/
/**************************************************************************************/

// Our 3DS model class
class CModel3DS
{
        public:
                CModel3DS(std::string filename);
                virtual void Draw() const;
                virtual void CreateVBO();
                virtual ~CModel3DS();
        protected:
                void GetFaces();
                unsigned int m_TotalFaces;
                Lib3dsFile * m_model;
                GLuint m_VertexVBO, m_NormalVBO;
};

/**************************************************************************************/

// Load 3DS model
CModel3DS::CModel3DS(std::string filename)
{
        m_TotalFaces = 0;

        m_model = lib3ds_file_load(filename.c_str());
        // If loading the model failed, we throw an exception
        if(!m_model)
        {
                throw strcat("Unable to load ", filename.c_str());
        }
}

/**************************************************************************************/

// Destructor
CModel3DS::~CModel3DS()
{
        glDeleteBuffers(1, &m_VertexVBO);
        glDeleteBuffers(1, &m_NormalVBO);

        if(m_model != NULL)
        {
                lib3ds_file_free(m_model);
        }
}

/**************************************************************************************/

// Copy vertices and normals to the memory of the GPU
void CModel3DS::CreateVBO()
{
        assert(m_model != NULL);

        // Calculate the number of faces we have in total
        GetFaces();

        // Allocate memory for our vertices and normals
        Lib3dsVector * vertices = new Lib3dsVector[m_TotalFaces * 3];
        Lib3dsVector * normals = new Lib3dsVector[m_TotalFaces * 3];

        Lib3dsMesh * mesh;
        unsigned int FinishedFaces = 0;
        // Loop through all the meshes
        for(mesh = m_model->meshes;mesh != NULL;mesh = mesh->next)
        {
                lib3ds_mesh_calculate_normals(mesh, &normals[FinishedFaces*3]);
                // Loop through every face
                for(unsigned int cur_face = 0; cur_face < mesh->faces;cur_face++)
                {
                        Lib3dsFace * face = &mesh->faceL[cur_face];
                        for(unsigned int i = 0;i < 3;i++)
                        {
                                memcpy(&vertices[FinishedFaces*3 + i], mesh->pointL[face->points[i]].pos, sizeof(Lib3dsVector));
                        }
                        FinishedFaces++;
                }
        }

        // Generate a Vertex Buffer Object and store it with our vertices
        glGenBuffers(1, &m_VertexVBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Lib3dsVector) * 3 * m_TotalFaces, vertices, GL_STATIC_DRAW);

        // Generate another Vertex Buffer Object and store the normals in it
        glGenBuffers(1, &m_NormalVBO);
        glBindBuffer(GL_ARRAY_BUFFER, m_NormalVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Lib3dsVector) * 3 * m_TotalFaces, normals, GL_STATIC_DRAW);

        // Clean up our allocated memory
        delete vertices;
        delete normals;

        // We no longer need lib3ds
        lib3ds_file_free(m_model);
        m_model = NULL;
}

/**************************************************************************************/

// Count the total number of faces this model has
void CModel3DS::GetFaces()
{
        assert(m_model != NULL);

        m_TotalFaces = 0;
        Lib3dsMesh * mesh;
        // Loop through every mesh
        for(mesh = m_model->meshes;mesh != NULL;mesh = mesh->next)
        {
                // Add the number of faces this mesh has to the total faces
                m_TotalFaces += mesh->faces;
        }
}

/**************************************************************************************/

// Render the model using Vertex Buffer Objects
void CModel3DS::Draw() const
{
        assert(m_TotalFaces != 0);

        // Enable vertex and normal arrays
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);

        // Bind the vbo with the normals
        glBindBuffer(GL_ARRAY_BUFFER, m_NormalVBO);
        // The pointer for the normals is NULL which means that OpenGL will use the currently bound vbo
        glNormalPointer(GL_FLOAT, 0, NULL);

        glBindBuffer(GL_ARRAY_BUFFER, m_VertexVBO);
        glVertexPointer(3, GL_FLOAT, 0, NULL);

        // Render the triangles
        glDrawArrays(GL_TRIANGLES, 0, m_TotalFaces * 3);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
}

/**************************************************************************************/



/**************************************************************************************/
/******************      CLASS   MYGLWIDGET             *******************************/
/**************************************************************************************/

/*************************/
  /** VARIABLEN  **/
/*************************/
CModel3DS *object;


/**************************************************************************************/


void MyGLWidget::initializeGL(){

    try
    {
            object = new CModel3DS("monkey.3ds");
    }
    catch(std::string error_str)
    {

            exit(1);
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // Enable lighting and set the position of the light
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    GLfloat pos[] = { 0.0, 4.0, 4.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

    // Generate Vertex Buffer Objects
    object->CreateVBO();

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

    glRotated(x_axis,1,0,0);
    glRotated(y_axis,0,1,0);
    glRotated(z_axis,0,0,1);

    object->Draw();



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

