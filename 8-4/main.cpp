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

       QSlider *z_slider = new QSlider();
       QSlider *x_slider = new QSlider();

       z_slider->setRange(0,360);
       x_slider->setRange(0,360);

       z_slider->setSliderPosition(0);
       x_slider->setSliderPosition(0);

       MyGLWidget *win = new MyGLWidget();

       QHBoxLayout *layout = new QHBoxLayout;

       layout->addWidget(win,Qt::AlignLeft);

       layout->addWidget(z_slider,Qt::AlignRight);
       layout->addWidget(x_slider,Qt::AlignRight);



       connect(z_slider, SIGNAL(valueChanged(int)), win, SLOT(setZRotation(int)));
       connect(x_slider, SIGNAL(valueChanged(int)), win, SLOT(setXRotation(int)));

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








