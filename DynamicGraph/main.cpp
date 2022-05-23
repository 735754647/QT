#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTextCodec>
#include <QElapsedTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //创建主视图对象
    MainWindow w;

    //程序数据加载完毕后，显示主视图，并结束启动画面
    w.show();

    QFont font=a.font();
    font.setPointSize(12);
    a.setFont(font);




    return a.exec();
}
