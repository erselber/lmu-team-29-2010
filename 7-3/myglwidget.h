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

    void draw_Cube();

public slots:

            void dimmen(int value);




protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

private:
    int dimm_grad;

};

#endif // MYGLWIDGET_H

