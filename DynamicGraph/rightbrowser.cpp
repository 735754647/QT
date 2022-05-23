#pragma execution_character_set("utf-8")
#include "rightbrowser.h"
#include "mainwindow.h"
#include <QVBoxLayout>


RightBrowser::RightBrowser(QWidget *parent) : QWidget(parent)
{
    timerTxt=new QTimer;
    tb=new QTextBrowser;
    QVBoxLayout *vLayout=new QVBoxLayout;
    vLayout->addWidget(tb);

    this->setLayout(vLayout);
    this->show();

}

void RightBrowser::showFileContents()
{
    //读已经完全写好的结果文件，每隔3秒显示一行数据
    QStringList sl;
    //右下文本框读内容，显示
    QFile file(":/resultdata/result/data.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text))
        qDebug()<<"canot open!";
    
    
    QTextStream stream(&file);

    //初始时加上首行说明
    if(lastReadRowNums==0){
        qDebug()<<"初始lastReadRowNums:"<<lastReadRowNums;
        tb->append("------------------------------------------------------------------");
    }


    while(!stream.atEnd()){
        QString line=stream.readLine();
        if (line.startsWith("#") || line.startsWith("variables"))
            continue;
        sl.append("  "+line.trimmed());//trimmed():Returns a string that has whitespace removed from the start and the end.
    }

    int len=sl.size();
    tb->append(sl.at(lastReadRowNums++));
    qDebug()<<"lastReadRowNums"<<lastReadRowNums;

    //杀掉定时器
    if(lastReadRowNums>len-1){//此处数目设置为所读文件的最大行数
        qDebug()<<" stop timerTXT!";
        timerTxt->stop();
        }
    }
