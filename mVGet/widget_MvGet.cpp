#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

void Widget::initmvGet()
{


    mvGetTimer = new QTimer(this);
    connect(mvGetTimer, SIGNAL(timeout()), this, SLOT(onMvGetTimeOut()));


    mvGetTimer->start(100);

}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    charts->setShowLine(index);
    if(index==3)
         ui->value->setText("--");
}


void Widget::onMvGetTimeOut()
{
    qDebug()<<ui->comboBox->currentIndex();
    for(int i=0;i<3;i++)     //显示全部曲线
    {
         int data = qrand()%400-200;
         charts->addLineSeries(i,data);
         if(ui->comboBox->currentIndex()==i)
             ui->value->setText(QString::asprintf("%dmV",data));
    }

}
