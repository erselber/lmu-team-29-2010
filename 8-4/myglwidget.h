#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include "QMouseEvent"




class MyGLWidget : public QGLWidget
{
    Q_OBJECT


public:
    MyGLWidget()
    {
    }





public slots:
        void setXRotation(int angle);
        void setYRotation(int angle);
        void setZRotation(int angle);

protected:



    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();


private:

    void draw_Cube();

    float x_axis,y_axis,z_axis;
    QPoint lastPos;

};

#endif // MYGLWIDGET_H

