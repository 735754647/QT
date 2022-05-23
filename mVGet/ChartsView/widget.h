#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QResizeEvent>
#include <QTimer>
#include "ChartsView.h"
class widget : public QWidget
{
    Q_OBJECT
public:
    QTimer* TestTimer;          //时间定时器

    ChartsView *view;
    explicit widget(QWidget *parent = 0);


    void resizeEvent(QResizeEvent *event);
signals:

public slots:
    void TestOnTimeOut();

};

#endif // WIDGET_H
