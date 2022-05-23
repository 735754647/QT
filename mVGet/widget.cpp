#pragma execution_character_set("utf-8")
#include "widget.h"
#include <QCloseEvent>
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    this->setWindowTitle("电压显示");


    initmvGet();

    charts =new ChartsView(300,ui->Chart);

    charts->resize(ui->Chart->size());

    charts->setShowLine(0);

    initTrayIcon();

}



void Widget::initTrayIcon()
{



    if (!QSystemTrayIcon::isSystemTrayAvailable())      //判断系统是否支持系统托盘图标
    {
       return;
    }

       myTrayIcon = new QSystemTrayIcon(this);

       myTrayIcon->setIcon(QIcon(":icon"));   //设置图标图片
       setWindowIcon(QIcon(":icon"));  //把图片设置到窗口上

       myTrayIcon->setToolTip("电压显示");    //托盘时，鼠标放上去的提示信息

       myTrayIcon->showMessage("电压显示","已缩放至托盘",QSystemTrayIcon::Information,10000);
       //显示消息

       myTrayIcon->show();

       this->connect(myTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));


       quitAction = new QAction("退出(&Q)",this);
       this->connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));
       myMenu = new QMenu((QWidget*)QApplication::desktop());
       myMenu->addAction(quitAction);
       myTrayIcon->setContextMenu(myMenu);     //设置托盘上下文菜单
}

void Widget::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:

    case QSystemTrayIcon::DoubleClick:
        showNormal();
        break;
    case QSystemTrayIcon::MiddleClick:
        myTrayIcon->showMessage("电压显示","已缩放至托盘",QSystemTrayIcon::Information,10000);

        break;

    default:
        break;
    }
}

void Widget::closeEvent(QCloseEvent *event)
{
    if (myTrayIcon->isVisible())
    {
        myTrayIcon->showMessage("电压显示","已缩放至托盘",QSystemTrayIcon::Information,5000);

        hide();     //最小化
        event->ignore();
    }
    else
        event->accept();
}

void Widget::showErr(QString text)
{
    ui->status->setText(text);
    ui->value->setText("ERR");
}


void Widget::on_ChartClean_clicked()
{
    charts->initMSecBase(300);
}


Widget::~Widget()
{

    delete ui;
}




