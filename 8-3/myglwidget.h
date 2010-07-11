#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include "QMouseEvent"
#include "QKeyEvent"




class MyGLWidget : public QGLWidget
{
    Q_OBJECT


public:
    MyGLWidget()
    {
    }


void drawBOMBOM(bool form);


public slots:
        void setXRotation(int angle);
        void setYRotation(int angle);
        void setZRotation(int angle);

protected:



    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void mouseMoveEvent(QMouseEvent *event);

    void keyPressEvent( QKeyEvent* event );
    void keyReleaseEvent(QKeyEvent *event);

private:

    void drawSphere(double r, int lats, int longs);
    void getCube(GLfloat x, int i);

    float x_axis,y_axis,z_axis;
    QPoint lastPos;

};

#endif // MYGLWIDGET_H

