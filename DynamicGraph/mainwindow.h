#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "rightbrowser.h"
#include "rightechart.h"
#include <QPushButton>
#include <QMainWindow>
#include <QWidget>
#include <QToolButton>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QMainWindow>
#include <QChartView>
#include <QtCharts/QChart>
//#include <QtCharts>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QSplitter>

#include <QTextBrowser>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QVector>


class QLineEdit;
class QDialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



    //菜单栏
    QMenu *fileMenu;
    QAction *action_Open;
    QAction *action_Close;
    QMenu *toolMenu;

    QAction *action_Save;
    QAction *action_Load;
    QMenu *helpMenu;

    //中间区域
    QPushButton * runBtn;

    QWidget * widget;
    QTabWidget *tabWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *mainLayout;
    QDialog *dialog;

    RightBrowser *rightBrowser;
    RightEChart *rightEChart;

    int t=3000;//定时器触发间隔：毫秒

protected:


private slots:

    void startShowAndDrawTimer();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
