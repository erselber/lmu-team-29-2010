#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include "QKeyEvent"




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

private:

    void drawSphere(double r, int lats, int longs);
    void getCube(GLfloat x, int i);


};

#endif // MYGLWIDGET_H
