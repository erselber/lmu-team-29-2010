#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>


class MyGLWidget : public QGLWidget
{
    Q_OBJECT


public:
    MyGLWidget()
    {
        x_grad = 0;
        y_grad = 0;
        z_grad = 0;
    }

public slots:
    void rotateX(int value);
    void rotateY(int value);
    void rotateZ(int value);

    void setBlue(void);
    void setRed(void);

protected:

    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

    void contextMenuEvent(QContextMenuEvent *event);


private:
    void initializeSCENE();

    int x_grad,y_grad,z_grad;

};

#endif // MYGLWIDGET_H

