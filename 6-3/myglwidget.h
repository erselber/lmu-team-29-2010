#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>


class MyGLWidget : public QGLWidget
{
    Q_OBJECT


public:
    MyGLWidget()
    {
    }


public slots:
            void rotateX(int value);
            void rotateY(int value);
            void rotateZ(int value);

protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

private:
    float x_axis,y_axis,z_axis;
    QPoint lastPos;

};

#endif // MYGLWIDGET_H
