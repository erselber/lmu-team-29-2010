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






       MyGLWidget *win = new MyGLWidget();

       QHBoxLayout *layout = new QHBoxLayout;

       layout->addWidget(win,Qt::AlignLeft);

       win->grabKeyboard();
       win->grabMouse();
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








