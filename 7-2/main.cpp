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



       QSlider *y_slider = new QSlider();


       y_slider->setRange(-90,90);


       y_slider->setSliderPosition(0);


       MyGLWidget *win = new MyGLWidget();

       QHBoxLayout *layout = new QHBoxLayout;

       layout->addWidget(win,Qt::AlignLeft);

       layout->addWidget(y_slider,Qt::AlignRight);


       connect(y_slider, SIGNAL(valueChanged(int)), win, SLOT(setYRotation(int)));
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





