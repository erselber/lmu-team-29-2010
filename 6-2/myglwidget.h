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

void mouseMoveEvent(QMouseEvent *event);


public slots:

            void setXRotation(int angle);
            void setYRotation(int angle);
            void setZRotation(int angle);

        signals:
            void xRotationChanged(int angle);
            void yRotationChanged(int angle);
            void zRotationChanged(int angle);

protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void swap(int i);



private:
    float x_axis,y_axis,z_axis;
    QPoint lastPos;

};

#endif // MYGLWIDGET_H

