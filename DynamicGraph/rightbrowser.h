#ifndef RIGHTBROWSER_H
#define RIGHTBROWSER_H

#include <QWidget>
#include <QTextBrowser>
#include <QLabel>
#include <QPushButton>

#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QAbstractScrollArea>
#include <QTextCursor>
#include <QFileInfo>
#include <QStringList>
#include <QDebug>

class RightBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit RightBrowser(QWidget *parent = nullptr);
    QLabel *l;
    QPushButton *b;

    QTextBrowser *tb;
    QTimer * timerTxt;


    int lastReadRowNums=0;//上次读到的文件行数，初始为0


signals:

public slots:
    void showFileContents();

};

#endif // RIGHTBROWSER_H
