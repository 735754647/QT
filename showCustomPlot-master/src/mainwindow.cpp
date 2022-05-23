#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::pushData);
	
	
	customPlot = ui->widget; // 创建一个指针，方便使用，省去  "ui->"
	
    customPlot->addGraph();   //添加一条线

    customPlot->xAxis->setLabel("这里是X轴");   //XY轴的名字
	customPlot->yAxis->setLabel("这里是Y轴");  //
	
	customPlot->xAxis->setRange(MinX,MaxX);   //这里我们设置默认的轴值
	customPlot->yAxis->setRange(MinY,MaxY);

    //可以进行鼠标位置 放大缩小 拖拽  放大缩小坐标系！！！功能非常强大
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::pushData()
{
	double xNumber = ui->LineX->text().toInt();
	double yNumber = ui->LineY->text().toInt();
	
	
	if(xNumber > MaxX)
		{
			MaxX = xNumber;
		}
	if(xNumber < MinX)
		{
			MinX = xNumber;
		}
	if(yNumber > MaxY)
		{
			MaxY = yNumber;
		}
	if(yNumber < MinY)
		{
			MinY = yNumber;
		}
	x.push_back(xNumber);
	y.push_back(yNumber);
	customPlot->xAxis->setRange(MinX,MaxX);   //这里我们设置默认的轴值
	customPlot->yAxis->setRange(MinY,MaxY);
	customPlot->graph(0)->setData(x,y);
	customPlot->replot();
	qDebug()<<"X "<<x;
	qDebug()<<"Y "<<y;
}
