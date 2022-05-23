#pragma execution_character_set("utf-8")
#include "widget.h"
#include "ui_widget.h"
#include <QtCharts>
#include <QtWidgets/QWidget>
#include <QMouseEvent>

QT_CHARTS_USE_NAMESPACE

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
       createChart("eins");

 //   m_chart = new QChart();
//    //创建1个条线数据
//      QBarSet *set0 = new QBarSet("数量");


//    *set0 << 158 << 685 << 458 << 260 << 354;    //向零食数据添加这4个月的销售数据


//    set0->setLabelColor(QColor(0,0,255));       //设置条形数据颜色


//    QBarSeries *series = new QBarSeries();
//    series->append(set0);
//    series->setVisible(true);
//    series->setLabelsVisible(true);

//    m_chart->setTheme(QChart::ChartThemeLight);//设置白色主题
//    m_chart->setDropShadowEnabled(true);//背景阴影
//    m_chart->addSeries(series);//添加系列到QChart上

//    m_chart->setTitleBrush(QBrush(QColor(0,0,255)));//设置标题Brush
//    m_chart->setTitleFont(QFont("微软雅黑"));//设置标题字体
//    m_chart->setTitle("数量统计图");

//    //创建X轴和Y轴
//    QBarCategoryAxis *axisX = new QBarCategoryAxis;
//    axisX->append("8:00-12:00");
//    axisX->append("13:00-16:00");
//    axisX->append("17:00-20:00");
//    axisX->append("20:00-22:00");
//    axisX->append("22:00-24:00");
//    axisX->setLabelsColor(QColor(7,28,96));

//    QValueAxis *axisY = new QValueAxis;
//    axisY->setRange(0,1000);   //改为setRange(0,1);则表示坐标为动态计算大小的
//    axisY->setTitleText("个数");
//    axisY->setLabelFormat("%d$");

//    m_chart->setAxisX(axisX,series);
//    m_chart->setAxisY(axisY,series);

//    //修改说明样式
//    m_chart->legend()->setVisible(true);
//    m_chart->legend()->setAlignment(Qt::AlignBottom);//底部对齐
//    m_chart->legend()->setBackgroundVisible(true);//设置背景是否可视
//    m_chart->legend()->setAutoFillBackground(true);//设置背景自动填充
//    m_chart->legend()->setColor(QColor(222,233,251));//设置颜色
//    m_chart->legend()->setLabelColor(QColor(0,100,255));//设置标签颜色
//    m_chart->legend()->setMaximumHeight(50);

//    QChartView *chartView = new QChartView(m_chart);
//    chartView->setRenderHint(QPainter::Antialiasing);

//    QVBoxLayout *pVLayout = new QVBoxLayout(this);
//    pVLayout->addWidget(chartView);

//    resize(960, 720);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::wheelEvent(QWheelEvent *event)
  {
      if (event->delta() > 0) {
          m_chart->zoom(1.1);
      } else {
          m_chart->zoom(10.0/11);
      }
}



void Widget::createChart(std::map<QString, std::list<int> > obj)
{
    QBarSeries *series = new QBarSeries();
    std::map<QString, std::list<int>>::iterator it = obj.begin();
    //将数据读入
    while (it != obj.end())
    {
        QString tit = it->first;
        QBarSet *set = new QBarSet(tit);
        std::list<int> vecnum = it->second;
        for (auto &a : vecnum)
        {
            *set << a;
        }
        set->setColor(QColor(qrand()%255, qrand()%255, qrand()%255, 128));
        series->append(set);
        it++;
    }
    int size = series->count();
    series->setVisible(true);
    series->setLabelsVisible(true);
    QBarCategoryAxis *axis = new QBarCategoryAxis;
    axis->append("January");
    axis->append("February");
    axis->append("March");
    axis->append("April");
    axis->setLabelsColor(QColor(qrand() % 255, qrand() % 255, qrand() % 255, 255));

    QValueAxis *axisy = new QValueAxis;
    axisy->setRange(0, 1000);
    axisy->setTitleText(tr("数量"));
    m_chart->addSeries(series);
    m_chart->setTitle(tr("谢谢大家观看我的博客"));
    m_chart->setTitleFont(QFont("微软雅黑"));
    m_chart->setAxisX(axis, series);
    m_chart->setAxisY(axisy, series);
    m_chart->legend()->setVisible(true);
}

void Widget::dischart()
{
    std::list<int> list0 = { 101,505,200,301 };
    std::list<int> list1 = { 200,100,59,601 };
    std::list<int> list2 = { 599,421,878,213 };
    std::list<int> list3 = { 15,50,708,988 };
    std::map<QString, std::list<int>> mapnum;
    mapnum.insert(std::pair<QString, std::list<int>>("apple", list0));
    mapnum.insert(std::pair<QString, std::list<int>>("banana", list1));
    mapnum.insert(std::pair<QString, std::list<int>>("watermelon", list2));
    mapnum.insert(std::pair<QString, std::list<int>>("orange", list3));
    createChart(mapnum);
    QChartView *view = new QChartView(m_chart);
    view->setRenderHint(QPainter::Antialiasing);

        QVBoxLayout *pVLayout = new QVBoxLayout(this);
        pVLayout->addWidget(view);

    //ui->mainlayout->addWidget(view);
}
