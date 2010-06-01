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


protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

};

#endif // MYGLWIDGET_H

