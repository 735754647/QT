#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QTimer>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

    void initTrayIcon();
    void initmvGet();
    QTimer*  mvGetTimer;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void wheelEvent(QWheelEvent *event);

    void createChart(std::map<QString, std::list<int> > obj);
private:
    Ui::Widget *ui;

    QChart *m_chart;


    void onMvGetTimeOut();
    void dischart();
};
#endif // WIDGET_H
