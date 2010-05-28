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
        rotation = false;
    }


protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void paint_cube();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void rotate_Y_axis(QMouseEvent *event);

private:

    int y_axis;
    QPoint lastPos;
    bool rotation;
};

#endif // MYGLWIDGET_H
