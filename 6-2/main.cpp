#include <QSlider>
#include <QHBoxLayout>
#include "myglwidget.h"
#include <QApplication>



class MyWidget : public QWidget
{
    public:
        MyWidget(QWidget *parent=0);

};

MyWidget::MyWidget(QWidget *parent):QWidget(parent)
{


       QSlider *x_slider = new QSlider();
       QSlider *y_slider = new QSlider();
       QSlider *z_slider = new QSlider();


       x_slider->setRange(0,360);
       y_slider->setRange(0,360);
       z_slider->setRange(0,360);

       x_slider->setSliderPosition(0);
       y_slider->setSliderPosition(0);
       z_slider->setSliderPosition(0);

       MyGLWidget *win = new MyGLWidget();

       QHBoxLayout *layout = new QHBoxLayout;

       layout->addWidget(win,Qt::AlignLeft);

       layout->addWidget(x_slider,Qt::AlignRight);
       layout->addWidget(y_slider,Qt::AlignRight);
       layout->addWidget(z_slider,Qt::AlignRight);


       connect(x_slider, SIGNAL(valueChanged(int)), win, SLOT(setXRotation(int)));
       connect(win, SIGNAL(xRotationChanged(int)), x_slider, SLOT(setValue(int)));
       connect(y_slider, SIGNAL(valueChanged(int)), win, SLOT(setYRotation(int)));
       connect(win, SIGNAL(yRotationChanged(int)), y_slider, SLOT(setValue(int)));
       connect(z_slider, SIGNAL(valueChanged(int)), win, SLOT(setZRotation(int)));
       connect(win, SIGNAL(zRotationChanged(int)), z_slider, SLOT(setValue(int)));


       setLayout(layout);
}


/***************************      MAIN      *********************************************/

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    MyWidget widget;
    widget.resize(800,800);
    widget.show();

    return app.exec();
}




