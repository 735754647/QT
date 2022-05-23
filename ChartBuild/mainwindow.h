#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <map>
#include <cstdlib>
#include <QMap>
#include <QList>
#include <QLabel>
#include <QVBoxLayout>
#include <QMouseEvent>

#include "barchartsbuilder.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void CreateDate(unsigned int uiCnt);
    void ResetLabel();

private slots:
    void pushRand1();
    void pushRand2();
    void pushRand3();
    void pushRand4();


     void pushRand5();

    void pushClear();
    void sltTooltip(bool status, int index, QBarSet *barset);

private:
    std::vector<QLabel*>    m_vecToolTips;
    Ui::MainWindow          *ui;
    BarChartBuilder         *m_BarChart;


};

#endif // MAINWINDOW_H
