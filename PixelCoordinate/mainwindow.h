#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>

class WImage;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnPre_clicked();

    void on_btnNext_clicked();

    void on_actionSetImgPath_triggered();

    void setPicLoc();

    void on_btnSave_clicked();

private:
    Ui::MainWindow *ui;
    QLabel* m_labelStatus;

private:
    void setBtnState();

};

#endif // MAINWINDOW_H
