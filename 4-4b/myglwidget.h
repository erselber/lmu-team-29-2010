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
    }


protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void paint_cube();

    void mousePressEvent(QMouseEvent *e);

private:

    int y_axis;
};

#endif // MYGLWIDGET_H
