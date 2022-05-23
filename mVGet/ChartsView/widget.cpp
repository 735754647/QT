#include "widget.h"
#include "QVBoxLayout"
widget::widget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(640, 480);

    view =new ChartsView(300,this);
    view->setMinimumSize(640, 480);

    view->addLineSeries(2,150,255);

    TestTimer = new QTimer(this);
    connect(TestTimer, SIGNAL(timeout()), this, SLOT(TestOnTimeOut()));
    TestTimer->start(1000);

    view->initMSecBase(300);
}
void widget::TestOnTimeOut()
{

    view->addLineSeries(0,qrand()%200);

}

void widget::resizeEvent(QResizeEvent *event)
{
    view->resize(event->size());
}
