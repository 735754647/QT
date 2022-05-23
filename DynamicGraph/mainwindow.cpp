#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QAbstractScrollArea>
#include <QTextCursor>
#include <QFileInfo>
#include <QStringList>

#include <QProcess>
#include <iostream>
#include <sstream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    this->showFullScreen();//全屏
    //添加文件菜单
    fileMenu=ui->menuBar->addMenu(tr("文件(&F)"));
    //添加打开菜单
    action_Open=fileMenu->addAction(tr("打开(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    //添加关闭菜单
    action_Close=fileMenu->addAction(tr("关闭(&C)"));
    action_Close->setShortcut(QKeySequence("Ctrl+C"));

   //添加工具菜单
    toolMenu=ui->menuBar->addMenu(tr("工具(&T)"));

    //添加帮助菜单
    helpMenu=ui->menuBar->addMenu(tr("帮助(&H)"));



    //splitter 划分
    QSplitter *mainSplitter=new QSplitter(Qt::Horizontal,this);
    mainSplitter->setFrameStyle(QFrame::Panel|QFrame::Raised);
    QSplitter *leftSplitter=new QSplitter(Qt::Vertical,mainSplitter);
    QSplitter *rightSplitter=new QSplitter(Qt::Vertical,mainSplitter);


    //左布局按钮
     runBtn=new QPushButton(tr("开始画图"));
     leftSplitter->addWidget(runBtn);

    //文本显示+图显示==>同步
    //添加运行按钮启动定时show和画的的信号和槽
     connect(runBtn,SIGNAL(clicked()),this,SLOT(startShowAndDrawTimer()));

    QHBoxLayout *leftBtnLayout=new QHBoxLayout;
    leftBtnLayout->addWidget(runBtn);
    QWidget *leftBtnWidget=new QWidget;
    leftBtnWidget->setLayout(leftBtnLayout);
    leftSplitter->addWidget(leftBtnWidget);

    //右布局（垂直）：曲线图+文本显示框

    rightBrowser=new RightBrowser;
    rightEChart=new RightEChart;
    rightEChart->resize(1000,700);
    rightSplitter->addWidget(rightEChart);
    rightSplitter->addWidget(rightBrowser);

    mainLayout=new QHBoxLayout(mainSplitter);
    mainLayout->addWidget(mainSplitter);
    this->setLayout(mainLayout);
    this->setCentralWidget(mainSplitter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startShowAndDrawTimer(){
    qDebug()<<"startShowAndDrawTimer!";
    //定时器的另外一种方法QTimer
    //分别设置读文件、显示文件，动态画点的定时器
    connect(rightBrowser->timerTxt,&QTimer::timeout,rightBrowser,&RightBrowser::showFileContents);
    rightBrowser->timerTxt->start(t);

    connect(rightEChart->timerChart,&QTimer::timeout,rightEChart,&RightEChart::drawFilePoints);
    rightEChart->timerChart->start(t);

}
















