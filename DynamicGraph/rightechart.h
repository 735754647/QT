#ifndef RIGHTECHART_H
#define RIGHTECHART_H

#include <QWidget>
#include <QChartView>
//#include <QtCharts/QChart>
#include <QtCharts>
//#include <QtCharts/QLineSeries>
//#include <QtCharts/QSplineSeries>
//#include <QtCharts/QValueAxis>
#include <QVBoxLayout>

#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QAbstractScrollArea>
#include <QTextCursor>
#include <QFileInfo>
#include <QStringList>
#include <QDebug>


class RightEChart : public QWidget
{
    Q_OBJECT
public:
    explicit RightEChart(QWidget *parent = nullptr);

    QLineSeries *var1Series;
    QLineSeries *var2Series;


    QChart *chart;
    QChartView *chartView;
    QValueAxis *axisY;

    QVBoxLayout *vLayout;

    QTimer * timerChart;
    int allSteps=50;
    int lastReadSteps=1;//上次读到的跌代步数step，初始为1
    int lastDrawRowNums=0;

    QValueAxis *axisX;

signals:

public slots:
    void drawFilePoints();
};

#endif // RIGHTECHART_H
