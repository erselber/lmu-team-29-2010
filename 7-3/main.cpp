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



       QSlider *dimmer = new QSlider();


       dimmer->setRange(0,50);


       dimmer->setSliderPosition(0);


       MyGLWidget *win = new MyGLWidget();

       QHBoxLayout *layout = new QHBoxLayout;

       layout->addWidget(win,Qt::AlignLeft);

       layout->addWidget(dimmer,Qt::AlignRight);


       connect(dimmer, SIGNAL(valueChanged(int)), win, SLOT(dimmen(int)));
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






