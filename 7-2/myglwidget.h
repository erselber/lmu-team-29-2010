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

            void setYRotation(int angle);




protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

private:
    int y_axis;

};

#endif // MYGLWIDGET_H

