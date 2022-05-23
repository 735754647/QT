#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_vecToolTips.clear();
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(pushRand1()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(pushRand2()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(pushRand3()));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(pushRand4()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(pushRand5()));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(pushClear()));

    m_BarChart = new BarChartBuilder();
    ui->widget->setLayout(m_BarChart->m_Layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushRand1()
{
    CreateDate(4);
}
void MainWindow::pushRand2()
{
    CreateDate(7);
}
void MainWindow::pushRand3()
{
    CreateDate(25);
}
void MainWindow::pushRand4()
{
    CreateDate(15);
}


void MainWindow::pushRand5()
{
    int value=ui->spinBox->value();
    CreateDate(value);
}

void MainWindow::pushClear()
{
    m_BarChart->ClearData();
}

//创建数据：demo获取指定随机数创建新的数据内容
void MainWindow::CreateDate(unsigned int uiCnt)
{
    std::map<QString, int> mapData;
    for(unsigned int i = 0; i < uiCnt; i++)
    {
        mapData[QString::number(i)] = rand();
    }
    m_BarChart->UpdateDate(mapData);

    ResetLabel();
}

//重置鼠标悬停时的标签对象，连接新柱状图的信号槽函数
void MainWindow::ResetLabel()
{
    connect(m_BarChart->m_Series, SIGNAL(hovered(bool,int,QBarSet*)), this, SLOT(sltTooltip(bool,int,QBarSet*)));
    for(unsigned int index = 0; index < m_vecToolTips.size(); index++)
    {
        delete m_vecToolTips[index];
    }
    m_vecToolTips.clear();
    for(unsigned int index = 0; index < m_BarChart->m_uiCnt; index++)
    {
        QLabel *label = nullptr;
        m_vecToolTips.push_back(label);
    }
}

//鼠标悬停时标签创建和显示
void MainWindow::sltTooltip(bool status, int index, QBarSet *barset)
{
    if(nullptr != m_BarChart->m_Series && nullptr != m_BarChart->m_Chartview)
    {
        QChart* pchart = m_BarChart->m_Chartview->chart();
        QLabel *m_tooltip = nullptr;

        if(nullptr != m_vecToolTips[index])
        {
            m_tooltip = m_vecToolTips[index];
        }
        else
        {
            m_tooltip = new QLabel(m_BarChart->m_Chartview);    //头文件中的定义 QLabel*   m_tooltip = nullptr;
            m_tooltip->setStyleSheet("background: rgba(240, 128, 128,185);color: rgb(248, 248, 255);"
                                     "border:0px groove gray;border-radius:10px;padding:2px 4px;"
                                     "border:2px groove gray;border-radius:10px;padding:2px 4px");
            m_tooltip->setVisible(false);
            m_vecToolTips[index] = m_tooltip;
        }

        if (status)
        {
            double val = barset->at(index);
            QPointF point(index, barset->at(index));
            QPointF pointLabel = pchart->mapToPosition(point);

            m_tooltip->setText(QString::number(val));
            m_tooltip->move(pointLabel.x(), pointLabel.y() - m_tooltip->height()*1.5);
            m_tooltip->show();
        }
        else
        {
            m_tooltip->hide();
        }
    }
}
