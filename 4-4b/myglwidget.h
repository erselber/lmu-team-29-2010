#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>


class MyGLWidget : public QGLWidget
{
    Q_OBJECT


public:
    MyGLWidget()
    {

        y_axis = 0;
        z_axis = -10;
        winkel = 45;
        perspektive = true;
    }


protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void paint_cube();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void wheelEvent(QWheelEvent *event);


private:

    float y_axis;
    float z_axis;
    float winkel;
    bool perspektive;
    QPoint lastPos;
};

#endif // MYGLWIDGET_H
