
#include <QtGUI>
#include "MyGLWidget.h"
#include <QLCDNumber>
#include <iostream>


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

    MyGLWidget *win = new MyGLWidget();

    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(win,Qt::AlignLeft);

    layout->addWidget(x_slider,Qt::AlignRight);
    layout->addWidget(y_slider,Qt::AlignRight);
    layout->addWidget(z_slider,Qt::AlignRight);



    connect(x_slider,SIGNAL(valueChanged(int)),win,SLOT(rotateX(int)));
    connect(y_slider,SIGNAL(valueChanged(int)),win,SLOT(rotateY(int)));
    connect(z_slider,SIGNAL(valueChanged(int)),win,SLOT(rotateZ(int)));

    setLayout(layout);
}


/***************************      MAIN      *********************************************/

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    MyWidget widget;
    widget.resize(700,800);
    widget.show();

    return app.exec();
}


