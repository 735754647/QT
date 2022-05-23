#pragma execution_character_set("utf-8")
#include "rightechart.h"

RightEChart::RightEChart(QWidget *parent) : QWidget(parent)
{
    //******chart begain*********

    var1Series = new QLineSeries();
    var2Series= new QLineSeries();
    var1Series->setName("var1");
    var2Series->setName("var2");

    chart = new QChart();

    //增加各变量的点
    chart->addSeries(var1Series);
    chart->addSeries(var2Series);


    chart->setTitle("DYChart");

    chart->createDefaultAxes();

    //默认坐标轴设置
//    chart->axisY()->setRange(0,10);
//    chart->axisX()->setRange(0,20);//y轴初始固定值
//    chart->axisX()->setTitleText("Accumulated Time Step");
//    chart->axisY()->setTitleText("Variable Value");

    //chart->axisX()->setMinorTickCount(4);

    //自定义x轴以及相关属性
    axisX=new QValueAxis;
    axisX->setRange(0,20);
    axisX->setTitleText("X");//X轴标题
    axisX->setGridLineVisible(true);//是否显示网格线
   // axisX->setMinorTickCount(4);//小刻度线数目
  //  axisX->setTickCount(5);//大刻度线数目
    axisX->setMinorGridLineVisible(false);
    chart->setAxisX(axisX,var1Series);
    chart->setAxisX(axisX,var2Series);



    //因为y轴是科学计数法，所以需要自定义y轴以及相关属性
    axisY=new QValueAxis;
    axisY->setRange(0,1);
    axisY->setLabelFormat("%E");//设置刻度的格式
    axisY->setTitleText("Y");//Y轴标题
    axisY->setGridLineVisible(true);//是否显示网格线
//    axisY->setMinorTickCount(4);//小刻度线数目
//    axisY->setMinorGridLineVisible(false);
    axisY->setTickCount(6);//大刻度线数目
    chart->setAxisY(axisY,0);
    chart->legend()->setVisible(true);//图例的隐藏->hide();

    //chart->setAnimationOptions(QChart::SeriesAnimations);//设置曲线呈动画显示

    //******chart end********

    //显示图标的view
    chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    vLayout=new QVBoxLayout;
    vLayout->addWidget(chartView);


    this->setLayout(vLayout);
    this->show();

    timerChart=new QTimer;


}

void RightEChart::drawFilePoints()
{
    QFile outFile(":/resultdata/result/data.txt");
    if(!outFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       qDebug()<<"canot open!";
    }
    QTextStream stream(&outFile);

    //每次读取一行每一行为一个QStringList，
    //第一列values[0]:step,
    //第二列values[1]:var1,
    //第三列values[2]:var2,

    //分别声明接受各列变量的QStringList
    QStringList stepStrArr,var1StrArr,var2StrArr;

    QStringList column;//如果声明到循环内程序崩掉！！！
    while(!stream.atEnd()){
        QString wholeLine=stream.readLine();
        qDebug()<<"wholeLine"<<wholeLine;
        //过滤掉文本中的#行，和“variables”行
        if (wholeLine.startsWith("#") ||wholeLine.startsWith("variables"))
            continue;
        //以“ ”为分隔符将每一行划分成多列
        column=wholeLine.split(" ",QString::SkipEmptyParts);
        stepStrArr.append(column.at(0));//接受column[0]的值
        var1StrArr.append(column.at(1));//接受column[1]的值
        var2StrArr.append(column.at(2));//接受column[2]的值

    }

    //将各变量对应的QStringList转换为int或float以便作为点的y值
    int stepInt=stepStrArr.at(lastDrawRowNums).toInt();
    int maxValueAxisX=stepInt;//声明递增的Y轴刻度
    float var1Float=var1StrArr.at(lastDrawRowNums).toFloat();
    float var2Float=var2StrArr.at(lastDrawRowNums).toFloat();


    if(maxValueAxisX>20){//当step大于20，设置为动态可变x轴
        chart->axisX()->setRange(0,maxValueAxisX);
    }

    var1Series->append(stepInt,var1Float);
    var2Series->append(stepInt,var2Float);
    lastDrawRowNums++;

    //杀掉定时器
    if(lastDrawRowNums>allSteps-1){//此处数目设置为文件的最大行数(即step)
        qDebug()<<"lastDrawRowNums:"<<lastDrawRowNums;
        qDebug()<<"stop timerChart!";
        timerChart->stop();
    }
}


