#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include "QKeyEvent"
#include "QPoint"




class MyGLWidget : public QGLWidget
{
    Q_OBJECT


public:
    MyGLWidget()
    {
    }


protected:



    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void keyPressEvent( QKeyEvent* event );
    void keyReleaseEvent(QKeyEvent *event);

    void mousePressEvent(QMouseEvent *event);

private:
    void drawCube();
    GLdouble* picking(QPoint mousepos);
    void setCube(QMouseEvent *event);


};

#endif // MYGLWIDGET_H
