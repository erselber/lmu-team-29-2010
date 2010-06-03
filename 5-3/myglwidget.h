#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>


class MyGLWidget : public QGLWidget
{
    Q_OBJECT


public:
    MyGLWidget()
    {
        x_axis = 0;
        y_axis = 0;
        z_axis = 0;
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
    void initializeSCENE();

    int x_axis,y_axis,z_axis;

};

#endif // MYGLWIDGET_H

