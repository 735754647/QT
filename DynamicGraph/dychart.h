#ifndef DYCHART_H
#define DYCHART_H

#include <QWidget>
#include <QChartView>
#include <QtCharts>
#include <QLineSeries>
#include <QSplineSeries>
#include <QSplitter>
#include <QWidget>

class DyChart
{
public:
    DyChart();

    //chart   曲线QSplineSeries
//    QSplineSeries *series;
//    QSplineSeries *denSeries;
//    QSplineSeries *uSeries;
//    QSplineSeries *vSeries;
//    QSplineSeries *wSeries;
//    QSplineSeries *tempSeries;

    //折线QLineSeries
    QLineSeries *series;
    QLineSeries *denSeries;
    QLineSeries *uSeries;
    QLineSeries *vSeries;
    QLineSeries *wSeries;
    QLineSeries *tempSeries;

    QChart *chart;
    QChartView *chartView;
    QWidget *widget;
};

#endif // DYCHART_H
