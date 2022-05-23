#ifndef WIDGET_H
#define WIDGET_H
#include <QSystemTrayIcon>
#include <QWidget>
#include <QTimer>
#include <QMenu>
#include "ChartsView.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

    QSystemTrayIcon  *myTrayIcon;       //右下角托盘
    QMenu *myMenu;
    QAction *quitAction;
    QTimer*  mvGetTimer;
    ChartsView *charts;


    void initmvGet();
    void initTrayIcon();

    void showValue(double value);
    void showErr(QString text);

    void closeEvent(QCloseEvent *event);
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void onMvGetTimeOut();

    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private slots:
    void on_ChartClean_clicked();



    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
