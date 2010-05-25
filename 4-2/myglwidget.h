#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>


class MyGLWidget : public QGLWidget
{
    Q_OBJECT


public:
    MyGLWidget(int timerInterval=0, QWidget *parent=0, char *name=0)
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

    void paint_one();
    void paint_two();
    void paint_three();
    void paint_four();

private:
    double x_axis;
    double y_axis;
    double z_axis;


};

#endif // MYGLWIDGET_H
